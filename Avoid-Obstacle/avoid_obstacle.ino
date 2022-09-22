#include <Servo.h>
#include <NewPing.h>

const int LF = 6;
const int LB = 7;
const int RF = 5;
const int RB = 4;

const int enA = 10;
const int enB = 11;

const int servoPin = 9;

#define trig_pin A1
#define echo_pin A2
#define maximum_distance 200

int distance = 100;

NewPing sonar(trig_pin, echo_pin, maximum_distance);
Servo servo_motor;

void setup() 
{
  pinMode(RF, OUTPUT);
  pinMode(LF, OUTPUT);
  pinMode(LB, OUTPUT);
  pinMode(RB, OUTPUT);

  pinMode(enA,OUTPUT);
  pinMode(enB,OUTPUT);

  servo_motor.attach(servoPin);
  Serial.begin(9600);

  servo_motor.write(90);
  delay(2000);
  distance = readDistance();
  delay(100);

  analogWrite(enA, 100);
  analogWrite(enB, 100);
}

void loop()
{

  int distanceRight = 0;
  int distanceLeft = 0;
  delay(50);

  if (distance <= 20) 
  {
    moveStop();
    delay(300);
    moveBackward();
    delay(400);
    moveStop();
    delay(300);
    distanceRight = lookRight();
    delay(300);
    distanceLeft = lookLeft();
    delay(300);

    if (distance >= distanceLeft)
    {
      turnRight();
      moveStop();
    }
    else
    {
      turnLeft();
      moveStop();
    }
  }
  else
  {
    moveForward();
  }
  distance = readDistance();
  Serial.println(distance);
}

int lookRight()
{
  servo_motor.write(10);
  delay(500);
  int distance = readDistance();
  delay(500);
  servo_motor.write(90);
  return distance;
}

int lookLeft()
{
  servo_motor.write(170);
  delay(500);
  int distance = readDistance();
  delay(500);
  servo_motor.write(90);
  return distance;
  delay(100);
}

int readDistance()
{
  delay(70);
  int cm = sonar.ping_cm();
  if (cm == 0)
  {
    cm = 250;
  }
  return cm;
}

void moveStop()
{
  digitalWrite(RF, LOW);
  digitalWrite(LF, LOW);
  digitalWrite(RB, LOW);
  digitalWrite(LB, LOW);
}

void moveForward()
{
    digitalWrite(LF, HIGH);
    digitalWrite(RF, HIGH);

    digitalWrite(LB, LOW);
    digitalWrite(RB, LOW);
}

void moveBackward()
{
  digitalWrite(LB, HIGH);
  digitalWrite(RB, HIGH);

  digitalWrite(LF, LOW);
  digitalWrite(RF, LOW);
}

void turnRight()
{
  digitalWrite(LF, HIGH);
  digitalWrite(RB, HIGH);

  digitalWrite(LB, LOW);
  digitalWrite(RF, LOW);

  delay(300);

  digitalWrite(LF, HIGH);
  digitalWrite(RF, HIGH);

  digitalWrite(LB, LOW);
  digitalWrite(RB, LOW);
}

void turnLeft()
{

  digitalWrite(LB, HIGH);
  digitalWrite(RF, HIGH);

  digitalWrite(LF, LOW);
  digitalWrite(RB, LOW);

  delay(300);

  digitalWrite(LF, HIGH);
  digitalWrite(RF, HIGH);

  digitalWrite(LB, LOW);
  digitalWrite(RB, LOW);
}

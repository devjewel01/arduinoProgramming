#include <SoftwareSerial.h>
#include <Servo.h>
#include <NewPing.h>
#include <MD_MAX72xx.h>
#include <SPI.h>
#include "MD_EyePair.h"
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);


#define HARDWARE_TYPE MD_MAX72XX::PAROLA_HW
#define MAX_DEVICES 10

#define CLK_PIN   12  // or SCK
#define DATA_PIN  11  // or MOSI
#define CS_PIN    10  // or SS
#define IR        30
#define Fire      31
#define Gas       32
#define LDR       33
#define Temp      34
#define Trigger   35
#define Echo      36
#define Buzzer    37
#define Light     38


NewPing sonar(Trigger, Echo, 200);

MD_MAX72XX M = MD_MAX72XX(HARDWARE_TYPE, CS_PIN, MAX_DEVICES);

#define MAX_EYE_PAIR (MAX_DEVICES/2)

MD_EyePair E[MAX_EYE_PAIR];

#define  DELAYTIME  500

String readvoice;

Servo servo[7];
int pin[8] = {0, 2, 3, 4, 5, 6, 7, 8};
int pos[8] = {0, 0, 90, 180, 30, 150, 90};
int highest[8] = {0, 180, 180, 180, 180, 180, 180, 180};
int now[8];

int angle;

int RF = 22;
int RB = 23;
int LF = 24;
int LB = 25;
int enA = 26;
int enB = 27;

void setup()
{
  Serial1.begin(9600);
  Serial.begin(9600);
  Serial.print("Robot is started");
  pinMode(RF, OUTPUT);
  pinMode(RB, OUTPUT);
  pinMode(LF, OUTPUT);
  pinMode(LB, OUTPUT);
  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);

  analogWrite(enA, 400);
  analogWrite(enB, 400);
  
  pinMode(IR, INPUT);
  pinMode(Fire, INPUT);
  pinMode(Gas, INPUT);
  pinMode(LDR, INPUT);
  pinMode(Buzzer, OUTPUT);
  pinMode(Light, OUTPUT);

  M.begin();

  // initialize the eye view
  for (uint8_t i = 0; i < MAX_EYE_PAIR; i++)
    E[i].begin(i * 2, &M, DELAYTIME);

  for (int i = 1; i < 8; i++)
  {
    servo[i].attach(pin[i]);
  }
  for (int i = 1; i < 8; i++)
  {
    servo[i].write(pos[i]);
    now[i] = pos[i];
  }

  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 3);
  lcd.print("Robot Spector");
}

int readDistance()
{
  int distance = sonar.ping_cm();
  if ( distance == 0)
    distance = 200;
  return distance;
}

void changeDegree(int n, int p)
{
  if (now[n] < p)
  {
    for ( ; now[n] < p; now[n]++)
    {
      servo[n].write(now[n]);
      delay(20);
    }
  }
  else
  {
    for ( ; now[n] > p; now[n]--)
    {
      servo[20].write(now[n]);
      delay(5);
    }
  }
}


void changeDegree2(int n, int m, int p, int q)
{
  if (now[n] < p)
  {
    for ( ; now[n] < p; now[n]++)
    {
      servo[n].write(now[n]);
      servo[m].write(map(now[n], 0, 180, 180, 0));
      delay(20);
    }
  }
  else
  {
    for ( ; now[n] > p; now[n]--)
    {
      servo[n].write(now[n]);
      servo[m].write(map(now[n], 0, 180, 180, 0));
      delay(20);
    }
  }

}

void Eye(int x)
{
  E[x].animate();
}

void take_position()
{
  digitalWrite (RF, LOW);
  digitalWrite (RB, LOW);
  digitalWrite (LF, LOW);
  digitalWrite (LB, LOW);
  changeDegree2(3, 4, pos[3], pos[4]);
  changeDegree2(5, 6, pos[5], pos[6]);
  changeDegree2(1, 2, pos[1], pos[2]);
}

void readSensor()
{
  if ( digitalRead(IR) == LOW || digitalRead(Fire) == LOW || digitalRead(Gas) == LOW)
  {
    digitalWrite(Buzzer, HIGH);
  }
  else
  {
    digitalWrite(Buzzer, LOW);
  }
  if ( digitalRead(LDR) == LOW)
  {
    digitalWrite(Light, HIGH);
  }
  else
  {
    digitalWrite(Light, LOW);
  }
}


void loop()
{
  Eye(0);
  while (Serial1.available())
  {
    delay(10);
    char c = Serial1.read();
    Serial.println(c);
    readvoice += c;
  }
  Serial.println("the command is : ");
  Serial.println(readvoice);
  Serial.println("Found the voice");
  delay(10);
  if (readvoice == "*normal position#" || readvoice == "*okay#" || readvoice == "*take position#" || readvoice == "*ok#")
  {
    take_position();
    Eye(0);
  }


  else if (readvoice == "*hand shake#")
  {
    Eye(1);
    changeDegree(2, 130);
    delay(2000);
    take_position();
  }
  else if (readvoice == "*tata#" || readvoice == "*hello#" ||  readvoice == "*hi#")
  {
    changeDegree(2, 180);
    changeDegree(6, 90);
    changeDegree(6, 70);
    changeDegree(6, 110);
    delay (3000);
    changeDegree(2, pos[1]);
  }
  else if (readvoice == "*left hand up#")
  {
    changeDegree(1, 180);
  }
  else if (readvoice == "*left hand down#")
  {
    changeDegree(1, pos[1]);
  }
  else if (readvoice == "*right hand up#")
  {
    changeDegree(2, 180);
  }
  else if (readvoice == "*right hand down#")
  {
    changeDegree(2, pos[2]);
  }
  else if (readvoice == "*move your hand#")
  {
    changeDegree2(1, 2, 180, 0);
    delay(2000);
    changeDegree2(1, 2, 0, 180);
    delay(1000);
    take_position();
  }
  else if (readvoice == "*raise your hand#" ||  readvoice == "*both hand up#" )
  {
    changeDegree2(1, 2, 180, 0);
    delay(2000);
    take_position();
  }
  else if (readvoice == "*hands up#")
  {
    changeDegree2(1, 2, 180, 0);
  }
  else if (readvoice == "*down your hand#" || readvoice == "*both hand down#")
  {
    take_position();
  }

  else if (readvoice == "move your head#" )
  {
    Eye(2);
    delay (100);
    changeDegree(7, 180);
    delay(2000);
    changeDegree(7, 0);
    delay(2000);
    changeDegree(7, 90);
  }
  else if (readvoice == "*head turn left#" || readvoice == "*turn left#")
  {
    changeDegree(7, 180);
    delay(1000);
    changeDegree(7, 90);
  }
  else if (readvoice == "*head turn right#" || readvoice == "*turn right#")
  {
    changeDegree(7, 0);
    delay(1000);
    changeDegree(7, 90);
  }
  else if (readvoice == "*go#" || readvoice == "*go forward#")
  {
    Serial.println("go forward function");
    Eye(3);
    digitalWrite(RF, HIGH);
    digitalWrite(LF, HIGH);
    digitalWrite(RB, LOW);
    digitalWrite(LB, LOW);
    delay(2000);
    take_position();

  }

  else if (readvoice == "*go and go#" || readvoice == "*go forward long#")
  {

    digitalWrite(RF, HIGH);
    digitalWrite(LF, HIGH);
    digitalWrite(RB, LOW);
    digitalWrite(LB, LOW);
  }

  else if (readvoice == "*back#" || readvoice == "*go back#")
  {
    digitalWrite(RF, LOW);
    digitalWrite(LF, LOW);
    digitalWrite(RB, HIGH);
    digitalWrite(LB, HIGH);
    delay(2000);
    take_position();
  }
  else if (readvoice == "*back and back#" || readvoice == "*go back long#")
  {
    digitalWrite(RF, LOW);
    digitalWrite(LF, LOW);
    digitalWrite(RB, HIGH);
    digitalWrite(LB, HIGH);
  }
  else if (readvoice == "*left#")
  {
    digitalWrite (RF, HIGH);
    digitalWrite (RB, LOW);
    digitalWrite (LF, LOW);
    digitalWrite (LB, LOW);
    delay (2000);
    take_position();
  }
  else if ( readvoice == "*right#")
  {
    digitalWrite (RF, LOW);
    digitalWrite (RB, LOW);
    digitalWrite (LF, HIGH);
    digitalWrite (LB, LOW);
    delay (2000);
    take_position();
  }

  else if (readvoice == "*stop#" )
  {
    digitalWrite (LF, LOW);
    digitalWrite (LB, LOW);
    digitalWrite (RF, LOW);
    digitalWrite (RB, LOW);
    delay(100);
  }
  else if (readvoice == "*circle#")
  {
    digitalWrite (RF, HIGH);
    digitalWrite (RB, LOW);
    digitalWrite (LF, LOW);
    digitalWrite (LB, LOW);
    delay(5000);
  }
  else if (readvoice == "*dance your eye#")
  {
    for (int i = 0; i < 5; i++)
    {
      Eye(i);
      delay(500);
    }
  }
  readvoice = "";

  readSensor();

  if (readDistance() < 10)
  {
    digitalWrite (LF, LOW);
    digitalWrite (LB, LOW);
    digitalWrite (RF, LOW);
    digitalWrite (RB, LOW);
  }
}

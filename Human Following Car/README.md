```C++
#include <NewPing.h>

int LF = 6;
int LB = 7;
int RF = 5;
int RB = 4;

int leftIR = A1;
int rightIR = A2;
int trigger = A3;
int echo = A4;

NewPing sonar(trigger, echo, 200);



void setup()
{
  Serial.begin(9600);
  Serial.println("Car is Ready");
  
  pinMode(LF, OUTPUT);
  pinMode(RF, OUTPUT);
  pinMode(LB, OUTPUT);
  pinMode(RB, OUTPUT);

  pinMode(leftIR, INPUT);
  pinMode(rightIR, INPUT);
  pinMode(led, OUTPUT);
}

void loop()
{
  int d = distance();
  int l = digitalRead(leftIR);
  int r = digitalWrite(rightIR);
  if( l==1 && r==1 &&  d>=10 && d<=30)
      Forward();
  else if(l==1 && r==1 && d<=5)
      Backword();
  else if(l==1 && r==0)
      Right();
  else if(l==0 && r==1)
      Left();
  else
      Stop();
}




void Forward()
{
  Serial.println("Go forward");
  digitalWrite(LF, HIGH);
  digitalWrite(RF, HIGH);
  digitalWrite(RB, LOW);
  digitalWrite(LB, LOW);
}

void Backward()
{
  Serial.println("go back");
  digitalWrite(LB, HIGH);
  digitalWrite(RB, HIGH);
  digitalWrite(RF, LOW);
  digitalWrite(LF, LOW);
}

void Right()
{
  Serial.println("Go right");
  digitalWrite(LF, HIGH);
  digitalWrite(RF, LOW);
  digitalWrite(RB, HIGH);
  digitalWrite(LB, LOW);
}

void Left()
{
  Serial.println("Go left");
  digitalWrite(LF, LOW);
  digitalWrite(RF, HIGH);
  digitalWrite(RB, LOW);
  digitalWrite(LB, HIGH);
}

void Stop()
{
  Serial.println("Stop car");
  digitalWrite(LF, LOW);
  digitalWrite(RF, LOW);
  digitalWrite(RB, LOW);
  digitalWrite(LB, LOW);
}

int distance()
{
  int cm = sonar.ping_cm();
  if (cm == 0)
  {
    cm = 250;
  }
  return cm;
}
```

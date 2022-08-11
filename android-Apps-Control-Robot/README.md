**Andriod Apps control Robot**
```cpp
#include<SoftwareSerial.h>

int LF = 6;
int LB = 7;
int RF = 5;
int RB = 4;

void setup()
{
  Serial.begin(9600);
  Serial.println("Car is Ready");
  pinMode(LF, OUTPUT);
  pinMode(RF, OUTPUT);
  pinMode(LB, OUTPUT);
  pinMode(RB, OUTPUT);
}

void loop()
{
  if (Serial.available())
  {
    char a = Serial.read();
    Serial.print("The command is ");
    Serial.println(a);
    if (a == 'F')
      Forward();
    if (a == 'B')
      Backward();
    if (a == 'R')
      Right();
    if (a == 'L')
      Left();
    if (a == 'S')
      Stop();
  }
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
```

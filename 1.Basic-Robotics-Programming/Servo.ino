#include<Servo.h> 

Servo a;

void setup()
{
    a.attach(9);
}
void loop()
{
  a.write(0);
  delay(1000);
  a.write(180);
  delay(1000);
}

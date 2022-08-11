#include<Servo.h> 

Servo a;

void setup()
{
    Serial.begin(9600);
    Serial.println("Enter angle between 1 to 180");
    a.attach(9);
}
void loop()
{
  if(Serial.available())
  {
     int deg = Serial.parseInt();
     if(deg > 0)
     {
        a.write(deg);
        Serial.print("Now servo in ");
        Serial.println(deg);
        Serial.println("Enter angle between 1 to 180");
     }
  }
}

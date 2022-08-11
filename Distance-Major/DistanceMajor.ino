#include <Wire.h>
#include <LiquidCrystal_I2C.h>

#define trigPin 12
#define echoPin 8
#define Buzzer 13

LiquidCrystal_I2C lcd(0x27,16,2);

void setup ()
{
  Serial.begin(9600);
  Serial.println("Code started");
  pinMode(trigPin, OUTPUT);  
  pinMode(echoPin, INPUT);   
  pinMode(Buzzer, OUTPUT);  

  lcd.init();
  lcd.backlight();
}

void loop()
{
  int duration, distance;
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(100);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance =(duration/2) / 29.1;

  delay(100);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Distance ");
  lcd.print(distance);
  lcd.print("cm");
  
  if (distance >=10)
  { 
    digitalWrite(Buzzer, LOW);
  }
  else
  {
    digitalWrite(Buzzer, HIGH);
  }
}

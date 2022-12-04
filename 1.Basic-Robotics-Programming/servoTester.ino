#include<Servo.h>
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,16,2);
Servo sm;
int deg, pDeg=90;



void setup() 
{
  Serial.begin(9600); 
  sm.attach(9);
  sm.write(90);

  lcd.init();                      
  lcd.backlight();
  lcd.setCursor(0,0);
  lcd.print("Quanta Robotics");
  lcd.setCursor(0,1);
  lcd.print("Servo angle 90");
}

void loop() 
{
  int v = analogRead(A0);
  deg = map(v, 0, 1023, 0, 180);
  
  if(deg != pDeg)
  {
    sm.write(deg);
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Quanta Robotics");
    
    lcd.setCursor(0,1);
    lcd.print("Servo angle ");
    lcd.print(deg);
    
  }
  delay(100);
}

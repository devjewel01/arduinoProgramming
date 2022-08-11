#include <NewPing.h>

int trigger = 12;  
int echo = 11;
int MAX_DISTANCE = 200; 

NewPing sonar(trigger, echo, MAX_DISTANCE);

void setup() 
{
  Serial.begin(9600); 
}

void loop() 
{
  delay(50);                     
  Serial.print("Ping: ");
  Serial.print(sonar.ping_cm()); 
  Serial.println("cm");
}
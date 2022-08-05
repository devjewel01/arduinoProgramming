#include <NewPing.h>
#include Servo.h>

int trigger =   12;
int echo =   11 ;
int MAX_DISTANCE = 200 ;

NewPing sonar(trigger, echo, MAX_DISTANCE);
Servo dakna;

void setup() 
{
   dakna.attach(2);
   dakna.write(0);
}

void loop() 
{                 
  int d = sonar.ping_cm();
  if(d == 0)
    d = 200;
  if( d <= 30 )
  {
    dakna.write(180);
    delay(3000);
  }
  else
  {
    dakna.write(0);
  }
}

#include <teslon.h>
teslon robot;

#define LeftLeg 2
#define RightLeg 3
#define LeftFoot 4
#define RightFoot 5
#define touch 6
#define Buzzer  7
#define Trigger A0
#define Echo A1
#define red 10
#define green 11
#define green1 13
#define blue 12
#define tx   8
#define rx   9

long ultrasonic()
{
  long duration, distance;
  digitalWrite(Trigger, LOW);
  delayMicroseconds(2);
  digitalWrite(Trigger, HIGH);
  delayMicroseconds(10);
  digitalWrite(Trigger, LOW);
  duration = pulseIn(Echo, HIGH);
  distance = duration / 58;
  return distance;
}

void setup()
{
  robot.init(LeftLeg, RightLeg, LeftFoot, RightFoot, true, Buzzer);
  robot.home();
  delay(50);
  pinMode(red, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(blue, OUTPUT);
  pinMode(Trigger, OUTPUT);
  pinMode(Echo, INPUT);
  pinMode(touch, INPUT);
  Serial.begin(9600);
  Serial.println("Robot is ready");
}

void Green()
{
  digitalWrite(green, LOW);
  digitalWrite(blue, HIGH);
  digitalWrite(red, HIGH);
}
void Red()
{
  digitalWrite(red, LOW);
  digitalWrite(green, HIGH);
  digitalWrite(blue, HIGH);
}
void Blue()
{
  digitalWrite(blue, LOW);
  digitalWrite(green, HIGH);
  digitalWrite(red, HIGH);
}




int count = 0;
void loop()
{
  robot.home();
  if (digitalRead(touch) == HIGH)
  {
    count = (count+1)%16;
    
    if (count == 1)
    {
      Serial.println("Walk Forward");
      Green();
      robot.walk(4, 1000, 1);
    }

    else if (count == 2)
    {
      Serial.println("Walk Back");
      Red();
      robot.walk(4, 1000, -1);

    }

    else if (count == 13)
    {
      Blue();
      Serial.println("Turn Left");
      robot.turn(4, 1000, 1);
      
      delay(100);
      
      Serial.println("Turn Right");
      robot.turn(4, 1000, -1);
    }


    else if (count == 4)
    {
      Serial.println("tone and bendTones");
      robot._tone(20, 3, 1);
      robot.bendTones (100, 200, 1.04, 10, 10);
    }

    else if (count == 5)
    {
      Serial.println("bend ");
      robot.bend (2, 500, 1);
      
      delay(100);
      
      robot.bend (2, 2000, -1);
    }

    else if (count == 6)
    {
      Serial.println("moon walker");
      robot.moonwalker(4, 1000, 25, 1);
      
      delay(100);
      
      robot.moonwalker(4, 1000, 25, -1);
    }

    else if (count == 7)
    {
      Serial.println("crusaito");
      robot.crusaito(4, 1000, 20, 1);

      delay(100);
      
      robot.crusaito(4, 1000, 20, -1);
    }

    else if (count == 8)
    {
      Serial.println("flapping");
      robot.flapping(4, 1000, 20, 1);

      delay(100);
      robot.home();
      
      robot.flapping(4, 1000, 20, -1);
    }

    else if (count == 9)
    {
      
      Serial.println("swing");
      robot.swing(4, 1000, 20);
     
    }

    else if (count == 10)
    {
      Serial.println("tiptoeSwing");
      robot.tiptoeSwing(4, 1000, 20);
    }

    else if( count == 11)
    {
      Serial.println("jitter");
      robot.jitter(4, 1000, 20);
    }

    else  if (count == 12)
    {
      Serial.println("updown");
      robot.updown(4, 1500, 20);
    }

    else if (count == 3)
    {
      Serial.println("ascendingTurn");
      robot.ascendingTurn(4, 1000, 50);
    }

    else if (count == 14)
    {
      Serial.println("shakeLeg");
      robot.shakeLeg (1, 1500, 1);
      
      delay(100);
      robot.home();
      

      robot.shakeLeg (1, 1500, -1);
    }

    else if (count == 15)
    {
      robot.sing(S_cuddly);
      robot.sing(S_OhOoh);
      robot.sing(S_OhOoh2);
      robot.sing(S_surprise);
      robot.sing(S_buttonPushed);
      robot.sing(S_mode1);
      robot.sing(S_mode2);
      robot.sing(S_mode3);
      robot.sing(S_sleeping);
      robot.sing(S_fart1);
      robot.sing(S_fart2);
      robot.sing(S_fart3);
      robot.sing(S_happy);
      robot.sing(S_happy_short);
      robot.sing(S_superHappy);
      robot.sing(S_sad);
      robot.sing(S_confused);
      robot.sing(S_disconnection);
    }
    delay(200);
    robot.home();
    delay(50);

  }

}

## Arduino Programming Guideline 

<br>

**Blinking a LED**
```c
void setup() 
{
  pinMode(13, OUTPUT);
}
void loop() 
{
    digitalWrite(13, HIGH);
    delay(1000);
    digitalWrite(13, LOW);
    delay(1000);
}
```

<br>

**Blinking two LED**
```arduino
int led1 = 13;
int led2 = 12;

void setup() 
{
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
}

void loop() 
{
    digitalWrite(led1, HIGH);
    digitalWrite(led2, LOW);
    delay(1000);
    digitalWrite(led1, LOW);
    digitalWrite(led2, HIGH);
    delay(1000);
}
``` 

<br>

**Detect a object using IR sensor**
```arduino
int ir = 2;
int led = 13;

void setup() 
{
  pinMode(ir, INPUT);
  pinMode(led, OUTPUT);
}
void loop() 
{
    if(digitalRead(ir) == LOW)
    {
      digitalWrite(led, HIGH);
    }
    else
    {
      digitalWrite(led, LOW);
    }
}
``` 

**Two IR sensor detect object parallely**
```arduino
int ir1 = 2;
int led1 = 13;

int ir2 = 3;
int led2 = 12;

void setup() 
{
  pinMode(ir1, INPUT);
  pinMode(ir2, INPUT);

  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
}
void loop() 
{
    if(digitalRead(ir1) == LOW)
    {
      digitalWrite(led1, HIGH);
    }
    else
    {
      digitalWrite(led1, LOW);
    }

    if(digitalRead(ir2) == LOW)
    {
      digitalWrite(led2, HIGH);
    }
    else
    {
      digitalWrite(led2, LOW);
    }
}
```

<br>

**Major Distance using Ultrasonic with NewPing Library**
```arduino
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
```

<br>

**Ultrasonic** 
```arduino
#define trigPin 12
#define echoPin 8
#define Buzzer 13


void setup ()
{
  Serial.begin(9600);
  Serial.println("Code started");
  pinMode(trigPin, OUTPUT);  
  pinMode(echoPin, INPUT);   
  pinMode(Buzzer, OUTPUT);  
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
  Serial.print("Distance : ");
  Serial.println(distance);
}
```

<br>

**Move a servo**
```arduino
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
```

<br>

**Hello World with Serial Monitor**
```arduino
void setup()
{
  Serial.begin(9600);
  Serial.print("Hello World");
}
void loop()
{
  
}
```

<br>

**Control LED with Serial Monitor**
```arduino
int led = 13;
void setup()
{
  Serial.begin(9600);
  pinMode(led, OUTPUT);
}
void loop()
{
  if(Serial.available())
  {
    String cmd = Serial.readString();
    if( cmd == "on")
       digitalWrite(led, HIGH);
    if (cmd == "off")
       digitalWrite(led, LOW);
  }
}
```

<br>

**Control Servo motor using Serial Monitor**
```arduino
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
```

<br>


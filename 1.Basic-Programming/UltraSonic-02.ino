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

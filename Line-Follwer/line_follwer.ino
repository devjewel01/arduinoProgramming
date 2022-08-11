const int RF = 8;
const int RB = 9;
const int LF = 10;
const int LB = 11;

const int enA = 6;
const int enB = 7;
const int lir = A0;
const int rir = A1;

void setup()
{
  Serial.begin(9600);
  pinMode(RF, OUTPUT);
  pinMode(RB, OUTPUT);
  pinMode(LF, OUTPUT);
  pinMode(LB, OUTPUT);
  pinMode(enA,OUTPUT);
  pinMode(enB,OUTPUT);
  pinMode(A0, INPUT); 
  pinMode(A1, INPUT); 
}
void loop()
{
  int LEFT_SENSOR = digitalRead(lir);
  int RIGHT_SENSOR = digitalRead(rir);
  
  
  if (RIGHT_SENSOR == 0 && LEFT_SENSOR == 0)
  {
    forward();
  }
  else if (RIGHT_SENSOR == 1 && LEFT_SENSOR == 0)
  {
    right(); 
  }
  else if (RIGHT_SENSOR == 0 && LEFT_SENSOR == 1)
  {
    left(); 
  }
  else if (RIGHT_SENSOR == 1 && LEFT_SENSOR == 1)
  {
    Stop(); 
  }
}

void forward()
{
  digitalWrite(RF, HIGH);
  digitalWrite(RB, LOW);
  digitalWrite(LF, HIGH);
  digitalWrite(LB, LOW);
  analogWrite(enA, 130);
  analogWrite(enB, 130);

}
void backward()
{
  digitalWrite(RF, LOW);
  digitalWrite(RB, HIGH);
  digitalWrite(LF, LOW);
  digitalWrite(LB, HIGH);
  analogWrite(enA, 150);
  analogWrite(enB, 150);
}
void right()
{
  digitalWrite(RF, LOW);
  digitalWrite(RB, HIGH);
  digitalWrite(LF, HIGH);
  digitalWrite(LB, LOW);
  analogWrite(enA, 200);
  analogWrite(enB, 200);
}
void left()
{
  digitalWrite(RF, HIGH);
  digitalWrite(RB, LOW);
  digitalWrite(LF, LOW);
  digitalWrite(LB, HIGH);
  analogWrite(enA, 200);
  analogWrite(enB, 200);
}
void Stop()
{
  digitalWrite(RF, LOW);
  digitalWrite(RB, LOW);
  digitalWrite(LF, LOW);
  digitalWrite(LB, LOW);
}

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
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

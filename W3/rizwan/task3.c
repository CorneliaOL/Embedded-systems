



void setup()
{
	int voltage = 0;
  	Serial.begin(9600);
  	pinMode(A0, INPUT);

}

void loop()
{
  //calcius = map(((analogRead(A0)-20) * 3.04), 0, 1023, -40, 125);

    voltage = analogRead(A0);

    Serial.println(voltage);

}
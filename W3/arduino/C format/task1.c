// (C) Lucas Holter, Cornelia Olofsson, Rizwan Rafiq, group: 18 (2024)
// Work package 3
// Exercise 1
// Submission code: 655738


//constant ins for pins and period of time, and state that will get used to check if button is pressed or not
const int buttonPressed = 2, led1 = 3, led2 = 4, period = 1000;
int state = 0, LED1state=0; // integers that will get used in digitalWrite

void setup()
{
  pinMode(buttonPressed, INPUT);//Push Button as input
  pinMode(led1, OUTPUT);//Led as output
  pinMode(led2, OUTPUT);//Led as output
  Serial.begin(9600);
}
void loop()
{
    digitalWrite(led2, HIGH); // light led 2
	delay(period); //delay to get led2 to blink
  if (digitalRead(buttonPressed) == HIGH) { //check if button is pressed
    LED1state=1; // if so, set ledstate to 1, indicating it will ligt up
  }
  if (digitalRead(buttonPressed) == LOW) {   // check if button is not pressed 
    LED1state=0; //if so, set ledstate to 0 indicating it should not be light up
  }
    
   digitalWrite(led1, LED1state); //digitalwrite the value to led1, 1 = HIGH, 0 = LOW
    digitalWrite(led2, LOW); // Turn off led2 since it has been on for 1 sec (or what period is set to)
  delay(period); // delay to blink


}

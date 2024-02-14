/* 	
	Program to control two LEDs , 
	one direct & another with push button
    Tinkercad (Schematic & Code)

*/

#define LED_FIRST_PIN	13		// pin for first LED
#define LED_SECOND_PIN	11		// pin for second LED
#define PIN2			2		// pin for checking button status
#define DURATION		1000	// time in milliseconds

int d=0;   // variable initialization to hold button status

void setup(){
  	
	pinMode(LED_FIRST_PIN, OUTPUT);// declare pin-13 as output pin
  pinMode(LED_SECOND_PIN, OUTPUT);// declare pin-13 as output pin
  pinMode(PIN2,INPUT); // declare pin-2 as input pin

}


void   loop(){
  
  digitalWrite(LED_FIRST_PIN, HIGH);
  delay(DURATION);
  digitalWrite(LED_FIRST_PIN, LOW);
  delay(DURATION);
  
  	d=digitalRead(PIN2);
	  if(d==0){					// check if button is pushed
      digitalWrite(LED_SECOND_PIN,HIGH);	// turn LED On 
    } else {
      digitalWrite(LED_SECOND_PIN,LOW);}	// otherwise turn LED off
 
}
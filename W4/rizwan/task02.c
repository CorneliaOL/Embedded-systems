
// (C) Lucas Holter, Cornelia Olofsson, Rizwan Rafiq, group: 18 (2024)
// Work package 4
// Exercise 2
// Submission code: ??????



/* Code to design Second Clock by using Timer interrupts */

#include <Servo.h>

Servo myservo;
int iDegrees = 0; 
unsigned long ticks = 0; // Count ISR calls

void setup()
{
  
  // Start serial communication at 9600 bps
  Serial.begin(9600);
  // Wait for serial port to connect. Needed for native USB port only
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }

  // Print pin information
  Serial.println("______________________________________________________");
  Serial.println("Program name: Second clock ticker by using servo motor");
  Serial.println("Pins used: A0 , Ground , Power");
  Serial.println("Servo attached to pin A0");

  cli();

TCCR2A = 0;
TCCR2B = 0;

TCCR2A |= (1 << WGM21);

TCCR2B |= (1 << CS22) | (1 << CS21) | (1 << CS20); // Set prescaler to 1024

OCR2A = 255;

TIMSK2 |= (1 << OCIE2A);

sei();

  /* put code here to read once */ 

  //servo_A0.attach(A0, 0, 360);

myservo.attach(9);
myservo.write(0);


}

void loop()
{
  
  //servo_A0.write(iDegrees++);

}


ISR(TIMER2_COMPA_vect) {

  ticks++; // Increment tick count
  if (ticks >= 61) { // Approximately 1 second; adjust this value as needed for accuracy
    ticks = 0; // Reset tick count
    iDegrees = (iDegrees + 6) % 180; // Decrement degrees to move clockwise
    
    myservo.write(iDegrees);
  }

 


}

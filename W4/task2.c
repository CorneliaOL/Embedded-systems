// (C) Lucas Holter, Cornelia Olofsson, Rizwan Rafiq, group: 18 (2024)
// Work package 4
// Exercise 2
// Submission code: ??????

//Import statement
#include <Servo.h>

Servo servo_A0; //Declare variable to hold servo motor controll
int iDegrees = 180; //Set start angle for motor controll
int count = 0; //Declare variable count which will be used to controll how often the servo is being turned
bool flag = 0; //Declare flag which will "notify" when the right amount of time has passed
int sec = 0; //Declare int sec that will hold seconds to print

//Setup function
void setup() {
  Serial.begin(9600);
  servo_A0.attach(A0); //Start control of the servo motor
  servo_A0.write(iDegrees); //Turn the motor to the value of iDegrees, I.E. 180 degrees
  
  cli(); //Stop any interupt from happening between this and sei()
  TCCR2A = 0; //Reset all options converning timer2
  TCCR2B = 0; //Reset all options converning timer2
  TCCR2B |= 0b00000111; //Set prescalar to 1024

  TIMSK2 |= 0b00000010; //Enable compare registry A for timer 2
  OCR2A = 255; //Set at what value for TCNT2 the interupt should be triggered
  TCNT2 = 0; //Reset counter
  sei(); //End the block where no interupts can happen
}

//Loop function
void loop(){

  //When the interupt happens we set flag to 1 to notify that we now should execute this code
  if (flag==1){
    //If the interupt has happened 61 times, I.E. a second has passed since the last interupt. This was doen since OCR2A is only 8 bits, and can thus not
    //trigger the interupt every second
    // The calculations for the number is (1/(6e6))*1024*255*COUNT = 1(second) which gives roughly 61.27 ≈ 61
    if(count == 61){
      iDegrees = iDegrees - 6; //Change the value of iDegrees to be itself - 6, this corresponds to a one 60th rotation in the clockwise direction
      servo_A0.write(iDegrees); //Turn the motor
      count = 0; //Reset the count variable to reset timer to 1 second
      sec++;
      Serial.println(sec);
    }
    //If count is not 61, I.E. a second has not passed
    else{
      count++; //Increment counter 
    }
    flag = 0; //Reset the flag that says that the timer has been triggered
  }

}

//Interupt service routine for timer 2, OCR2A
ISR(TIMER2_COMPA_vect) {
  flag = 1; //Set flag to 1, indicating the interupt has happened
  TCNT2 = 0; //Reset the counter
}

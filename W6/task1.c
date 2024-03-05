// (C) Lucas Holter, Cornelia Olofsson, Rizwan Rafiq, group: 18 (2024)
// Work package 6 - smartcar shield
// Exercise 1
// Submission code: z4z6rd

#include <Smartcar.h>


//import and initialize library objects, such as motors car and differential control
ArduinoRuntime arduinoRuntime;
BrushedMotor leftMotor(arduinoRuntime, smartcarlib::pins::v2::leftMotorPins); //define leftMotor
BrushedMotor rightMotor(arduinoRuntime, smartcarlib::pins::v2::rightMotorPins); //define rightmotor
DifferentialControl control(leftMotor, rightMotor); // define control that uses the left and right motor
SimpleCar car(control); // define a car that uses the control

void setup() {

  Serial.begin(115200); //begin serial
  car.setSpeed(30); //set car speed to 30% of full speed
}

void loop() {
  delay(2000); //delay to allow the car to run straight
  turnRight(); //turn the car to the right
  delay(1920);//delay to continue to turn right
  straighten(); // straighten the path so the car runs in a straight line
}

void straighten(){
  car.setAngle(0); // set angle to 0 to let all motors spin at the same velocity
}

void turnRight(){
    car.setAngle(80); // set the angle to 80 degrees, so that it turns to the tight
}

//this method is not used, but keept intact to demonstrate the difference between turning right and left (right - negative angle, right - positive angle)
void turnLeft(){
  car.setAngle(-80); // set the angle to -80 degrees, so that it turns to the left
}
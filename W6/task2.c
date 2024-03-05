// (C) Lucas Holter, Cornelia Olofsson, Rizwan Rafiq, group: 18 (2024)
// Work package 6 - smartcar shield
// Exercise 2
// Submission code: z4z6rd

//Import statement
#include <Smartcar.h>

#define buzzerPin 19 //Defines which pin the buzzer is connected to
#define LED1 23 //Defines which pin the first LED is connected to
#define LED2 33 //Defines which pin the second LED is connected to
#define LED3 32 //Defines which pin the third LED is connected to
#define LED4 17 //Defines which pin the fourth LED is connected to

//Set up car controlls
ArduinoRuntime arduinoRuntime;
BrushedMotor leftMotor(arduinoRuntime, smartcarlib::pins::v2::leftMotorPins);
BrushedMotor rightMotor(arduinoRuntime, smartcarlib::pins::v2::rightMotorPins);
DifferentialControl control(leftMotor, rightMotor);
SimpleCar car(control);
//To here

bool lightsOn = false; //Flag used to blink lights when car is too close to obstacle

SR04 front(arduinoRuntime, 5, 18, 40); //Declare ultrasound sensor
unsigned long curTime; //Variable used to store the time since program began
unsigned long prevTime; //Variable used to store last time the logic loop was triggered
unsigned int interval = 500; //Time between sensor readings
int currSpeed = -30; //Current speed of the car

void setup() {
  Serial.begin(115200); //Begin serial
  car.setSpeed(currSpeed); //Start moving the car

  pinMode(LED1, OUTPUT); //Set pin connected to LED1 to output
  pinMode(LED2, OUTPUT); //Set pin connected to LED2 to output
  pinMode(LED3, OUTPUT); //Set pin connected to LED3 to output
  pinMode(LED4, OUTPUT); //Set pin connected to LED4 to output

  ledcSetup(0, 1000, 8); // Channel 0, 2000 Hz frequency, 8-bit resolution
  ledcAttachPin(buzzerPin, 0); //Attach the pin connected to buzzer to channel 0.
  
}

void loop() {
  // put your main code here, to run repeatedly: 
  curTime = millis(); //Set current time to amount of miliseconds since program execution began
  //If the time since last entrance of the if statement is greater than or equal to interval
  if(curTime-prevTime >= interval){
    prevTime = curTime; //Set prevTime to curTime

    float dist = front.getDistance(); //Get the distance the ultrasound sensor is detecting
    //If the reading from ultrasound sensor is less than 50 but not 0 (0 is default value when nothin is detected).
    if((dist < 50) && (dist != 0)){
      setBuzz(dist); //Set the buzzer tone according to distance
      setLights(dist); //Set the led lights according to distance
      currSpeed = map(dist, 10, 40, 0, -30); //map car speed to ultrasound distance
      car.setSpeed(currSpeed); //Set the new speed to the mapped value
    }
    //If the ultrasound detector is not detecting any obstacle
    if(dist == 0){
      ledcWrite(0, 0); //Turn off the buzzer
      car.setSpeed(-30); //Move the car
      digitalWrite(LED1, LOW); //Turn of LED1
      digitalWrite(LED2, LOW); //Turn of LED2
      digitalWrite(LED3, LOW); //Turn of LED3
      digitalWrite(LED4, LOW); //Turn of LED4
    }
    Serial.println(dist); //Print read distance to serial
  }
}

void blinkLights(){
  lightsOn = !lightsOn; //If lights are on, turn them off and vice versa
  digitalWrite(LED1, lightsOn);
  digitalWrite(LED2, lightsOn);
  digitalWrite(LED3, lightsOn);
  digitalWrite(LED4, lightsOn);

}

void setLights(float dist){
  digitalWrite(LED1, dist <= 40); //Turn on LED1 if distance is less than or equal to 40
  digitalWrite(LED2, dist <= 35); //Turn on LED2 if distance is less than or equal to 35
  digitalWrite(LED3, dist <= 25); //Turn on LED3 if distance is less than or equal to 25
  digitalWrite(LED4, dist <= 20); //Turn on LED4 if distance is less than or equal to 20
  
  //If distance is less than or equal to 15, blink the lights
  if(dist <= 15){
    blinkLights(); //Blink lights
  }
}

void setBuzz(float dist){
  //If distance is between 50 and 40
  if(dist <= 50 && dist > 40){
      ledcSetup(0, 500, 8); //Sound buzzer with 500hz frequency
      ledcWrite(0, 125);
  }
  //If distance is between 35 and 25
  else if(dist <= 35 && dist > 25){
      ledcSetup(0, 600, 8); //Sound buzzer with 600hz frequency
      ledcWrite(0, 125);
  }
  //If distance is between 25 and 20
  else if(dist <= 25 && dist > 20){
      ledcSetup(0, 700, 8); //Sound buzzer with 700hz frequency
      ledcWrite(0, 125);
  }
  //If distance is between 20 and 15
  else if(dist <= 20 && dist > 15){
      ledcSetup(0, 800, 8); //Sound buzzer with 800hz frequency
      ledcWrite(0, 125);
  }
  //If distance is between 15 and 0
  else if(dist <= 15 && dist > 0){
      ledcSetup(0, 900, 8); //Sound buzzer with 900hz frequency
      ledcWrite(0, 125);
  }
}
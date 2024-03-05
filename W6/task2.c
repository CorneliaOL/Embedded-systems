// (C) Lucas Holter, Cornelia Olofsson, Rizwan Rafiq, group: 18 (2024)
// Work package 6 - smartcar shield
// Exercise 2
// Submission code: z4z6rd

#include <Smartcar.h>

#define MAX 100
#define buzzerPin 19 
#define LED1 23
#define LED2 33
#define LED3 32
#define LED4 17

ArduinoRuntime arduinoRuntime;
BrushedMotor leftMotor(arduinoRuntime, smartcarlib::pins::v2::leftMotorPins);
BrushedMotor rightMotor(arduinoRuntime, smartcarlib::pins::v2::rightMotorPins);
DifferentialControl control(leftMotor, rightMotor);
SimpleCar car(control);
bool lightsOn = false;

SR04 front(arduinoRuntime, 5, 18, 40);
unsigned long curTime;
unsigned long prevTime;
unsigned int interval = 500;
int currSpeed = -30;

void setup() {
  Serial.begin(115200);
  car.setSpeed(currSpeed);

  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  pinMode(LED4, OUTPUT);

  ledcSetup(0, 1000, 8); // Channel 0, 2000 Hz frequency, 8-bit resolution
  ledcAttachPin(buzzerPin, 0);
  
}

void loop() {
  // put your main code here, to run repeatedly: 
  float freq;
  curTime = millis();
  if(curTime-prevTime >= interval){
    prevTime = curTime;

    float dist = front.getDistance(); 
    if((dist < 50) && (dist != 0)){
      setBuzz(dist);
      setLights(dist);
      currSpeed = map(dist, 10, 40, 0, -30);
      car.setSpeed(currSpeed);
    }
    if(dist == 0){
      ledcWrite(0, 0);
      car.setSpeed(-30);
      digitalWrite(LED1, LOW);
      digitalWrite(LED2, LOW);
      digitalWrite(LED3, LOW);
      digitalWrite(LED4, LOW);
    }
    Serial.println(dist);
  }
  
  delay(10);
}

void blinkLights(){
  lightsOn = !lightsOn;
  digitalWrite(LED1, lightsOn);
  digitalWrite(LED2, lightsOn);
  digitalWrite(LED3, lightsOn);
  digitalWrite(LED4, lightsOn);

}

void setLights(float dist){
  digitalWrite(LED1, dist <= 40);
  digitalWrite(LED2, dist <= 35);
  digitalWrite(LED3, dist <= 25);
  digitalWrite(LED4, dist <= 20);
  
  if(dist <= 15){
    blinkLights();
  }
}

void setBuzz(float dist){
  if(dist <= 50 && dist > 40){
      ledcSetup(0, 500, 8);
      ledcWrite(0, 125);
  }
  else if(dist <= 35 && dist > 25){
      ledcSetup(0, 600, 8);
      ledcWrite(0, 125);
  }
  else if(dist <= 25 && dist > 20){
      ledcSetup(0, 700, 8);
      ledcWrite(0, 125);
  }
  else if(dist <= 20 && dist > 15){
      ledcSetup(0, 800, 8);
      ledcWrite(0, 125);
  }
  else if(dist <= 15 && dist > 0){
      ledcSetup(0, 900, 8);
      ledcWrite(0, 125);
  }
}
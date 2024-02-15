// (C) Lucas Holter, Cornelia Olofsson, Rizwan Rafiq, group: 18 (2024)
// Work package 2
// Exercise 2
// Submission code: 

#define lightRes A1
#define tempSens A0
#define green 4
#define yellow 3
#define red 2


void setup() //Setup function, this will be the first thing to happen in the program
{
  pinMode(lightRes, INPUT); //Sets pin A3 to input
  pinMode(tempSens, INPUT); //Sets pin A3 to input
  pinMode(green, OUTPUT); //Sets pin 13 to output
  pinMode(red, OUTPUT); //Sets pin 12 to output
  pinMode(yellow, OUTPUT); //Sets pin 11 ti output
  Serial.begin(9600); //Begin serial with the bandwidth of 9600
}

void loop() //Loop function, thiw is in essence a perpetual loop
{
  int temp = 0; //Initialize variable temp, this will hold temmperature reading
  int light = 0; //Initialize variable light, this will hold the light reading
  while(1){
    light = analogRead(lightRes); //Read the analog pin A4, which is the light sensor, this will give us the voltage of pin A4
  	temp = analogRead(tempSens); //Read the analog pin A3, which is the temperature sensor, this will give us the voltage of pin A3
    
	//Scaling factor found online
  	temp = map((temp-20)*3.04,0, 1023, -40, 125); //Mapping used found here: https://www.instructables.com/TMP36-Temperature-Sensor-Arduino-Tinkercad/
    light = map(light, 54, 974, 0, 100); //Map photoresistors lowest to highest voltage to 0-100. So lowest voltage will corespond to 0, and highest to 100
    
  	Serial.println(temp); //Print new, converted value of temp to serial monitor
    Serial.println(light); //Print new, converted value of light to serial monitor
    
	//This if statement checks if the temperature is higher than the coresponding light value should have as described in the assignment.
    if( (light == 0) && (temp >= -12) 
      || (((light <= 20) && (light >= 1)) && (temp > 0))
      || (((light <= 60) && (light >= 21)) && ((temp > 20))) ) {
      	digitalWrite(red, HIGH); //If it is, turn on the red light
      	digitalWrite(green, LOW); //Turn off the green light
      	digitalWrite(yellow, LOW); //And turn of the yellow light
    }
	//This if statement checks if the temperature is lower than the coresponding light value should have as described in the assignment.
    else if((((light <= 20) && (light >= 1)) && (temp < -12))
      || (((light <= 60) && (light >= 21)) && (temp < 0)) 
      || (((light <= 100) && (light >= 61)) && (temp < 21) )){
    	digitalWrite(red, LOW); //Turn off the red light
      	digitalWrite(green, LOW); //Turn off the green light
      	digitalWrite(yellow, HIGH); //Turn on the yellow light
    }
	//If neither of the above is true, we are in a good range
    else{
      digitalWrite(red, LOW); //Turn off red light
      digitalWrite(green, HIGH); //Turn on green light
      digitalWrite(yellow, LOW); //Turn on yellow light
    }
      
    
    Serial.println("Waiting"); //Print "Waiting" to serial monitor
    delay(500); //Wait 500 ms
    
    
  }
}
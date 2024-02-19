#include <Adafruit_NeoPixel.h>

#define PIN 6 //built in pins from the neopixel
#define SENSOR_PIN A0 // temperature sensor pin
#define STATUS_LED_PIN 5 //pin that will signal if the temperature is "out of bounds" on the neopixel
const int buzzer = 7; //buzzer to arduino pin 7
int flag = 0; //flag that will get used in the loop()
int lowerBound = 0;
int higherBound = 100;


Adafruit_NeoPixel strip = Adafruit_NeoPixel(24, PIN, NEO_GRB + NEO_KHZ800); // declare a strip object and set properties, can be found in the documentation

void setup() {
  
   cli(); //pause interuptions
  TCCR1A = 0;                 // Reset entire TCCR1A to 0 
  TCCR1B = 0;                 // Reset entire TCCR1B to 0
 
  TCCR1B |= B00000100;        //Set CS12 to 1 so we get prescalar 256  
  
  TIMSK1 |= B00000010;        //Set OCIE1A to 1 so we enable compare match A 
  
  OCR1A = 31250;             //We set compare register A to this value  
  sei();    // begin interuptions again
  
  strip.begin(); //begin the strip 
  pinMode(STATUS_LED_PIN, OUTPUT); // set output for status pin
  digitalWrite(STATUS_LED_PIN, LOW); // Turn off the status LED initially
  pinMode(buzzer, OUTPUT); // Set buzzer - pin 7 as an output
}

void loop() {
  if (flag == 1){ // if flag is equal to one
  float temperature = readSensor(); // read temperature
  
  if (temperature >= lowerBound && temperature <= higherBound) { // check if temperature is within a certain temperature intervall
    displayValueOnNeoPixel(temperature); //if so, display value on neoPixel ring
    digitalWrite(STATUS_LED_PIN, LOW); // Turn off the status LED
  } else {
    // Temperature outside the desired range, light up the status LED
    displayStatusLED();
  }
    flag = 0; //reset the flag to 0 and do nothing until flag is 1 again
  }
    }

void displayValueOnNeoPixel(float value) {
  noTone(buzzer);     // Stop sound
  strip.clear(); // clear the strip 
  int numPixelsToLight = map(value, lowerBound, higherBound, 0, 24); // map pixels to light based on the temperature that is within 0-100 with this calculation
  
  for (int i = 0; i < numPixelsToLight; i++) { // for all pixels to light
    strip.setPixelColor(i, strip.Color(0, 255, 0)); //set the pixel with colour, this is a green colour
  }
  
  strip.show(); // show the light up pixels
}

ISR(TIMER1_COMPA_vect){
    TCNT1  = 0;                  //First, set the timer back to 0 so it resets for next interrupt
	flag = 1;                   // then, set the flag to 1 so that the loop will trigger the displayValueOnNeoPixel
}

void displayStatusLED() {
  strip.clear(); // Turn off the NeoPixel ring leds
  strip.show(); //show nothing 
  tone(buzzer, 1000); // start the buzzer 

  // Light up the status LED in red
  digitalWrite(STATUS_LED_PIN, HIGH);
}

//calculate the readings from the sensor to celius and 
float readSensor() {
  int sensorReading = analogRead(SENSOR_PIN);
  float voltage = sensorReading * 5.0 / 1023.0;
  float temperatureC = (voltage - 0.5) * 100.0;
  return temperatureC;
}

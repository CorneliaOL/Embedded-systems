/* to attach display check , 
reference: OLED display code help 
https://randomnerdtutorials.com/guide-for-oled-display-with-arduino/

https://stackoverflow.com/questions/40874880/getting-nan-readings-from-dht-11-sensor
*/

// (C) Lucas Holter, Cornelia Olofsson, Rizwan Rafiq, group: 18 (2024)
// Work package 5
// Exercise 2
// Submission code: 1


#include <DHT.h>
#include <Wire.h>               // Include Wire library for I2C
#include <Adafruit_GFX.h>       // Include core graphics library for the display
#include <Adafruit_SSD1306.h>   // Include Adafruit_SSD1306 library to control the OLED

#define DATA_PIN2 2             /* define pin 2 for temprature sensor */
#define SCREEN_WIDTH 128        /* OLED display width, in pixels */
#define SCREEN_HEIGHT 64        /* OLED display height, in pixels */
#define OLED_RESET     -1       /* Reset pin # (or -1 if sharing Arduino reset pin) */
#define SCREEN_ADDRESS 0x3C     /* screen address declaration, specific to OLED 128x64 */

/* make an instance of display with required parameters */
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

DHT dht;                        /* make instance of temprature sensor */
float temp;                     /* variable to hold temporary value of temprature */
float btemp;


unsigned long previousMillis = 0; // will store last time the OLED was updated
const long interval = 500;    // interval at which to update the screen (milliseconds)

void updateLEDsBasedOnTemperature();

void setup() {
  
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);

  cli();
  TCCR1A = 0;
  TCCR1B = 0;
  TCCR1B |= B00000011;  // Prescalar value set to 64 CS12=1 , CS11=0, CS10=0
  TIMSK1 |= B00000010;
  OCR1A = 2499;
  sei();
  Serial.begin(9600);

  // Initialize the OLED display
  if(!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {
    Serial.println(F("SSD1306 allocation failed"));
    for(;;); // Don't proceed, loop forever
  }
  display.display();
  delay(2000); // Pause for 2 seconds
  display.clearDisplay();




  //Serial.println("Humidity (%)\tTemperature (C)");

  dht.setup(DATA_PIN2);
  delay(dht.getMinimumSamplingPeriod());
  
}

void loop() {

unsigned long currentMillis = millis();
    if (currentMillis - previousMillis >= interval) {
        
        // save the last time you updated the OLED
        previousMillis = currentMillis;
        
        // Read temperature as Celsius
        temp = dht.getTemperature();
        
        // Clear the previous display
        display.clearDisplay();
        display.setTextSize(1); // Normal 1:1 pixel scale
        display.setTextColor(SSD1306_WHITE); // Draw white text
        display.setCursor(0,0); // Start at top-left corner
        display.print(F("Temp: "));
        if(!isnan(temp)){
        btemp = temp;
        display.print(temp);
        Serial.println(temp);
        }
        else {
        display.print(btemp);
        Serial.println(temp);
        }
        display.println(F(" C"));
        display.display(); // Actually display the text written above
    }

}

ISR(TIMER1_COMPA_vect){
  
  TCNT1  = 0;                  //First, set the timer back to 0 so it resets for next interrupt
  updateLEDsBasedOnTemperature(); // This should be trigered in loop() by setting a flag for best practice

}


void updateLEDsBasedOnTemperature() {

  if(temp < 10){
    digitalWrite(8,   HIGH);
    digitalWrite(9,   LOW);
    digitalWrite(10,  LOW);
    digitalWrite(11,  LOW);
    digitalWrite(12,  LOW);
  } else if (temp >= 10 && temp <= 15){
    digitalWrite(8,   HIGH);
    digitalWrite(9,   HIGH);
    digitalWrite(10,  LOW);
    digitalWrite(11,  LOW);
    digitalWrite(12,  LOW);
  } else if (temp >= 16 && temp <= 18){
    digitalWrite(8,   HIGH);
    digitalWrite(9,   HIGH);
    digitalWrite(10,  HIGH);
    digitalWrite(11,  LOW);
    digitalWrite(12,  LOW);
  } else if (temp >= 19 && temp <= 25){
    digitalWrite(8,   HIGH);
    digitalWrite(9,   HIGH);
    digitalWrite(10,  HIGH);
    digitalWrite(11,  HIGH);
    digitalWrite(12,  LOW);

  } else if (temp >= 26 && temp <= 30){
    digitalWrite(8,   HIGH);
    digitalWrite(9,   HIGH);
    digitalWrite(10,  HIGH);
    digitalWrite(11,  HIGH);
    digitalWrite(12,  HIGH);
  }


}

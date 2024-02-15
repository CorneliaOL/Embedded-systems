// (C) Lucas Holter, Cornelia Olofsson, Rizwan Rafiq, group: 18 (2024)
// Work package 2
// Exercise 3.1
// Submission code: 

#include <LiquidCrystal.h> //Import library to handle the lcd display

const int rs=12, d4=6, d5=5, d6=3, d7=2, en=11; //Set different pins to the functionallity they corespond to on the LCD
LiquidCrystal lcd(rs, en, d4, d5, d6, d7); //Initialize the display with the pin numbers that the functionallity is wired to
//Setup function, will happen first in the program
void setup() 
{
  pinMode(2, OUTPUT); //Set pin 2 to output
  pinMode(8, OUTPUT); //Set pin 8 to output
  pinMode(9, OUTPUT); //Set pin 9 to output
  pinMode(10, OUTPUT); //Set pin 10 to output
  pinMode(11, OUTPUT); //Set pin 11 to output
  pinMode(13, OUTPUT); //Set pin 13 to output
 
  Serial.begin(9600);
  lcd.begin(16, 2); //Start the lcd 
}

//Loop function that will happen continously
void loop()
{
  int rawTemp = analogRead(A1); //Reads analog pin 1, which is the temperature sensor. This will give us a voltage
  float temp = rawTemp*(5.0/1023.0)*1000;
  float tempC = (temp-500)/10; //Convert that voltage to a temperature
  Serial.println(tempC);
  lcd.clear(); //Clear the LCD display
  lcd.setCursor(0,0); //Set the cursor of the display to the start
  lcd.print(tempC); //Print the converted temperature to the display
  delay(500); //Wait 0.5 sec
 
}
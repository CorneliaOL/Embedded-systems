
// Beginning of keypad configuration code

#include <Keypad.h>   /* Preprocessor directive - includes Keypad functions */

const byte ROWS = 4; // variable declaration & initialization for number of rows
const byte COLS = 4; // variable declaration & initialization for number of columns

// Multidimensional array to define the keypad keys for mapping 
char keys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};

byte rowPins[ROWS] = {11, 10, 9, 8};  // Row pins declaration in array 

byte colPins[COLS] = {7, 6, 5, 4};    // Column pins declaration in array

Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS ); // making instance of keypad from object keypad

// End of keypad configuration code


void setup() {    // start of setup function 
  
  // initiate the serial to have values in the console
  Serial.begin(9600); // with baud rate 9600 bit/sec
}                 // end of setup function

void loop() {     // start of loop function

  char key = keypad.getKey(); //variable declaration to hold the keypad value against pressed button
  
  if (key){                   // if-block to check triggered event from getKey() function 
    Serial.print(key);      
  }

}                 // end of loop function

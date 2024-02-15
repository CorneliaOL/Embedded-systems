// (C) Lucas Holter, Cornelia Olofsson, Rizwan Rafiq, group: 18 (2024)
// Work package 3
// Exercise 4
// Submission code: 

//Include keypad library to handle keypad
#include <Keypad.h>

byte output[4][4] = { //Defines the keyboard layout in a matrix
    {'1', '2', '3', 'A'},
    {'4', '5', '6', 'B'},
    {'7', '8', '9', 'C'},
    {'*', '0', '#', 'D'}
};
byte rows[4] = {11, 10, 9, 8}; //defines the pins the rows are connected to
byte cols[4] = {7, 6, 5, 4}; //defines the pins the cols are connected to

Keypad keypad = Keypad(makeKeymap(output), rows, cols, 4, 4); //Initialize the keypad with layout of keyboard, rowpins, colpins and ammount of rows and cols

//Setup function, this will be executed first in the program
void setup(){
    Serial.begin(9600); //Begin serial
}

//Loop, this will happen continously after the setup function
void loop(){

    char pressed = keypad.getKey(); //Check if a key is being pressed, if so, assign it to the pressed variable

    //If a key was pressed
    if(pressed != NULL){
        Serial.println(pressed); //print it
    }
  
}
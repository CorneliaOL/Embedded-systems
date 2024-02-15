// (C) Lucas Holter, Cornelia Olofsson, Rizwan Rafiq, group: 18 (2024)
// Work package 3
// Exercise 3.2
// Submission code: 655738

//Defines different pins the rows and cols are connected to
#define row1 11 //defines that row 1 is connected to pin 11
#define row2 10 //defines that row 2 is connected to pin 10
#define row3 9 //defines that row 3 is connected to pin 9
#define row4 8 //defines that row 4 is connected to pin 8

#define col1 7 //defines that column 1 is connected to pin 7
#define col2 6 //defines that column 1 is connected to pin 6
#define col3 5 //defines that column 1 is connected to pin 5
#define col4 4 //defines that column 1 is connected to pin 7

typedef unsigned char byte; //Defines the type byte to be unsigned char

byte input[4][4]; //declare an array if size 4x4 to hold the values of the combinations of row and column
byte output[4][4] = { //Defines a matrix of the characters on the keyboard
	{'1', '2', '3', 'A'},
	{'4', '5', '6', 'B'},
	{'7', '8', '9', 'C'},
	{'*', '0', '#', 'D'}
}; 

//Setup cuntion, this will happen first in the program
void setup(){

  Serial.begin(9600); //Initializes serial with a bandwidth of 9600

  pinMode(row1, OUTPUT); //Sets the pin corrosponding to row1 to output
  pinMode(row2, OUTPUT); //Sets the pin corrosponding to row2 to output
  pinMode(row3, OUTPUT); //Sets the pin corrosponding to row3 to output
  pinMode(row4, OUTPUT); //Sets the pin corrosponding to row4 to output

  pinMode(col1, INPUT); //Sets the pin corrosponding to column1 to output
  pinMode(col2, INPUT); //Sets the pin corrosponding to column2 to output
  pinMode(col3, INPUT); //Sets the pin corrosponding to column3 to output
  pinMode(col4, INPUT); //Sets the pin corrosponding to column4 to output

  //Ensure all rows are set high
  digitalWrite(row1, HIGH); //set row1 high
  digitalWrite(row2, HIGH); //set row2 high
  digitalWrite(row3, HIGH); //set row3 high
  digitalWrite(row4, HIGH); //set row4 high


}

//This function will be executed continously after the setup function
void loop(){

  digitalWrite(row1, LOW); //Set row1 to low to be able to read the columns, if row is high, column will always be tied high
  input[0][0] = digitalRead(col1); //read value of col1 and put it into matrix
  input[0][1] = digitalRead(col2); //read value of col2 and put it into matrix
  input[0][2] = digitalRead(col3); //read value of col3 and put it into matrix
  input[0][3] = digitalRead(col4); //read value of col4 and put it into matrix
  digitalWrite(row1, HIGH); //Set row1 to high again to read the next row
  
  digitalWrite(row2, LOW); //set row2 to low to read the columns
  input[1][0] = digitalRead(col1); //read value of col1 and put it into matrix 
  input[1][1] = digitalRead(col2); //read value of col2 and put it into matrix
  input[1][2] = digitalRead(col3); //read value of col3 and put it into matrix
  input[1][3] = digitalRead(col4); //read value of col4 and put it into matrix
  digitalWrite(row2, HIGH); //Set row2 to high again to read the next row

  digitalWrite(row3, LOW); //set row3 to low to read the columns
  input[2][0] = digitalRead(col1); //read value of col1 and put it into matrix
  input[2][1] = digitalRead(col2); //read value of col2 and put it into matrix
  input[2][2] = digitalRead(col3); //read value of col3 and put it into matrix
  input[2][3] = digitalRead(col4); //read value of col4 and put it into matrix
  digitalWrite(row3, HIGH); //Set row3 to high again to read the next row

  digitalWrite(row4, LOW); //set row4 to low to read the columns
  input[3][0] = digitalRead(col1); //read value of col1 and put it into matrix
  input[3][1] = digitalRead(col2); //read value of col2 and put it into matrix
  input[3][2] = digitalRead(col3); //read value of col3 and put it into matrix
  input[3][3] = digitalRead(col4); //read value of col4 and put it into matrix
  digitalWrite(row4, HIGH); //Set row4 to high again to read the next row


  //for every row in the input matrix
  for(int i = 0; i < 4; i++){
	//for every column in the input matrix
    for (int j = 0; j < 4; j++)
	  //If that vlaue is 0
      if(input[i][j] == 0){
        Serial.println((char)output[i][j]); //Print out the corresponding value from the output matrix
      }
  }

  delay(1000); //wait 1 sec
}
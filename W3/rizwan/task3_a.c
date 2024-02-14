/* 
WP3 - Keypad without library 
*/

// Define the connections to the rows and columns of the keypad
const int ROW_NUM = 4; // Four rows
const int COLUMN_NUM = 4; // Four columns

// Define the symbols on the buttons of the keypads
char keys[ROW_NUM][COLUMN_NUM] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};

// Connect to the row pinouts of the keypad
byte rowPins[ROW_NUM] = {11, 10, 9, 8}; // Connect to the row pinouts of the keypad
byte colPins[COLUMN_NUM] = {7, 6, 5, 4}; // Connect to the column pinouts of the keypad

void setup() {
  Serial.begin(9600);
  // Initialize the row pins as outputs
  for (int i = 0; i < ROW_NUM; i++) {
    pinMode(rowPins[i], OUTPUT);
    digitalWrite(rowPins[i], HIGH);
  }

  // Initialize the column pins as inputs
  for (int i = 0; i < COLUMN_NUM; i++) {
    pinMode(colPins[i], INPUT);
  }
}

void loop() {
  for (int row = 0; row < ROW_NUM; row++) {
    digitalWrite(rowPins[row], LOW); // Activate the current row.
    
    for (int col = 0; col < COLUMN_NUM; col++) {
      if (digitalRead(colPins[col]) == LOW) { // Check if the button is pressed
        Serial.println(keys[row][col]); // Print the key's character
        delay(500); // Debounce
        while(digitalRead(colPins[col]) == LOW); // Wait for the button to be released
      }
    }
    
    digitalWrite(rowPins[row], HIGH); // Deactivate the current row.
  }
}
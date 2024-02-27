// (C) Lucas Holter, Cornelia Olofsson, Rizwan Rafiq, group: 18 (2024)
// Work package 5
// Exercise 1
// Submission code: 1

#define BUTTON_PIN 2
#define RED_LED 11
#define GREEN_LED 12

// Variables for debouncing
volatile bool buttonPressed = false;
volatile unsigned long lastDebounceTime = 0; // the last time the output pin was toggled
unsigned long debounceDelay = 50; // the debounce time; increase if the output flickers

void setup() {
  pinMode(BUTTON_PIN, INPUT);
  pinMode(RED_LED, OUTPUT);
  pinMode(GREEN_LED, OUTPUT);
  digitalWrite(GREEN_LED, LOW);

  cli(); // stop interrupts

  TCCR1A = 0; // set entire TCCR1A register to 0
  TCCR1B = 0; // same for TCCR1B
  TCNT1  = 0; //initialize counter value to 0
  // set compare match register for 100hz increments
  OCR1A = 1562; // = 16000000 / (1024 * 100) - 1 (must be <65536)
  // turn on CTC mode
  TCCR1B |= (1 << WGM12);
  // Set CS10 and CS12 bits for 1024 prescaler
  TCCR1B |= (1 << CS12) | (1 << CS10);  
  // enable timer compare interrupt
  TIMSK1 |= (1 << OCIE1A);

  sei(); // allow interrupts
}

void loop() {
  digitalWrite(RED_LED, HIGH);
  delay(1000);
  digitalWrite(RED_LED, LOW);
  delay(1000);
}

ISR(TIMER1_COMPA_vect) {
  // Debouncing logic
  if ((millis() - lastDebounceTime) > debounceDelay) {
    // Check button state only if debounce time has passed
    if (digitalRead(BUTTON_PIN) == HIGH) {
      if (!buttonPressed) { // If the button state has changed
        buttonPressed = true;
        digitalWrite(GREEN_LED, HIGH);
      }
    } else {
      if (buttonPressed) { // If the button state has changed
        buttonPressed = false;
        digitalWrite(GREEN_LED, LOW);
      }
    }
  }
}

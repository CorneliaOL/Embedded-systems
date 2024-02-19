
// (C) Lucas Holter, Cornelia Olofsson, Rizwan Rafiq, group: 18 (2024)
// Work package 4
// Exercise 1
// Submission code: ??????


int temp = 0;       /* variable declaration to hold the temprature value */

void updateLEDsBasedOnTemperature();    /* function prototype - to update LEDs based on temp value */


void setup(){

  cli();                                /* to disble all global interrupts */

  TCCR1A = 0;                           /* reset entire TCCR1A register */
  TCCR1B = 0;                           /* reset entire TCCR1B register */

  TCCR1B |= B00000011;                  // Prescalar value set to 64 for Timer1/Control Register B

  TIMSK1 |= B00000010;                  /* //Set OCIE1A to 1 to enable compare match A on Register A */

  OCR1A = 2499;                         /* set compare register A to this value */
  sei();                                /* to enable back all global registers */

  pinMode(8, OUTPUT);                   /* set pin 8 as output pin */
  pinMode(9, OUTPUT);                   /* set pin 9 as output pin */
  pinMode(10, OUTPUT);                  /* set pin 10 as output pin */
  pinMode(11, OUTPUT);                  /* set pin 11 as output pin */
  pinMode(12, OUTPUT);                  /* set pin 12 as output pin */

}

void loop(){
  updateLEDsBasedOnTemperature();       /* function call - to update LEDs based on temp value */
}

ISR(TIMER1_COMPA_vect){
  
  TCNT1  = 0;                           /* first set the timer back to 0 so it resets for next interrupt */

  temp = analogRead(A0);                /* variable declaration/initialization to hold voltage at pin A0 */
  temp = map((temp-20)*3.04, 0, 1023, -40, 125);    /* mapping voltage to temp value */

}

/* if-blocks to decide number of LEDs based on temprature at A0 */
void updateLEDsBasedOnTemperature() {


  if(temp>=0 && temp<=10){              /* Range 1 : to lid 1 LED */
    digitalWrite(8,   HIGH);
    digitalWrite(9,   LOW);
    digitalWrite(10,  LOW);
    digitalWrite(11,  LOW);
    digitalWrite(12,  LOW);
  } else if (temp>=11 && temp<=20){     /* Range 2 : to lid 2 LEDs */
    digitalWrite(8,   HIGH);
    digitalWrite(9,   HIGH);
    digitalWrite(10,  LOW);
    digitalWrite(11,  LOW);
    digitalWrite(12,  LOW);
  } else if (temp>=21 && temp<=30){     /* Range 3 : to lid 3 LEDs */
    digitalWrite(8,   HIGH);
    digitalWrite(9,   HIGH);
    digitalWrite(10,  HIGH);
    digitalWrite(11,  LOW);
    digitalWrite(12,  LOW);
  } else if (temp>=31 && temp<=40){     /* Range 4 : to lid 4 LEDs */
    digitalWrite(8,   HIGH);
    digitalWrite(9,   HIGH);
    digitalWrite(10,  HIGH);
    digitalWrite(11,  HIGH);
    digitalWrite(12,  LOW);

  } else if (temp>=41 && temp<=50){     /* Range 5 : to lid 5 LEDs */
    digitalWrite(8,   HIGH);
    digitalWrite(9,   HIGH);
    digitalWrite(10,  HIGH);
    digitalWrite(11,  HIGH);
    digitalWrite(12,  HIGH);

  }

}           /* end of function */
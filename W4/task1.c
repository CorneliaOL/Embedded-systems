// (C) Lucas Holter, Cornelia Olofsson, Rizwan Rafiq, group: 18 (2024)
// Work package 4
// Exercise 1
// Submission code: 18987221


int temp = 0;       /* variable declaration to hold the temprature value */
int flag = 0;       /* variable declaration to notify when timer has been triggered */

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
  Serial.begin(9600);                   /* initialize serial */

}

void loop(){
  
  if (flag == 1){                           /* if flag equals 1 , timer has been triggered */
  	temp = analogRead(A0);                /* variable declaration/initialization to hold voltage at pin A0 */
  	temp = map((temp-20)*3.04, 0, 1023, -40, 125);    /* mapping voltage to temp value */
    updateLEDsBasedOnTemperature();       /* function call - to update LEDs based on temp value */
    Serial.println(temp);                 /* print temp value in the serial  */
    flag = 0;                               /* set flag to 0 */
    
  }
  
}

ISR(TIMER1_COMPA_vect){
  
  TCNT1  = 0;                           /* first set the timer back to 0 so it resets for next interrupt */
  flag = 1;                             /* set flag to 1  */

}

/* if-blocks to decide number of LEDs based on temprature at A0 */
void updateLEDsBasedOnTemperature() {
	digitalWrite(8, (temp>=0));         /* turn on first LED if temp is >= 0 */
  	digitalWrite(9, (temp>=11));        /* turn on second LED if temp is >= 11 */
  	digitalWrite(10, (temp>=21));       /* turn on third LED if temp is >= 21 */
  	digitalWrite(11, (temp>=31));       /* turn on fourth LED if temp is >= 31 */
  	digitalWrite(12, (temp>=41));       /* turn on fifth LED if temp is >= 41 */
  
  
}           /* end of function */
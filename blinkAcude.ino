// Which pins are connected to which LED
const byte greenLED = 11;
const byte redLED = 12;
const byte blueLED = 10;

// Time periods of blinks in milliseconds (1000 to a second).
const unsigned long greenLEDinterval = 400;
const unsigned long redLEDinterval = 500;
const unsigned long blueLEDinterval = 300;

// Variable holding the timer value so far. One for each "Timer"
unsigned long greenLEDtimer;
unsigned long redLEDtimer;
unsigned long blueLEDtimer;

void setup () 
  {
  pinMode (greenLED, OUTPUT);
  pinMode (redLED, OUTPUT);
  pinMode (blueLED, OUTPUT);
  greenLEDtimer = millis ();
  redLEDtimer = millis ();
  blueLEDtimer = millis ();
  }  // end of setup

void toggleGreenLED ()
  {
   if (digitalRead (greenLED) == LOW)
      digitalWrite (greenLED, HIGH);
   else
      digitalWrite (greenLED, LOW);

  // remember when we toggled it
  greenLEDtimer = millis ();  
  }  // end of toggleGreenLED

void toggleRedLED ()
  {
   if (digitalRead (redLED) == LOW)
      digitalWrite (redLED, HIGH);
   else
      digitalWrite (redLED, LOW);

  // remember when we toggled it
  redLEDtimer = millis ();  
  }  // end of toggleRedLED


void toggleBlueLED ()
  {
   if (digitalRead (blueLED) == LOW)
      digitalWrite (blueLED, HIGH);
   else
      digitalWrite (blueLED, LOW);

  // remember when we toggled it
  blueLEDtimer = millis ();  
  }  // end of toggleRedLED

void loop ()
  {

  // Handling the blink of one LED.
  if ( (millis () - greenLEDtimer) >= greenLEDinterval)
     toggleGreenLED ();

  // The other LED is controlled the same way. Repeat for more LEDs
  if ( (millis () - redLEDtimer) >= redLEDinterval) 
    toggleRedLED ();

  if ( (millis () - blueLEDtimer) >= blueLEDinterval) 
    toggleBlueLED ();

/* Other code that needs to execute goes here.
   It will be called many thousand times per second because the above code
   does not wait for the LED blink interval to finish. */

}  // end of loop

#include <IRremote.h>

int IRPIN = 4; //pino do receptor IR

// leds controláveis
int irLEDPin1 = 8;
int irLEDPin2 = 9;
int irLEDPin3 = 10;
int irLEDPin4 = 11;
int irLEDPin5 = 12;
int irLEDPin6 = 13;

unsigned long LEDinterval1 = 2000;
unsigned long LEDinterval2 = 200;
unsigned long LEDinterval3 = 200;
unsigned long LEDinterval4 = 200;
unsigned long LEDinterval5 = 200;
unsigned long LEDinterval6 = 200;

unsigned long LEDtimer1;
unsigned long LEDtimer2;
unsigned long LEDtimer3;
unsigned long LEDtimer4;
unsigned long LEDtimer5;
unsigned long LEDtimer6;

IRrecv irrecv(IRPIN);

decode_results result;

void setup()
{
  Serial.begin(9600);
  Serial.println("Enabling IRin");
  irrecv.enableIRIn();
  Serial.println("Enabled IRin");

  pinMode (irLEDPin1, OUTPUT);
  pinMode (irLEDPin2, OUTPUT);
  pinMode (irLEDPin3, OUTPUT);
  pinMode (irLEDPin4, OUTPUT);
  pinMode (irLEDPin5, OUTPUT);
  pinMode (irLEDPin6, OUTPUT);
  LEDtimer1 = millis ();
  LEDtimer2 = millis ();
  LEDtimer3 = millis ();
  LEDtimer4 = millis ();
  LEDtimer5 = millis ();
  LEDtimer6 = millis ();
}

void toggleLED1 ()
  {
   if (digitalRead (irLEDPin1) == LOW)
      digitalWrite (irLEDPin1, HIGH);
   else
      digitalWrite (irLEDPin1, LOW);

  // remember when we toggled it
  LEDtimer1 = millis ();  
  } 

void toggleLED2 ()
  {
   if (digitalRead (irLEDPin2) == LOW)
      digitalWrite (irLEDPin2, HIGH);
   else
      digitalWrite (irLEDPin2, LOW);

  // remember when we toggled it
  LEDtimer2 = millis ();  
  } 

void toggleLED3 ()
  {
   if (digitalRead (irLEDPin3) == LOW)
      digitalWrite (irLEDPin3, HIGH);
   else
      digitalWrite (irLEDPin3, LOW);

  // remember when we toggled it
  LEDtimer3 = millis ();  
  } 

void toggleLED4 ()
  {
   if (digitalRead (irLEDPin4) == LOW)
      digitalWrite (irLEDPin4, HIGH);
   else
      digitalWrite (irLEDPin4, LOW);

  // remember when we toggled it
  LEDtimer4 = millis ();  
  } 

void toggleLED5 ()
  {
   if (digitalRead (irLEDPin5) == LOW)
      digitalWrite (irLEDPin5, HIGH);
   else
      digitalWrite (irLEDPin5, LOW);

  // remember when we toggled it
  LEDtimer5 = millis ();  
  } 

void toggleLED6 ()
  {
   if (digitalRead (irLEDPin6) == LOW)
      digitalWrite (irLEDPin6, HIGH);
   else
      digitalWrite (irLEDPin6, LOW);

  // remember when we toggled it
  LEDtimer6 = millis ();  
  } 



  
void loop() 
{
  if (irrecv.decode(&result)) 
  {
    Serial.println(result.value);
    irrecv.resume();
    switch (result.value) {
       case 16724175: 
        Serial.println("Botão 1"); 
        LEDinterval1 = LEDinterval1/2;
        break;
       case 16718055:
        Serial.println("Botão 2");
        LEDinterval2 = LEDinterval2/2;
        break;
       case 16743045: 
        Serial.println("Botão 3");
        LEDinterval3 = LEDinterval3/2;
        break;
       case 16716015: 
        Serial.println("Botão 4");
        LEDinterval4 = LEDinterval4/2;
        break;
       case 16726215: 
        Serial.println("Botão 5");
        LEDinterval5 = LEDinterval5/2;
        break;
       case 16734885: 
        Serial.println("Botão 6");
        LEDinterval6 = LEDinterval6/2;
        break;
      case 16738455:
        Serial.println("Botão 0");
        LEDinterval1 = 2000;
        break;
       
    }
    delay(1);
  }

  if ( (millis () - LEDtimer1) >= LEDinterval1)
     toggleLED1 ();

  if ( (millis () - LEDtimer2) >= LEDinterval2)
     toggleLED2 ();
  
  if ( (millis () - LEDtimer3) >= LEDinterval3)
     toggleLED3 ();
  
  if ( (millis () - LEDtimer4) >= LEDinterval4)
     toggleLED4 ();

  if ( (millis () - LEDtimer5) >= LEDinterval5)
     toggleLED5 ();
  
  if ( (millis () - LEDtimer6) >= LEDinterval6)
     toggleLED6 ();

  
} 

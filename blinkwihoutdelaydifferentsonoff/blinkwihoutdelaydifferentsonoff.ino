// 1: 16582903 2: 16615543 3: 16599223 4: 16591063 5: 16623703
// 6: 16607383 7: 16586983 8: 16619623 9: 16603303 0: 16593103
// vol+: 16613503 vol-: 16617583
#include <IRremote.h>

int IRPIN = 4; //pino do receptor IR

// leds controláveis
int irLEDPin1 = 12; // the number of the LED pin


// Variables will change:
int ledState = LOW;             // ledState used to set the LED
long previousMillis = 0;        // will store last time LED was updated

// the follow variables is a long because the time, measured in miliseconds,
// will quickly become a bigger number than can be stored in an int.
long interval = 0;           // interval at which to blink (milliseconds)
const unsigned long ONTIME = 3000UL;
const unsigned long OFFTIME = 5000UL;

IRrecv irrecv(IRPIN);

decode_results result;


void setup() {
  Serial.begin(9600);
  Serial.println("Enabling IRin");
  irrecv.enableIRIn();
  Serial.println("Enabled IRin");
  // set the digital pin as output:
  pinMode(irLEDPin1, OUTPUT);
}

void loop()
{
  if (irrecv.decode(&result))
  {
    Serial.println(result.value);
    irrecv.resume();
    switch (result.value) {
      case 16582903:
        Serial.println("Botão 1");
        break;

        delay(1);
    }
    // here is where you'd put code that needs to be running all the time.

    // check to see if it's time to blink the LED; that is, if the
    // difference between the current time and last time you blinked
    // the LED is bigger than the interval at which you want to
    // blink the LED.
      unsigned long currentMillis = millis();

    if (currentMillis - previousMillis > interval) {
      // save the last time you blinked the LED
      previousMillis = currentMillis;

      // if the LED is off turn it on and vice-versa:
      if (ledState == LOW)
      {
        interval = ONTIME;
        ledState = HIGH;
      }
      else
      {
        interval = OFFTIME;
        ledState = LOW;
      }
      // set the LED with the ledState of the variable:
      digitalWrite(irLEDPin1, ledState);
    }
  }
}


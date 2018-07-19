#include <IRremote.h>

const int CEILING = 5000;
const int FLOOR = 300;
const int COEFICIENT = 1000;

const int IRPIN = 4; //pino do receptor IR

// leds counterroláveis
const int irLEDPin[6] = {8,9,10,11,12,13};

//const int BUTTON[7] = {16738455, 16724175, 16718055, 16743045, 16716015, 16726215, 16734885};

int ledState[6] = {LOW, LOW, LOW, LOW, LOW, LOW}; // ledState used to set the LED
int counter[6] = {1, 1, 1, 1, 1, 1};
unsigned long blink_time[6] = {CEILING, CEILING, CEILING, CEILING, CEILING, CEILING};
long interval[6] = {0,0,0,0,0,0}; // interval at which to blink (milliseconds)
long previousMillis[6] = {0, 0, 0, 0, 0, 0}; // will store last time LED was updated

void blinkar(int button) {
  Serial.print("Botao ");
  Serial.println(button + 1);
  counter[button] = counter[button] + 1;
  if (blink_time[button] >= FLOOR)
    blink_time[button] = CEILING - (sqrt(counter[button])*COEFICIENT);
    Serial.println(counter[button]);
    Serial.println(blink_time[button]);
}

IRrecv irrecv(IRPIN);

decode_results result;

void setup() {
  Serial.begin(9600);
  Serial.println("Enabling IRin");
  irrecv.enableIRIn();
  Serial.println("Enabled IRin");
 
  // set the digital pin as output:
  pinMode(irLEDPin[0], OUTPUT);
  pinMode(irLEDPin[1], OUTPUT);
  pinMode(irLEDPin[2], OUTPUT);
  pinMode(irLEDPin[3], OUTPUT);
  pinMode(irLEDPin[4], OUTPUT);
  pinMode(irLEDPin[5], OUTPUT);
}

void toggleLED (int n, unsigned long currentMillis )
  {
    previousMillis[n] = currentMillis;

    if (ledState[n] == LOW)
      ledState[n] = HIGH;
    else
      ledState[n] = LOW;
  
    digitalWrite(irLEDPin[n], ledState[n]);  
  }

void loop()
{
  if (irrecv.decode(&result))
  {
    //Serial.println(result.value);
    irrecv.resume();
    switch (result.value) {
      case 16738455:
        Serial.println("Botao 0");
        for (int i = 0; i < 6; i++) {
          ledState[i] = LOW;
          counter[i] = 1;
          blink_time[i] = CEILING;
          interval[i] = 0;
          previousMillis[i] = 0;  
        }
      case 16724175:
        blinkar(0);
      	break;
      case 16718055:
        blinkar(1);
        break;  
    }
    delay(1);
  }
  unsigned long currentMillis = millis();

  if (currentMillis - previousMillis[0] > blink_time[0]) {
  toggleLED (0, currentMillis);
  }
  if (currentMillis - previousMillis[1] > blink_time[1]) {
    toggleLED (1, currentMillis);
  }
  if (currentMillis - previousMillis[2] > blink_time[2]) {
    toggleLED (2, currentMillis);
  }
  if (currentMillis - previousMillis[3] > blink_time[3]) {
    toggleLED (3, currentMillis);
  }
  if (currentMillis - previousMillis[4] > blink_time[4]) {
    toggleLED (4, currentMillis);
  }
  if (currentMillis - previousMillis[5] > blink_time[5]) {
    toggleLED (5, currentMillis);
  }
}

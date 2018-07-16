#include <IRremote.h>

int IRPIN = 4; //pino do receptor IR

// leds controláveis
int irLEDPin[6] = {8,9,10,11,12,13};

// Variables will change:
int ledState[6] = {LOW, LOW, LOW, LOW, LOW, LOW}; // ledState used to set the LED
long previousMillis[6] = {0,0,0,0,0,0};        // will store last time LED was updated

long interval[6] = {0,0,0,0,0,0};           // interval at which to blink (milliseconds)
const unsigned long ONTIME = 3000UL;
unsigned long OFFTIME[6] = {5000UL, 5000UL, 5000UL, 5000UL, 5000UL, 5000UL};

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
    {
      interval[n] = OFFTIME[n];
      ledState[n] = HIGH;
    }
    else
    {
      interval[n] = ONTIME;
      ledState[n] = LOW;
    }
    digitalWrite(irLEDPin[n], ledState[n]);  
  }

void loop()
{
  if (irrecv.decode(&result))
  {
    Serial.println(result.value);
    irrecv.resume();
    switch (result.value) {
      case 16582903:
        Serial.println("Botao 1");
      	OFFTIME[0] = OFFTIME[0] - 200;
        Serial.println(OFFTIME[0]);
      	break;
        delay(1);
    }
  }
  unsigned long currentMillis = millis();

  if (currentMillis - previousMillis[0] > interval[0]) {
  toggleLED (0, currentMillis);
  }
  if (currentMillis - previousMillis[1] > interval[1]) {
    toggleLED (1, currentMillis);
  }
  if (currentMillis - previousMillis[2] > interval[2]) {
    toggleLED (2, currentMillis);
  }
  if (currentMillis - previousMillis[3] > interval[3]) {
    toggleLED (3, currentMillis);
  }
  if (currentMillis - previousMillis[4] > interval[4]) {
    toggleLED (4, currentMillis);
  }
  if (currentMillis - previousMillis[5] > interval[5]) {
    toggleLED (5, currentMillis);
  }
}

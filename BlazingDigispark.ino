#define LEDpin      1   // LED on Model A

unsigned long randMillis = millis();
unsigned long fadeMillis = millis();
int fadeAmount = 1;
int brightness = 128;   // Brightness at start

// the setup routine runs once when you press reset:
void setup() {
  pinMode(LEDpin, OUTPUT);
}

// the loop routine runs over and over again forever:
void loop() {
  unsigned long currentMillis = millis();
  
  if (randMillis <= currentMillis) {
    fadeAmount = -fadeAmount;
    randMillis = currentMillis + random(100, 1000);
  }

  if (fadeMillis <= currentMillis) {
    if (brightness <= 0 || brightness >= 255) {
      fadeAmount = -fadeAmount;
    }
    brightness = brightness + fadeAmount;
    fadeMillis = currentMillis + 2;
  }

  analogWrite(LEDpin, brightness);
}

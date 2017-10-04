unsigned long randtime = millis();
unsigned long fadetime = millis();
int fadeAmount = 1;
int brightness = 128;   // Brightness at start
int LEDpin = 1;         // LED on Model A 

// the setup routine runs once when you press reset:
void setup() {
  pinMode(LEDpin, OUTPUT);
}

// the loop routine runs over and over again forever:
void loop() {
  unsigned long currentMillis = millis();
  
  if (randtime <= currentMillis) {
    fadeAmount = -fadeAmount;
    randtime = currentMillis + random(100, 1000);
  }

  if (fadetime <= currentMillis) {
    if (brightness <= 0 || brightness >= 255) {
      fadeAmount = -fadeAmount;
    }
    brightness = brightness + fadeAmount;
    fadetime = currentMillis + 2;
  }

  analogWrite(LEDpin, brightness);
}

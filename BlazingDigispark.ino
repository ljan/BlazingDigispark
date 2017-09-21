unsigned long randtime = millis();
unsigned long fadetime = millis();
int fadeAmount = 1;
int brightness = 128;
int LEDpin = 1;  //LED on Model A 

// the setup routine runs once when you press reset:
void setup()
{
  pinMode(LEDpin, OUTPUT);
}

// the loop routine runs over and over again forever:
void loop()
{
  if (randtime <= millis())
  {
    fadeAmount = -fadeAmount;
    randtime = millis() + random(100, 1000);
  }

  if (fadetime <= millis())
  {
    if (brightness <= 0 || brightness >= 255)
    {
      fadeAmount = -fadeAmount;
    }
    brightness = brightness + fadeAmount;
    fadetime = millis() + 2;
  }

  analogWrite(LEDpin, brightness);
}

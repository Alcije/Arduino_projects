// Petit test avec un bouton et la led de la carte.
// Le bouton est branche entre D2 et GND.

const int ledPin = 13;
const int buttonPin = 2;

void setup()
{
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP);
}

void loop()
{
  int buttonValue = digitalRead(buttonPin);

  if (buttonValue == LOW)
    digitalWrite(ledPin, HIGH);
  else
    digitalWrite(ledPin, LOW);
}

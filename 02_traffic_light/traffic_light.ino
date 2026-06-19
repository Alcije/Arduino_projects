// Feu tricolore simple.
// J'ai garde des temps assez longs pour bien voir les changements.

const int redLed = 2;
const int orangeLed = 3;
const int greenLed = 4;

void setup()
{
  pinMode(redLed, OUTPUT);
  pinMode(orangeLed, OUTPUT);
  pinMode(greenLed, OUTPUT);
}

void allOff()
{
  digitalWrite(redLed, LOW);
  digitalWrite(orangeLed, LOW);
  digitalWrite(greenLed, LOW);
}

void loop()
{
  allOff();
  digitalWrite(redLed, HIGH);
  delay(5000);

  allOff();
  digitalWrite(greenLed, HIGH);
  delay(5000);

  allOff();
  digitalWrite(orangeLed, HIGH);
  delay(1500);
}

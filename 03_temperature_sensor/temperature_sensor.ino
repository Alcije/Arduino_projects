// Lecture d'un capteur LM35 sur A0.
// Avec le LM35, 10 mV correspond a 1 degre C.

const int sensorPin = A0;

void setup()
{
  Serial.begin(9600);
}

void loop()
{
  int rawValue = analogRead(sensorPin);
  float voltage = rawValue * (5.0 / 1023.0);
  float tempC = voltage * 100.0;

  Serial.print("Temperature : ");
  Serial.print(tempC);
  Serial.println(" C");

  delay(1000);
}

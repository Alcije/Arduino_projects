// Thermostat avec DHT11 et relais.
// Le relais peut commander un petit ventilateur, pas directement du 220V.

#include <DHT.h>

#define DHTPIN 2
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);
const int relayPin = 3;
const float maxTemp = 25.0;

void setup()
{
  dht.begin();
  pinMode(relayPin, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  float temp = dht.readTemperature();

  if (isnan(temp))
  {
    Serial.println("Lecture impossible");
    delay(1000);
    return;
  }

  Serial.print("Temp : ");
  Serial.println(temp);

  if (temp > maxTemp)
    digitalWrite(relayPin, HIGH);
  else
    digitalWrite(relayPin, LOW);

  delay(1200);
}

// Petite station meteo avec DHT11.
// Led verte = temperature correcte, led rouge = trop chaud ou trop froid.

#include <DHT.h>

#define DHTPIN 2
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);
const int greenLed = 3;
const int redLed = 4;

void setup()
{
  dht.begin();
  pinMode(greenLed, OUTPUT);
  pinMode(redLed, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  float temp = dht.readTemperature();
  float humidity = dht.readHumidity();

  if (isnan(temp) || isnan(humidity))
  {
    Serial.println("Erreur DHT11");
    delay(1500);
    return;
  }

  Serial.print("Temperature : ");
  Serial.print(temp);
  Serial.print(" C  Humidite : ");
  Serial.print(humidity);
  Serial.println(" %");

  if (temp < 20 || temp > 28)
  {
    digitalWrite(redLed, HIGH);
    digitalWrite(greenLed, LOW);
  }
  else
  {
    digitalWrite(redLed, LOW);
    digitalWrite(greenLed, HIGH);
  }

  delay(1500);
}

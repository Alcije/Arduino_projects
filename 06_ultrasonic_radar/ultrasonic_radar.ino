// Detecteur de distance avec HC-SR04.
// La led s'allume si quelque chose passe trop pres.

const int trigPin = 9;
const int echoPin = 10;
const int ledPin = 13;

long readDistanceCm()
{
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  long duration = pulseIn(echoPin, HIGH, 25000);
  if (duration == 0)
    return 999;
  return duration * 0.034 / 2;
}

void setup()
{
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  long distance = readDistanceCm();

  Serial.print("Distance : ");
  Serial.print(distance);
  Serial.println(" cm");

  if (distance < 20)
    digitalWrite(ledPin, HIGH);
  else
    digitalWrite(ledPin, LOW);

  delay(150);
}

// Radar avec servo : le capteur ultrason regarde a gauche et a droite.
// Il affiche les distances dans le moniteur serie.

#include <Servo.h>

Servo headServo;

const int trigPin = 8;
const int echoPin = 9;

long getDistance()
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
  headServo.attach(10);
  Serial.begin(9600);
}

void loop()
{
  for (int angle = 30; angle <= 150; angle += 15)
  {
    headServo.write(angle);
    delay(250);

    Serial.print("Angle ");
    Serial.print(angle);
    Serial.print(" : ");
    Serial.print(getDistance());
    Serial.println(" cm");
  }

  for (int angle = 150; angle >= 30; angle -= 15)
  {
    headServo.write(angle);
    delay(250);
  }
}

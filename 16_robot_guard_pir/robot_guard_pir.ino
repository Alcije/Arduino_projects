// Robot gardien : il attend, puis reagit si le PIR detecte un mouvement.
// Ici il allume une led, sonne et tourne un peu pour faire "alerte".

#include <Servo.h>

Servo leftServo;
Servo rightServo;

const int pirPin = 2;
const int ledPin = 13;
const int buzzerPin = 8;

void stopRobot()
{
  leftServo.write(90);
  rightServo.write(90);
}

void setup()
{
  pinMode(pirPin, INPUT);
  pinMode(ledPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
  leftServo.attach(9);
  rightServo.attach(10);
  stopRobot();
}

void loop()
{
  if (digitalRead(pirPin) == HIGH)
  {
    digitalWrite(ledPin, HIGH);
    tone(buzzerPin, 900);
    leftServo.write(180);
    rightServo.write(180);
    delay(500);
    noTone(buzzerPin);
    stopRobot();
    delay(500);
  }
  else
  {
    digitalWrite(ledPin, LOW);
    noTone(buzzerPin);
    stopRobot();
  }
}

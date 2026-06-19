// Petit robot qui fait une mini danse et joue quelques sons.
// Utilise deux servos continus et un buzzer.

#include <Servo.h>

Servo leftServo;
Servo rightServo;
const int buzzerPin = 8;

void moveRobot(int leftValue, int rightValue, int timeMs)
{
  leftServo.write(leftValue);
  rightServo.write(rightValue);
  delay(timeMs);
}

void beep(int freq, int timeMs)
{
  tone(buzzerPin, freq);
  delay(timeMs);
  noTone(buzzerPin);
}

void setup()
{
  leftServo.attach(9);
  rightServo.attach(10);
  pinMode(buzzerPin, OUTPUT);
}

void loop()
{
  beep(440, 120);
  moveRobot(180, 0, 500);
  beep(660, 120);
  moveRobot(0, 180, 500);
  beep(520, 120);
  moveRobot(180, 180, 350);
  moveRobot(90, 90, 800);
}

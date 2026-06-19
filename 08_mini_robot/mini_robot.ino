// Petit robot avec deux servos a rotation continue.
// Valeur 90 = stop, plus haut/bas = rotation selon le servo.

#include <Servo.h>

Servo leftServo;
Servo rightServo;

void stopRobot()
{
  leftServo.write(90);
  rightServo.write(90);
}

void goForward()
{
  leftServo.write(180);
  rightServo.write(0);
}

void goBackward()
{
  leftServo.write(0);
  rightServo.write(180);
}

void setup()
{
  leftServo.attach(9);
  rightServo.attach(10);
  stopRobot();
  delay(1000);
}

void loop()
{
  goForward();
  delay(1800);

  stopRobot();
  delay(600);

  goBackward();
  delay(1000);

  stopRobot();
  delay(1000);
}

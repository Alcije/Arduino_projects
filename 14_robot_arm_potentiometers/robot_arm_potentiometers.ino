// Bras robotique simple avec deux servos et deux potentiometres.
// Potentiometre 1 = base, potentiometre 2 = bras.

#include <Servo.h>

Servo baseServo;
Servo armServo;

const int potBase = A0;
const int potArm = A1;

void setup()
{
  baseServo.attach(9);
  armServo.attach(10);
}

void loop()
{
  int baseValue = analogRead(potBase);
  int armValue = analogRead(potArm);

  int baseAngle = map(baseValue, 0, 1023, 0, 180);
  int armAngle = map(armValue, 0, 1023, 20, 160);

  baseServo.write(baseAngle);
  armServo.write(armAngle);

  delay(20);
}

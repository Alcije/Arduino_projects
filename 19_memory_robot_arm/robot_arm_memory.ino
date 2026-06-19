// Bras robotique avec memorisation simple.
// Un bouton enregistre la position, un autre rejoue la sequence.

#include <Servo.h>

Servo servoA;
Servo servoB;

const int potA = A0;
const int potB = A1;
const int saveButton = 2;
const int playButton = 3;

int posA[20];
int posB[20];
int savedCount = 0;

void setup()
{
  servoA.attach(9);
  servoB.attach(10);
  pinMode(saveButton, INPUT_PULLUP);
  pinMode(playButton, INPUT_PULLUP);
}

void moveByPots()
{
  int a = map(analogRead(potA), 0, 1023, 0, 180);
  int b = map(analogRead(potB), 0, 1023, 20, 160);

  servoA.write(a);
  servoB.write(b);
}

void savePosition()
{
  if (savedCount >= 20)
    return;

  posA[savedCount] = servoA.read();
  posB[savedCount] = servoB.read();
  savedCount++;
  delay(300);
}

void playSequence()
{
  for (int i = 0; i < savedCount; i++)
  {
    servoA.write(posA[i]);
    servoB.write(posB[i]);
    delay(700);
  }
}

void loop()
{
  moveByPots();

  if (digitalRead(saveButton) == LOW)
    savePosition();

  if (digitalRead(playButton) == LOW)
    playSequence();

  delay(20);
}

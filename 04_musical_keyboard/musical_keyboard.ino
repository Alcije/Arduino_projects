// Mini clavier avec trois boutons.
// Chaque bouton joue une note differente sur le buzzer.

const int buzzerPin = 8;
const int buttons[3] = {2, 3, 4};
const int notes[3] = {262, 294, 330}; // do, re, mi environ

void setup()
{
  pinMode(buzzerPin, OUTPUT);

  for (int i = 0; i < 3; i++)
    pinMode(buttons[i], INPUT_PULLUP);
}

void loop()
{
  int notePlayed = 0;

  for (int i = 0; i < 3; i++)
  {
    if (digitalRead(buttons[i]) == LOW)
    {
      tone(buzzerPin, notes[i]);
      notePlayed = 1;
    }
  }

  if (notePlayed == 0)
    noTone(buzzerPin);
}

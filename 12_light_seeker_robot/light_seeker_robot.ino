// Robot qui cherche la lumiere avec deux LDR.
// C'est volontairement simple : il va vers le cote le plus lumineux.

const int leftLdr = A0;
const int rightLdr = A1;
const int leftMotor = 5;
const int rightMotor = 6;

void setup()
{
  pinMode(leftMotor, OUTPUT);
  pinMode(rightMotor, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  int leftLight = analogRead(leftLdr);
  int rightLight = analogRead(rightLdr);
  int diff = leftLight - rightLight;

  Serial.print(leftLight);
  Serial.print("  ");
  Serial.println(rightLight);

  if (abs(diff) < 60)
  {
    analogWrite(leftMotor, 160);
    analogWrite(rightMotor, 160);
  }
  else if (diff > 0)
  {
    analogWrite(leftMotor, 80);
    analogWrite(rightMotor, 170);
  }
  else
  {
    analogWrite(leftMotor, 170);
    analogWrite(rightMotor, 80);
  }

  delay(80);
}

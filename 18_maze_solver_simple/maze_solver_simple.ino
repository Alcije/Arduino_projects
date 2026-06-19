// Robot labyrinthe version simple.
// Il applique une regle basique : si devant c'est bloque, il tourne a droite.
// A revoir pour optimiser.

const int trigPin = 8;
const int echoPin = 9;
const int leftMotor = 5;
const int rightMotor = 6;

long distanceCm()
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

void motors(int l, int r)
{
  analogWrite(leftMotor, l);
  analogWrite(rightMotor, r);
}

void setup()
{
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(leftMotor, OUTPUT);
  pinMode(rightMotor, OUTPUT);
}

void loop()
{
  long front = distanceCm();

  if (front > 18)
  {
    motors(160, 160);
  }
  else
  {
    motors(0, 0);
    delay(200);
    motors(170, 30);
    delay(550);
  }
}

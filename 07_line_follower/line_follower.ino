// Robot suiveur de ligne simple avec deux capteurs IR.
// A adapter selon les capteurs : parfois noir = LOW, parfois noir = HIGH.

const int leftSensor = 2;
const int rightSensor = 3;
const int leftMotor = 9;
const int rightMotor = 10;

const int normalSpeed = 180;
const int turnSpeed = 150;

void setup()
{
  pinMode(leftSensor, INPUT);
  pinMode(rightSensor, INPUT);
  pinMode(leftMotor, OUTPUT);
  pinMode(rightMotor, OUTPUT);
}

void drive(int leftSpeed, int rightSpeed)
{
  analogWrite(leftMotor, leftSpeed);
  analogWrite(rightMotor, rightSpeed);
}

void loop()
{
  int leftValue = digitalRead(leftSensor);
  int rightValue = digitalRead(rightSensor);

  if (leftValue == LOW && rightValue == LOW)
    drive(normalSpeed, normalSpeed);
  else if (leftValue == HIGH && rightValue == LOW)
    drive(0, turnSpeed);
  else if (leftValue == LOW && rightValue == HIGH)
    drive(turnSpeed, 0);
  else
    drive(0, 0);
}

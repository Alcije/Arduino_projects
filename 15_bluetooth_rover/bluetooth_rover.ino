// Rover Bluetooth simple.
// Module HC-05 sur Serial. Commandes : F B L R S.

const int leftMotor = 5;
const int rightMotor = 6;
const int normalSpeed = 180;

void motors(int leftSpeed, int rightSpeed)
{
  analogWrite(leftMotor, leftSpeed);
  analogWrite(rightMotor, rightSpeed);
}

void setup()
{
  pinMode(leftMotor, OUTPUT);
  pinMode(rightMotor, OUTPUT);
  Serial.begin(9600);
  motors(0, 0);
}

void loop()
{
  if (Serial.available() > 0)
  {
    char order = Serial.read();

    if (order == 'F')
      motors(normalSpeed, normalSpeed);
    else if (order == 'B')
      motors(80, 80); // selon le montage, il faudra peut-etre inverser les fils
    else if (order == 'L')
      motors(60, normalSpeed);
    else if (order == 'R')
      motors(normalSpeed, 60);
    else if (order == 'S')
      motors(0, 0);
  }
}

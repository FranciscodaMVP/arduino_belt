#include <ContinuousRotationServo.h>

ContinuousRotationServo Servo;
int distance;

void setup()
{
  Servo.begin(8);
}

void loop()
{
  Servo.rotateLeft(50,1);
  //Servo.noMovement(500);
  //Servo.rotateRight(50,100);
  //Servo.noMovement(500);
}

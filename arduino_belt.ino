
#include <Servo.h>
#include <ContinuousRotationServo.h>

// bandas
ContinuousRotationServo banda_izq;
ContinuousRotationServo banda_der;
int distance;


// bandas
int servo_ban_der = 6;
int servo_ban_izq = 7; 
Servo servo_der;
Servo servo_izq;  
int servoAngle = 0;   // servo position in degrees

//palancas
int servo_pal_der = 2;
int servo_pal_izq = 3;
Servo pal_izq;
Servo pal_der;
 
void setup()
{
  Serial.begin(9600);  
  servo_der.attach(servo_ban_der);
  servo_izq.attach(servo_ban_izq); 

  

}
 
void loop()
{
  //banda_izq.rotateRight(90,100);
  servo_der.write(45);      // Turn SG90 servo Left to 45 degrees
  servo_izq.write(45);      // Turn SG90 servo Left to 45 degrees  
}
 
void girar_pal_der()
{
   pal_der.write(0);      // Turn SG90 servo Left to 45 degrees
   delay(1000);          // Wait 1 second
   pal_der.write(180);      // Turn SG90 servo back to 90 degrees (center position)
   delay(1000);          // Wait 1 second
}

void girar_pal_izq()
{
   pal_izq.write(0);      // Turn SG90 servo Left to 45 degrees
   delay(1000);          // Wait 1 second
   pal_izq.write(180);      // Turn SG90 servo back to 90 degrees (center position)
   delay(1000);          // Wait 1 second
}


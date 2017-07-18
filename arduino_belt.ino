
#include <Servo.h>

// bandas
int servo_ban_der = 6;
int servo_ban_izq = 7; 
Servo servo_der;
Servo servo_izq;  
int servoAngle = 0;   // servo position in degrees

//palancas
int servo_pal_der = 2;
//int servo_pal_izq = 3;
Servo pal_izq;
Servo pal_der;

//ultra der
const int trigPin = 3;
const int echoPin = 4;
long duration;
int distance;

int aleatorio;

void setup()
{
  Serial.begin(9600);  
  servo_der.attach(servo_ban_der);
  servo_izq.attach(servo_ban_izq);
  servo_der.write(45); 

  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin, INPUT); // Sets the echoPin as an Input

  pal_der.attach(servo_pal_der);
  pal_der.write(0);
}
 
void loop()
{
  //banda_izq.rotateRight(90,100);
  //servo_der.write(45);      // Turn SG90 servo Left to 45 degrees
  //servo_izq.write(45);      // Turn SG90 servo Left to 45 degrees
  
  if (ultra_der()<3)
  {
    Serial.println("Checar");
    verificar();
  }
}

void verificar ()
{
  servo_der.detach();
  aleatorio = random(0,2);
  Serial.println(aleatorio);
  if  (aleatorio == 0)
  {
    
    girar_pal_der();
    servo_der.attach(servo_ban_der);
    //imprimir linea de no funciona y prender led
  }
  else{
    servo_der.attach(servo_ban_der);
    servo_der.write(45);
    // imprimir linea de si funciona
  }
}
 
void girar_pal_der()
{
   pal_der.write(180);      // Turn SG90 servo Left to 45 degrees
   delay(1000);          // Wait 1 second
   pal_der.write(0);      // Turn SG90 servo back to 90 degrees (center position)
   delay(1000);          // Wait 1 second
}

void girar_pal_izq()
{
   pal_izq.write(0);      // Turn SG90 servo Left to 45 degrees
   delay(1000);          // Wait 1 second
   pal_izq.write(180);      // Turn SG90 servo back to 90 degrees (center position)
   delay(1000);          // Wait 1 second
}

int ultra_der()
{
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);
  // Calculating the distance
  distance= duration*0.034/2;
  // Prints the distance on the Serial Monitor
  Serial.print("Distance: ");
  Serial.println(distance);
  delay(200);
  return distance;
}


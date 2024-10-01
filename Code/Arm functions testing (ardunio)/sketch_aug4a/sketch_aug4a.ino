/* Example sketch to control a stepper motor with 
   A4988/DRV8825 stepper motor driver and 
   Arduino without a library. 
   More info: https://www.makerguides.com */
#include <Servo.h>;

// Define stepper motor connections and steps per revolution:
#define dirPin 24
#define dirPin2 22
#define stepPin 8
#define stepPin2 9
#define elbowPin 11
#define gripPin 12
#define wristPin 10
#define stepsPerRevolution 200

Servo myservo;
Servo myservo2;
Servo myservo3;

void setup() {
  // Declare pins as output:
  pinMode(stepPin, OUTPUT);
  pinMode(dirPin, OUTPUT);
  pinMode(stepPin2, OUTPUT);
  pinMode(dirPin2, OUTPUT);
  myservo.attach(elbowPin);
    myservo2.attach(gripPin);
     myservo3.attach(wristPin);
}
void loop() {
  // Set the spinning direction clockwise:
 
 myservo.write(50);

  digitalWrite(dirPin, HIGH);
  digitalWrite(dirPin2, HIGH);

  // Spin the stepper motor 180*  slowly:
  for (int i = 0; i < 100; i++) {
    // These four lines result in 1 step:

  // myservo.write(i);

    // digitalWrite(stepPin, HIGH);
    // delayMicroseconds(14000);
    // digitalWrite(stepPin, LOW);
    // delayMicroseconds(14000);
    digitalWrite(stepPin2, HIGH);
    delayMicroseconds(14000);
    digitalWrite(stepPin2, LOW);
    delayMicroseconds(14000);
  }

  

  delay(1000);

  // Set the spinning direction counterclockwise:
  digitalWrite(dirPin, LOW);
  digitalWrite(dirPin2, LOW);

  // Spin the stepper motor 180* slow back otherway:
  for (int i = 0; i < 100; i++) {
    // These four lines result in 1 step:

      // myservo.write(100 - i);

    // digitalWrite(stepPin, HIGH);
    // delayMicroseconds(14000);
    // digitalWrite(stepPin, LOW);
    // delayMicroseconds(14000);
    digitalWrite(stepPin2, HIGH);
    delayMicroseconds(14000);
    digitalWrite(stepPin2, LOW);
    delayMicroseconds(14000);
  }
  delay(1000);
  }

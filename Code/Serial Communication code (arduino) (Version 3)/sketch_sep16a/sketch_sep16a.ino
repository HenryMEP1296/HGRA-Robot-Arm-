/* Example sketch to control a stepper motor with 
   A4988/DRV8825 stepper motor driver and 
   Arduino without a library. 
   More info: https://www.makerguides.com */
#include <Servo.h>;

// Define stepper motor connections and steps per revolution:
#define dirPin 3
#define dirPin2 2
#define stepPin 5
#define stepPin2 6
#define elbowPin 9
#define gripPin 11
#define wristPin 10
#define stepsPerRevolution 200

Servo myservo;
Servo myservo2;
Servo myservo3;

String controllerValues = ""; // main controller varibles that will updated 
                              // a whole string at a time (important)
int angle; // servo var

int curangle; 

void setup() {
  Serial.begin(115200);
  // Declare pins as output:
  // pinMode(stepPin, OUTPUT);
  // pinMode(dirPin, OUTPUT);
  // pinMode(stepPin2, OUTPUT);
  // pinMode(dirPin2, OUTPUT);
  // myservo.attach(elbowPin);
    myservo2.attach(gripPin);
    //  myservo3.attach(wristPin);
}

void loop() {

char cData; // each chracter 
  String rawData = ""; // string that will update by each new chracter
  if (Serial.available()) // if something is in serial
  {
    delay(20); // wait a little bit for more characters to arrive
    while(Serial.available()) // look for all characters in the input buffer
    {
      cData = Serial.read(); // reading each individual character
      rawData.concat(cData); // adding each character to an overall string called rawData
    }
      controllerValues = rawData; // updating controllervalue global varible everytime rawData is read
      
  }

  servoDiggerControls();
 delay(3);

    myservo2.write(curangle);// writing teh received values on the servo

 Serial.println(curangle);



  // Set the spinning direction clockwise:
 
//  myservo.write(50);

//   digitalWrite(dirPin, HIGH);
//   digitalWrite(dirPin2, HIGH);

//   // Spin the stepper motor 180*  slowly:
//   for (int i = 0; i < 100; i++) {
//     // These four lines result in 1 step:

//   // myservo.write(i);

//     // digitalWrite(stepPin, HIGH);
//     // delayMicroseconds(14000);
//     // digitalWrite(stepPin, LOW);
//     // delayMicroseconds(14000);
//     digitalWrite(stepPin2, HIGH);
//     delayMicroseconds(14000);
//     digitalWrite(stepPin2, LOW);
//     delayMicroseconds(14000);
//   }

  

//   delay(1000);

//   // Set the spinning direction counterclockwise:
//   digitalWrite(dirPin, LOW);
//   digitalWrite(dirPin2, LOW);

//   // Spin the stepper motor 180* slow back otherway:
//   for (int i = 0; i < 100; i++) {
//     // These four lines result in 1 step:

//       // myservo.write(100 - i);

//     // digitalWrite(stepPin, HIGH);
//     // delayMicroseconds(14000);
//     // digitalWrite(stepPin, LOW);
//     // delayMicroseconds(14000);
//     digitalWrite(stepPin2, HIGH);
//     delayMicroseconds(14000);
//     digitalWrite(stepPin2, LOW);
//     delayMicroseconds(14000);
//   }
//   delay(1000);
  }

  void servoDiggerControls() {
    angle = controllerValues.toInt(); // converting string values to int
    // Serial.println(angle);

  if(curangle > 170 || curangle < 10) { // condition to see if 
    if(curangle > 170) {
      curangle = 170;
    } else if (curangle < 10) {
      curangle = 10;
    }
  } else if(angle > 3) {
   curangle = curangle + 1;
  } else if (angle < -3) {
   curangle = curangle - 1;

  } else {
    curangle = curangle;
  }

  }
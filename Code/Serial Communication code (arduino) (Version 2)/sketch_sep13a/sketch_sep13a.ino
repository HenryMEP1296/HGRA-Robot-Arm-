#include <Servo.h>; // including servo library

String controllerValues = ""; // main controller varibles that will updated 
                              // a whole string at a time (important)
int angle; // servo var

int curangle; 
int leftStick;
int rightStick;
int circle;
int sq;
int l1;
int r1;
int r2;

Servo gripper; // servo object
Servo elbow;

void setup() {
  // put your setup code here, to run once:
 Serial.begin(115200); // increasing the speed of communication by having higher baud rate
   gripper.attach(11); // attaching the servo
   elbow.attach(9);
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
   int leftStick = controllerValues.substring(0, 1).toInt(); // assigning controller values from teh overall string
   int rightStick = controllerValues.substring(1, 2).toInt();
   int r2 = map(controllerValues.substring(2, 3).toInt(), 0, 9, 30, 170);
   int l1 = controllerValues.substring(3, 4).toInt();
   int r1 = controllerValues.substring(4, 5).toInt();
   int circle = controllerValues.substring(5, 6).toInt();
   int sq = controllerValues.substring(6, 7).toInt();

  //  angle = controllerValues.toInt(); // converting string values to int
    // Serial.println(angle);

   angle = rightStick;

  if(curangle > 170 || curangle < 10) {
    if(curangle > 170) {
      curangle = 170;
    } else if (curangle < 10) {
      curangle = 10;
    }
  } else if(angle > 5) {
   curangle = curangle + 1;
  } else if (angle < 3) {
   curangle = curangle - 1;

  } else {
    curangle = curangle;
  }

  elbow.write(curangle);

  if(leftStick != 0) {

//   Serial.print(leftStick);
//   Serial.print("-");
//   Serial.print(rightStick);
//   Serial.print("-");
//   Serial.print(r2);
//    Serial.print("-");
//   Serial.print(l1);
//  Serial.print("-");
//   Serial.print(r1);
//  Serial.print("-");
//   Serial.print(circle);
//  Serial.print("-");
//   Serial.println(sq);



  }
  // Serial.println("-");
    gripper.write(r2);// writing teh received values on the servo
 
 delay(3);
}

#include <Servo.h>; // including servo library


#define stepsPerRevolution 200
#define dirPin 2
#define dirPin2 3
#define stepPin 5
#define stepPin2 6

String controllerValues = ""; // main controller varibles that will updated 
                              // a whole string at a time (important)
int angle; // servo var

int curangle = 50; // initalising the servo posiont in startup, waiting for controller program
int leftStick = 4; // intisliaing the left stick value
int rightStick;
int circle;
int sq;
int l1;
int r1;
int r2 = 10; // intialising gripper startup psotion to being fully open

Servo gripper; // servo object
Servo elbow;

void setup() {

   pinMode(stepPin2, OUTPUT); // declaring the step and dir pins for each stepperimage.png
  pinMode(dirPin2, OUTPUT);
     pinMode(stepPin, OUTPUT);
  pinMode(dirPin, OUTPUT);
  // put your setup code here, to run once:
 Serial.begin(115200); // increasing the speed of communication by having higher baud rate
   gripper.attach(11); // attaching the servo
   elbow.attach(9);
   
  //  delay(2000);
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
 if (controllerValues != 0) { // guard clause if data from the controller is actually being recieved


   int leftStick = controllerValues.substring(0, 1).toInt(); // assigning controller values from teh overall string
   int rightStick = controllerValues.substring(1, 2).toInt();
   int r2 = map(controllerValues.substring(2, 3).toInt(), 0, 9, 30, 170);
   int l1 = controllerValues.substring(3, 4).toInt();
   int r1 = controllerValues.substring(4, 5).toInt();
   int circle = controllerValues.substring(5, 6).toInt();
   int sq = controllerValues.substring(6, 7).toInt();

  //  angle = controllerValues.toInt(); // converting string values to int
    // Serial.println(angle);

  // servoDiggerControls(); // function call

  angle = rightStick; // comparitive varible is right stick value

  if(curangle > 170 || curangle < 10) { // chechking if cur angle exceeds servo rotation limit
    if(curangle > 170) { // if yes at max
      curangle = 170; // rotation stays at 170
    } else if (curangle < 10) { // if yes at min
      curangle = 10; // rotation stays at 10
    }
  } else if(angle > 5) { // if it is within range, control stick is up (greater than 5)
   curangle = curangle + 1; // then add one degree to curangle
  } else if (angle < 3) { //if within range, control stick is down (less than 3)
   curangle = curangle - 1; // then subtract a degree from curangle

  } else { // if stick is stationary or otehr value
    curangle = curangle; //curangle doesnt change (servo stays stationary)
  }

  elbow.write(curangle); // write this curangle varible that is being adapted to servo

// if(leftStick != 0) { 
   if(leftStick > 5) { // if the left stick is up

    digitalWrite(dirPin2, HIGH); // Choosing the direction

   digitalWrite(stepPin2, HIGH); // Turn on the step pin
    delayMicroseconds(16000); // Dealy of step speed
    digitalWrite(stepPin2, LOW); // Turn off the step pin
    delayMicroseconds(16000); // delay of step speed

  } else if(leftStick < 3) { if left stick is down

      digitalWrite(dirPin2, LOW); // OPposite direction to the other oneimage.png

    digitalWrite(stepPin2, HIGH);
    delayMicroseconds(16000);
    digitalWrite(stepPin2, LOW);
    delayMicroseconds(16000);
  }
  // }

  if(l1 == 1 && r1 == 1) { // if both buttons are pressed at same time
   // do nothing
  } else { // else if both arent
    if (l1 == 1) {
         digitalWrite(dirPin, HIGH);

   digitalWrite(stepPin, HIGH); // take a step on base stepper
    delayMicroseconds(8000);  // faster speed
    digitalWrite(stepPin, LOW);
    delayMicroseconds(8000);
    } else if (r1 == 1) {
          digitalWrite(dirPin, LOW);

   digitalWrite(stepPin, HIGH); // 
    delayMicroseconds(8000); // faster speed
    digitalWrite(stepPin, LOW);
    delayMicroseconds(8000);
    }
  }


  



//   }
  // Serial.println("-");
    gripper.write(r2);// writing teh received values on the servo
 
 delay(3); // delay per each degree

 } else {
  gripper.write(0);
  elbow.write(50);
 }
}

// void servoDiggerControls() {
//   angle = rightStick; // comparitive varible is right stick value

//   if(curangle > 170 || curangle < 10) { // chechking if cur angle exceeds servo rotation limit
//     if(curangle > 170) { // if yes at max
//       curangle = 170; // rotation stays at 170
//     } else if (curangle < 10) { // if yes at min
//       curangle = 10; // rotation stays at 10
//     }
//   } else if(angle > 5) { // if it is within range, control stick is up (greater than 5)
//    curangle = curangle + 1; // then add one degree to curangle
//   } else if (angle < 3) { //if within range, control stick is down (less than 3)
//    curangle = curangle - 1; // then subtract a degree from curangle

//   } else { // if stick is stationary or otehr value
//     curangle = curangle; //curangle doesnt change (servo stays stationary)
//   }

//   elbow.write(curangle); // write this curangle varible that is being adapted to servo
// }

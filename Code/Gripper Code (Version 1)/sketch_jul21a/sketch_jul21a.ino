#import <Servo.h>;

Servo myservoL;
Servo myservoR;

int leftAngleClose = 150; // left max
int leftAngleOpen = 75; // left min

int rightAngleClose = 60; // right max
int rightAngleOpen = 135; // right min

int maxClawGap = 72; // max gap in mm

void setup() {
  // put your setup code here, to run once:
myservoL.attach(9);
myservoR.attach(10); // attahcing servos
Serial.begin(9600);// declaring serial comms

}

void loop() {
  // put your main code here, to run repeatedly:

//  for(int i = 0; i <= 100; i++) { // loop 0 - 100 simulating consistant movement

//  servoRotateOnPercent(i); // enter the desired percentage of claw closure here (data from HT)

//    Serial.print(percentToMm(i)); // printing claw gap
//  Serial.println(" mm gap bettwen claws");
//   delay(20);
//  }
//  for(int i = 100; i >= 0; i--) { // loop 100 - 0 simulating consistant movement

//  servoRotateOnPercent(i); // enter the desired percentage of claw closure here (data from HT)

//   Serial.print(percentToMm(i)); // printing claw gap
//  Serial.println(" mm gap bettwen claws");
//   delay(20);
//  }


servoRotateOnPercent(100); // enter the desired percentage of claw closure here (data from HT)

 Serial.print(percentToMm(100)); // printing claw gap
 Serial.println(" mm gap bettwen claws");
}

void servoRotateOnPercent(int percent) {
int curAngleR = map(percent, 0, 100, rightAngleOpen, rightAngleClose); // mapping % to R angle (making sure Open is min value as it is right servo)
int curAngleL = map(percent, 0, 100, leftAngleOpen, leftAngleClose); // mapping % to L angle (making sure close is min value as it is left servo)
myservoR.write(curAngleR); // rotating servo R to corrosponding angle
myservoL.write(curAngleL);// rotating servo L to corrosponding angle

}

int percentToMm(int percent) {
 return map(percent, 0, 100, maxClawGap, 0); // mapping percent to claw gap 
}

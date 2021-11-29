#include <Stepper.h>
#include <Servo.h>

int stepsPerRevolution = 400;
int motSpeed = 50;
int SensorPin = 23; 
int in1Pin = 22;
int in2Pin = 6;
int in3Pin = 7;
int in4Pin = 8;
int sensorState = 0, lastState = 0;
int MicroswitchPin = A5; //Microswitch Pin read
int MicroswitchState = digitalRead(MicroswitchPin);
int i=1;
int Ra1Pos=49;

Stepper Ra1Stepper (stepsPerRevolution, 22,6,7,8);
Servo Ra2Servo;
Servo Ra3Servo;
Servo StabilServo;
Servo GripCrankServo;

void setup() {
  
Ra1Stepper.setSpeed(motSpeed);
pinMode(in1Pin, OUTPUT);
pinMode(in2Pin, OUTPUT);
pinMode(in3Pin, OUTPUT);
pinMode(in4Pin,OUTPUT);

pinMode(MicroswitchPin, INPUT); //microswitch pin Output
digitalWrite(MicroswitchPin, HIGH); //Output normal high reading from Ms

pinMode(SensorPin, INPUT);
digitalWrite(SensorPin, HIGH);

Ra2Servo.attach(5);

Ra3Servo.attach(4);

StabilServo.attach(2);

GripCrankServo.attach(3);

Serial.begin(9600);
}

void loop() {
 sensorState = digitalRead(SensorPin);

 //Home The Stepper
 while (MicroswitchState == HIGH) { //initial honing
 Ra1Stepper.step(10);
 delay(10);
 }
Ra1Stepper.step(-100); //beginning zeroing homing

 //1
 Ra1Pos = Ra1Pos; //+step change
Ra1Stepper.step(Ra1Pos);
Ra2Servo.write(59);
Ra3Servo.write(78);
StabilServo.write(132);
delay(10);
if (sensorState == LOW) {
  GripCrankServo.write(0);
 Place();
 } 

//2
Ra1Pos = Ra1Pos-12; //+step change
Ra1Stepper.step(-12);
Ra2Servo.write(46);
Ra3Servo.write(105);
StabilServo.write(119);
delay(10);
if (sensorState == LOW) {
  GripCrankServo.write(0);
 Place();
 } 
 
//3
 Ra1Pos = Ra1Pos-7; //+step change
Ra1Stepper.step(-7);
Ra2Servo.write(25);
Ra3Servo.write(151);
StabilServo.write(94);
delay(10);
if (sensorState == LOW) {
  GripCrankServo.write(0);
 Place();
 } 

//4
Ra1Pos = Ra1Pos-11; //+step change
Ra1Stepper.step(-11);
Ra2Servo.write(34);
Ra3Servo.write(129);
StabilServo.write(105);
delay(10);
if (sensorState == LOW) {
  GripCrankServo.write(0);
 Place();
 } 
//5
Ra1Pos = Ra1Pos+5; //+step change
Ra1Stepper.step(5);
Ra2Servo.write(52);
Ra3Servo.write(90);
StabilServo.write(126);
delay(10);
if (sensorState == LOW) {
  GripCrankServo.write(0);
 Place();
 } 

 //6
 Ra1Pos = Ra1Pos+10; //+step change
Ra1Stepper.step(10);
Ra2Servo.write(67);
Ra3Servo.write(64);
StabilServo.write(139);
delay(10);
if (sensorState == LOW) {
  GripCrankServo.write(0);
 Place();
 } 

//7
Ra1Pos = Ra1Pos-22; //+step change
Ra1Stepper.step(-22);
Ra2Servo.write(71);
Ra3Servo.write(56);
StabilServo.write(142);
delay(10);
if (sensorState == LOW) {
  GripCrankServo.write(0);
 Place();
 } 

//8
Ra1Pos = Ra1Pos-4; //+step change
Ra1Stepper.step(-4);
Ra2Servo.write(56);
Ra3Servo.write(84);
StabilServo.write(129);
delay(10);
if (sensorState == LOW) {
  GripCrankServo.write(0);
 Place();
 } 

//9
Ra1Pos = Ra1Pos-2; //+step change
Ra1Stepper.step(-2);
Ra2Servo.write(38);
Ra3Servo.write(122);
StabilServo.write(110);
delay(10);
if (sensorState == LOW) {
  GripCrankServo.write(0);
 Place();
 } 

 //10
Ra1Pos = Ra1Pos-12; //+step change
Ra1Stepper.step(-12);
Ra2Servo.write(38);
Ra3Servo.write(122);
StabilServo.write(110);
delay(10);
if (sensorState == LOW) {
  GripCrankServo.write(0);
 Place();
 } 

//11
Ra1Pos = Ra1Pos-2; //+step change
Ra1Stepper.step(-2);
Ra2Servo.write(56);
Ra3Servo.write(84);
StabilServo.write(129);
delay(10);
if (sensorState == LOW) {
  GripCrankServo.write(0);
 Place();
 } 

//12
Ra1Pos = Ra1Pos-4; //+step change
Ra1Stepper.step(-4);
Ra2Servo.write(71);
Ra3Servo.write(56);
StabilServo.write(142);
delay(10);
if (sensorState == LOW) {
  GripCrankServo.write(0);
 Place();
 } 

  //13
   Ra1Pos = Ra1Pos-22; //+step change
Ra1Stepper.step(-22);
Ra2Servo.write(67);
Ra3Servo.write(64);
StabilServo.write(139);
delay(10);
if (sensorState == LOW) {
  GripCrankServo.write(0);
 Place();
 } 

//14
Ra1Pos = Ra1Pos+10; //+step change
Ra1Stepper.step(10);
Ra2Servo.write(52);
Ra3Servo.write(90);
StabilServo.write(126);
delay(10);
if (sensorState == LOW) {
  GripCrankServo.write(0);
 Place();
 } 

//15
Ra1Pos = Ra1Pos+5; //+step change
Ra1Stepper.step(5);
Ra2Servo.write(34);
Ra3Servo.write(129);
StabilServo.write(105);
delay(10);
if (sensorState == LOW) {
  GripCrankServo.write(0);
 Place();
}

//16
Ra1Pos = Ra1Pos-11; //+step change
Ra1Stepper.step(-11);
Ra2Servo.write(25);
Ra3Servo.write(151);
StabilServo.write(94);
delay(10);
if (sensorState == LOW) {
  GripCrankServo.write(0);
 Place();
 } 

//17
Ra1Pos = Ra1Pos-7; //+step change
Ra1Stepper.step(-7);
Ra2Servo.write(46);
Ra3Servo.write(105);
StabilServo.write(119);
delay(10);
if (sensorState == LOW) {
  GripCrankServo.write(0);
 Place();
 } 

//18
Ra1Pos = Ra1Pos-12; //+step change
Ra1Stepper.step(-12);
Ra2Servo.write(59);
Ra3Servo.write(78);
StabilServo.write(132);
delay(10);
if (sensorState == LOW) {
  GripCrankServo.write(0);
 Place();
 } 
}

void Place() {

if(i==1){
  
 while (MicroswitchState == HIGH) { //initial honing
 Ra1Stepper.step(10);
 delay(10);
 }

Ra1Stepper.setSpeed(motSpeed);//go to dropoff
Ra1Stepper.step(-344);
Ra2Servo.write(90);
Ra3Servo.write(30);
StabilServo.write(113);

GripCrankServo.write(135);//drop payload
delay(100);
GripCrankServo.write(45);

Ra1Stepper.setSpeed(motSpeed);//go back to hone to dropoff
Ra1Stepper.step(334);

 while (MicroswitchState == HIGH) { //final honing
 Ra1Stepper.step(10);
 delay(10);
 }
 Ra1Stepper.step(-100);//return to "zero"
Ra1Stepper.step(Ra1Pos);
 i=i+1;     // make the function go to the second hole next time
 return;   // exit funciton and re-enter code
 }

 

else if(i==2){
  while (MicroswitchState == HIGH) { //initial honing
 Ra1Stepper.step(10);
 delay(10);
 }

Ra1Stepper.setSpeed(motSpeed);//go to dropoff
Ra1Stepper.step(-310);
Ra2Servo.write(90);
Ra3Servo.write(9);
StabilServo.write(159);

GripCrankServo.write(135);//drop payload
delay(100);
GripCrankServo.write(45);

Ra1Stepper.setSpeed(motSpeed);//go back to hone to dropoff
Ra1Stepper.step(300);

 while (MicroswitchState == HIGH) { //final honing
 Ra1Stepper.step(10);
 delay(10);
 }
 Ra1Stepper.step(-100);//return to "zero"
 Ra1Stepper.step(Ra1Pos);

 i=i+1;     // make the function go to the second hole next time
 return;   // exit funciton and re-enter code
}




else if(i==3){
  while (MicroswitchState == HIGH) { //initial honing
 Ra1Stepper.step(10);
 delay(10);
 }

Ra1Stepper.setSpeed(motSpeed);//go to dropoff
Ra1Stepper.step(-285);
Ra2Servo.write(90);
Ra3Servo.write(42);
StabilServo.write(83);

GripCrankServo.write(135);//drop payload
delay(100);
GripCrankServo.write(45);

Ra1Stepper.setSpeed(motSpeed);//go back to hone to dropoff
Ra1Stepper.step(260);

 while (MicroswitchState == HIGH) { //final honing
 Ra1Stepper.step(10);
 delay(10);
 }
 Ra1Stepper.step(-100);//return to "zero"
Ra1Stepper.step(Ra1Pos);
 i=i+1;     // make the function go to the second hole next time
 return;   // exit funciton and re-enter code
}




else if(i==4){
  while (MicroswitchState == HIGH) { //initial honing
 Ra1Stepper.step(10);
 delay(10);
 }

Ra1Stepper.setSpeed(motSpeed);//go to dropoff
Ra1Stepper.step(-271);
Ra2Servo.write(81);
Ra3Servo.write(47);
StabilServo.write(83);

GripCrankServo.write(135);//drop payload
delay(100);
GripCrankServo.write(45);

Ra1Stepper.setSpeed(motSpeed);//go back to hone to dropoff
Ra1Stepper.step(260);

 while (MicroswitchState == HIGH) { //final honing
 Ra1Stepper.step(10);
 delay(10);
 }
 Ra1Stepper.step(-100);//return to "zero"
 Ra1Stepper.step(Ra1Pos);

 i=i+1;     // make the function go to the second hole next time
  while (1==1)
    {
  // WAIT FOR BUTTON TO RESTART
    }
 }
}

#include <Servo.h>
#include <Stepper.h>
#define GROUND_JOY_PIN3 A12            //joystick ground pin will connect to Arduino analog pin A12
#define VOUT_JOY_PIN3 A11              //joystick +5 V pin will connect to Arduino analog pin A11
#define Y2JOY_PIN A14                  //X axis reading from joystick4 will go into analog pin A14
#define GROUND_JOY_PIN2 A9            //joystick ground pin will connect to Arduino analog pin A9
#define VOUT_JOY_PIN2 A8              //joystick +5 V pin will connect to Arduino analog pin A8
#define X2JOY_PIN A13                  //X axis reading from joystick3 will go into analog pin A13
#define GROUND_JOY_PIN1 A6            //joystick ground pin will connect to Arduino analog pin A6
#define VOUT_JOY_PIN1 A5              //joystick +5 V pin will connect to Arduino analog pin A5
#define Y1JOY_PIN A4                  //X axis reading from joystick2 will go into analog pin A4
#define GROUND_JOY_PIN A1            //joystick ground pin will connect to Arduino analog pin A3
#define VOUT_JOY_PIN A2              //joystick +5 V pin will connect to Arduino analog pin A2
#define X1JOY_PIN A3                  //X axis reading from joystick will go into analog pin A1
#define STEPS 400

int potState = 0; 
Stepper Ra1Stepper (STEPS, 22,6,7,8);

Servo RAservo2;
Servo RAservo3;
Servo Gservo1;
Servo Gservo2;

int RAservo2_pin = 5;
int RAservo3_pin = 4;  
int Gservo1_pin = 2;  
int Gservo2_pin = 3;  

int initial_position2 = 90;
int initial_position3 = 90;
int initial_positionG = 90;
int initial_positionG2 = 90;

void setup() {

 Serial.begin(9600);
 pinMode(VOUT_JOY_PIN, OUTPUT);    //pin A3 shall be used as output
 pinMode(GROUND_JOY_PIN, OUTPUT);  //pin A2 shall be used as output
 digitalWrite(VOUT_JOY_PIN, HIGH); //set pin A3 to high (+5V)
 digitalWrite(GROUND_JOY_PIN,LOW); //set pin A3 to low (ground)

pinMode(VOUT_JOY_PIN1, OUTPUT);    //pin A3 shall be used as output
 pinMode(GROUND_JOY_PIN1, OUTPUT);  //pin A2 shall be used as output
 digitalWrite(VOUT_JOY_PIN1, HIGH); //set pin A3 to high (+5V)
 digitalWrite(GROUND_JOY_PIN1,LOW); //set pin A3 to low (ground)

 pinMode(VOUT_JOY_PIN2, OUTPUT);    //pin A3 shall be used as output
 pinMode(GROUND_JOY_PIN2, OUTPUT);  //pin A2 shall be used as output
 digitalWrite(VOUT_JOY_PIN2, HIGH); //set pin A3 to high (+5V)
 digitalWrite(GROUND_JOY_PIN2,LOW); //set pin A3 to low (ground)

 pinMode(VOUT_JOY_PIN3, OUTPUT);    //pin A3 shall be used as output
 pinMode(GROUND_JOY_PIN3, OUTPUT);  //pin A2 shall be used as output
 digitalWrite(VOUT_JOY_PIN3, HIGH); //set pin A3 to high (+5V)
 digitalWrite(GROUND_JOY_PIN3,LOW); //set pin A3 to low (ground)
 
RAservo2.attach (RAservo2_pin ) ; 
RAservo3.attach (RAservo3_pin ) ; 
Gservo1.attach (Gservo1_pin ) ; 
Gservo2.attach (Gservo2_pin ) ;

RAservo2.write (initial_position2);
RAservo3.write (initial_position3);
Gservo1.write (initial_positionG);
Gservo2.write (initial_positionG2);

pinMode(A0,INPUT);
  
}
 
void loop()
{
 delay(100); 
                                  //      this whole section controls the servos with three axese of the joysticks
 int joystickXVal = analogRead(X1JOY_PIN) ;  //read joystick input on pin A3
 RAservo2.write((joystickXVal+520)/10);      //write the calculated value to the servo  

 int joystickXVal2 = analogRead(Y1JOY_PIN) ;  //read joystick input on pin A4
 RAservo3.write((joystickXVal2+520)/10);      //write the calculated value to the servo

 int joystickXVal3 = analogRead(X2JOY_PIN) ;  //read joystick input on pin A13
 Gservo1.write((joystickXVal3+520)/10);      //write the calculated value to the servo

                                //      this whole section controls the Stepper with one axese of the joysticks
int potState = analogRead(Y2JOY_PIN); //reads the values from the potentiometers
  Ra1Stepper.setSpeed(5);
 

  if (potState > 600){  //all code below controls movement of stepper
    Ra1Stepper.step(10);
  }
  
  if (potState < 400){
    Ra1Stepper.step(-10);
  }

                                     //      this whole section controls the Actuator Servo

 if(digitalRead(A0)==LOW){
    Gservo2.write(180);
  }
  else
  {  
    Gservo2.write(0);
  }
  
}

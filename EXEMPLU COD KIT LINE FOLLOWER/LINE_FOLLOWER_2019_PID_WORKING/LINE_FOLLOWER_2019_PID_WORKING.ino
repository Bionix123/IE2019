#include <QTRSensors.h> //last modified 13.06.2019


float Kp = 0.038;// 0.032 cu rl200speed 140base
float Kd = 0.015; // valori
float lastMillis; //timer loop
float lastMillis1; // timer absBrake
#define Ki 0
#define brakeSpeed 0
#define rightMaxSpeed 230 // max speed 
#define leftMaxSpeed 230 // max speed 
#define rightBaseSpeed 140// viteza dreapta
#define leftBaseSpeed 140// viteza stanga
#define TIMEOUT       2500// timeout
#define EMITTER_PIN   2// nvm
#define NUM_SENSORS   6  // numar senzori
#define NUM_SAMPLES_PER_SENSOR  1 // do not touch


//---------------CONEXIUNI DRIVER-------------
#define rightMotor1 8
#define rightMotor2 7
#define rightMotorPWM 9
#define leftMotor1 4
#define leftMotor2 5
#define leftMotorPWM 3
#define motorPower 6
int lastError;
int positionPID;
int integrala = 0;
int start = 0;
QTRSensorsAnalog qtra((unsigned char[]) {14, 15, 16, 17, 18, 19}, NUM_SENSORS, NUM_SAMPLES_PER_SENSOR); //6 senzori
//-------------------------------SETUP-----------------------
void setup()
{
    int i;
    for (int i = 0; i < 100; i++)
    qtra.calibrate(); //calibrare 
    delay(20);
    wait();  
    delay(2000);
  Serial.begin(9600);
  pinMode(rightMotor1, OUTPUT);
  pinMode(rightMotor2, OUTPUT);
  pinMode(rightMotorPWM, OUTPUT);
  pinMode(leftMotor1, OUTPUT);
  pinMode(leftMotor2, OUTPUT);
  pinMode(leftMotorPWM, OUTPUT);
  pinMode(motorPower, OUTPUT);
  Serial.begin(9600);
  } 
  

//------------------------------------PID LINE FOLLOW-------------------------------------------
  void lineFollowPID(){
  int motor1dir=1;
  int motor2dir=1;
  unsigned int sensorValues[NUM_SENSORS];
  unsigned int sensors[6];
  int position = qtra.readLine(sensorValues);
  int error = position - 2500;
  if(error >= 2500){ move(1,leftMaxSpeed-35,1); move(0,brakeSpeed,0);} //brake
  else if(error <= -2500){ move(1,brakeSpeed,0); move(0,rightMaxSpeed-35,1);}
  else{
  //Serial.print(error);
  //Serial.println();
  integrala = integrala + error;
  int motorSpeed = Kp * error + Kd * (error - lastError) + Ki*integrala;
   /*Serial.print("error=");
  Serial.print(error);
  Serial.print("  ||  mspeed=");
  Serial.print(motorSpeed);
  Serial.print("  ||  lastErr=");
  Serial.print(error-lastError);
  Serial.println();*/
  lastError = error;
  int rightMotorSpeed = rightBaseSpeed + motorSpeed;
  int leftMotorSpeed = leftBaseSpeed - motorSpeed;
  if (rightMotorSpeed > rightMaxSpeed ) rightMotorSpeed = rightMaxSpeed; // limita viteza RIGHT
  if (leftMotorSpeed > leftMaxSpeed ) leftMotorSpeed = leftMaxSpeed; // limita viteza LEFT
  if (rightMotorSpeed < 0) rightMotorSpeed = 0; motor1dir=0;// limita >= 0
  if (leftMotorSpeed < 0) leftMotorSpeed = 0; motor2dir=0;// limita >=0
  if(rightMotorSpeed>0) motor1dir=1; // inverseaza directia
  if(leftMotorSpeed>0) motor2dir=1; // inverseaza directia
 
  if(motor1dir=1){
  digitalWrite(motorPower, HIGH); // >
  digitalWrite(rightMotor1, HIGH);
  digitalWrite(rightMotor2, LOW);
  analogWrite(rightMotorPWM, rightMotorSpeed);
  }
  else
  {
  digitalWrite(motorPower, HIGH); // <
  digitalWrite(rightMotor1, LOW);
  digitalWrite(rightMotor2, HIGH);
  analogWrite(rightMotorPWM, rightMotorSpeed); 
  }
  
  if(motor2dir=1){ // >
  digitalWrite(motorPower, HIGH);
  digitalWrite(leftMotor1, HIGH);
  digitalWrite(leftMotor2, LOW);
  analogWrite(leftMotorPWM, leftMotorSpeed);
  }
  else
  {
  digitalWrite(motorPower, HIGH); // <
  digitalWrite(leftMotor1, LOW);
  digitalWrite(leftMotor2, HIGH);
  analogWrite(leftMotorPWM, leftMotorSpeed);
  }
  }
}
//---------------------------------LOOP---------------------------------

void loop(){

  //Serial.println(digitalRead(13));
  do{
  lineFollowPID();
  if(digitalRead(11)==0 && millis() - lastMillis > 500){
    lastMillis=millis();
    start++;
  }
  }while(true);
  move(0,0,0);
  move(1,0,0);
// Kp = Kd/5;
// lineFollowPID();
// if(digitalRead(11)==0 && (millis() - lastMillis > 500)){
//  lastMillis = millis();
//  Kd=Kd+0.01;
// }
// Serial.print("Kd=");
// Serial.print(Kd);
// Serial.print("  Kp=");
// Serial.print(Kp);
// Serial.println();
// 
 }
 
  
//----------------------------------MOVE--------------------------------
void move(int motor, int speed, int direction) //doc driver
{
//speed: 0-255
//direction: 0 clockwise, 1 counter-clockwise

  digitalWrite(motorPower, HIGH); //disable standby

  boolean inPin1 = LOW;
  boolean inPin2 = HIGH;

  if(direction == 1)
  {
    inPin1 = HIGH;
    inPin2 = LOW;
  }

  if(motor == 1)
  {
    digitalWrite(rightMotor1, inPin1);
    digitalWrite(rightMotor2, inPin2);
    analogWrite(rightMotorPWM, speed);
  }
  else
  {
    digitalWrite(leftMotor1, inPin1);
    digitalWrite(leftMotor2, inPin2);
    analogWrite(leftMotorPWM, speed);
  }
}  
void wait(){
    digitalWrite(motorPower, LOW);
  }

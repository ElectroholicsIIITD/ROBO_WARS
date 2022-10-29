#include <Servo.h>
char Incoming_value=0;
int servopos=90; //angle for servo motor
int servo_rest=0; //angle for servo when at rest
int motorSpeed=255; // motor speed
int mL_1=2;   // in1 of L298n -> pin 2 of arduino
int mL_2=3;   // in2 of L298n -> pin 3 of arduino
int mR_1=4;   // in3 of L298n -> pin 4 of arduino
int mR_2=5;   // in4 of L298n -> pin 5 of arduino
int mL_speedpin=9;  // EnA of l298N -> pin 9 of arduino
int mR_speedpin=10; // EnB of l298n -> pin 10 of arduino
int servopin=11;
char front='1'; // character's assighned to each motion recived from bluetooth module
char right='4';
char back='2';
char left='3';
char servo='E';
//int calloff=13;
char pausee='9';
int led=6;
// l-> 1
// r-> 2
Servo myservo;
void forwardmotion(int motor_pin1,int motor_pin2,int speedpin) // this functuon decide motion of a motor(clockwise)
{
  
  analogWrite(speedpin,motorSpeed);
  digitalWrite(motor_pin1,HIGH);
  digitalWrite(motor_pin2,LOW);
  
}


void backwardmotion(int motor_pin1,int motor_pin2,int speedpin) // this functuon decide motion of a motor(anticlockwise)
{
  
  analogWrite(speedpin,motorSpeed);
  digitalWrite(motor_pin1,LOW);
  digitalWrite(motor_pin2,HIGH);
  
}


void forward(int motor1_1,int motor1_2,int motor2_1,int motor2_2,int speedpin1,int speedpin2) // this function moves bot in forward direction
{
  
  forwardmotion(motor1_1,motor1_2,speedpin1);
  forwardmotion(motor2_1,motor2_2,speedpin2);
  
}


void backward(int motor1_1,int motor1_2,int motor2_1,int motor2_2,int speedpin1,int speedpin2) // this function moves bot in backward direction
{
  
  backwardmotion(motor1_1,motor1_2,speedpin1);
  backwardmotion(motor2_1,motor2_2,speedpin2);
  
}


void leftward(int motor1_1,int motor1_2,int motor2_1,int motor2_2,int speedpin1,int speedpin2) // this function moves bot in leftward direction
{
  
  //backwardmotion(motor1_1,motor1_2,speedpin1);
  forwardmotion(motor2_1,motor2_2,speedpin2);
  
}


void rightward(int motor1_1,int motor1_2,int motor2_1,int motor2_2,int speedpin1,int speedpin2) // this function moves bot in rightward direction
{
  
  forwardmotion(motor1_1,motor1_2,speedpin1);
  //backwardmotion(motor2_1,motor2_2,speedpin2);
  
}

void pause(int motor1_1,int motor1_2,int motor2_1,int motor2_2,int speedpin1,int speedpin2)
{
  digitalWrite(motor1_1,LOW);
  digitalWrite(motor1_2,LOW);
  analogWrite(speedpin1,0);
  digitalWrite(motor2_1,LOW);
  digitalWrite(motor2_2,LOW);
  analogWrite(speedpin2,0);
  
}


void setup() 
{
  Serial.begin(9600);         
  pinMode(mL_1,OUTPUT);
  pinMode(mL_2,OUTPUT);
  pinMode(mR_1,OUTPUT);
  pinMode(mR_2,OUTPUT);
  pinMode(mL_speedpin,OUTPUT);
  pinMode(mR_speedpin,OUTPUT);
  pinMode(servopin,OUTPUT);
  //pinMode(calloff,INPUT);
  pinMode(led,OUTPUT);
  myservo.attach(servopin);
  myservo.write(servo_rest);
}
void loop()
{
  if(Serial.available() > 0)  
  {
    Incoming_value = Serial.read();      
    Serial.print(Incoming_value);       
    Serial.print("\n");       
    if(Incoming_value == front)            
      forward(mL_1,mL_2,mR_1,mR_2,mL_speedpin,mR_speedpin); 
    else if(Incoming_value == back)      
      backward(mL_1,mL_2,mR_1,mR_2,mL_speedpin,mR_speedpin);   
    else if(Incoming_value == left)      
      leftward(mL_1,mL_2,mR_1,mR_2,0,255); 
    else if(Incoming_value == right)      
      rightward(mL_1,mL_2,mR_1,mR_2,255,0); 
    else if (Incoming_value == pausee)
      pause(mL_1,mL_2,mR_1,mR_2,mL_speedpin,mR_speedpin); 
    else if(Incoming_value == servo)
      myservo.write(servopos);
      delay(750);
      myservo.write(servo_rest);
    
  }                            
 
}                 

#include <Servo.h>

int lft_1=2;
int lft_2=3;
int rght_1=4;
int rght_2=5;
int lsp=9;
int rsp=10;
int servopin=11;
char front='1'; 
char right='3';
char back='2';
char left='4';
char servo='5';
int servopos=90; 
int servo_rest=0;
char Incoming_value;

Servo myservo;

void clockwise(int motor_1,int motor_2,int motorsp,int rpm)
{
  digitalWrite(motor_1,HIGH);
  digitalWrite(motor_2,LOW);
  analogWrite(motorsp,rpm);
}
void anticlockwise(int motor_1,int motor_2,int motorsp,int rpm)
{
  digitalWrite(motor_1,LOW);
  digitalWrite(motor_2,HIGH);
  analogWrite(motorsp,rpm);
}
void Forward(int lft_1,int lft_2,int rght_1,int rght_2,int lsp,int rsp)
{
    int rpm=255;
    clockwise(lft_1,lft_2,lsp,rpm);
    clockwise(rght_1,rght_2,rsp,rpm);
}
void Backward(int lft_1,int lft_2,int rght_1,int rght_2,int lsp,int rsp)
{
    int rpm=255;
    anticlockwise(lft_1,lft_2,lsp,rpm);
    anticlockwise(rght_1,rght_2,rsp,rpm);
}
void Leftward(int lft_1,int lft_2,int rght_1,int rght_2,int lsp,int rsp)
{
    int rpm=255;
    clockwise(rght_1,rght_2,rsp,rpm);
    clockwise(lft_1,lft_2,lsp,0);
}
void Rightward(int lft_1,int lft_2,int rght_1,int rght_2,int lsp,int rsp)
{
    int rpm=255;
    clockwise(lft_1,lft_2,lsp,rpm);
    clockwise(rght_1,rght_2,rsp,0);
}
void setup() 
{
    pinMode(lft_1,OUTPUT);
    pinMode(lft_2,OUTPUT);
    pinMode(rght_1,OUTPUT);
    pinMode(rght_2,OUTPUT);
    pinMode(lsp,OUTPUT);
    pinMode(lsp,OUTPUT);
    pinMode(servopin,OUTPUT);
    myservo.attach(servopin);
    myservo.write(servo_rest);
    Serial.begin(9600);
}

void loop() 
{
    if(Serial.available() > 0)  
  {
    Incoming_value = Serial.read();      
    Serial.print(Incoming_value);       
    Serial.print("\n");
    if(Incoming_value== front)
        Forward(lft_1,lft_2,rght_1,rght_2,lsp,rsp);
    else if(Incoming_value== left)
        Leftward(lft_1,lft_2,rght_1,rght_2,lsp,rsp);
    else if(Incoming_value== right)
        Rightward(lft_1,lft_2,rght_1,rght_2,lsp,rsp);
    else if(Incoming_value== back)
        Backward(lft_1,lft_2,rght_1,rght_2,lsp,rsp);
    else if(Incoming_value == servo)
        myservo.write(servopos);
        delay(750);
        myservo.write(servo_rest); 
  }

}

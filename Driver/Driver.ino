///////////////////////////////////////////////////////////////////////////////////////////
//
// ALA library example: RgbStripSerial
//
// Example to demonstrate how to control WS2812 RGB LED strip lighting and animations
// sending AT commands through the serial port.
//
// Web page: http://yaab-arduino.blogspot.com/p/ala-example-rgbstripserial.html
//
///////////////////////////////////////////////////////////////////////////////////////////


#include <stdlib.h>

#define CMDBUFSIZE 16   // buffer size for receiving serial commands

char cmdBuffer[CMDBUFSIZE];
int motionCmd= 212;
float brightness = 0.3;
int paletteId=0;
long duration = 5000;
int palette=0;
int speed=3;

int IN1=3;    
int IN2=4;    
int IN3=5;    
int IN4=7;

const int trig=9;
const int echo=10;
int vcc=8;
int pinBuzzer = 11; //管脚D3连接到蜂鸣器模块的信号脚  

void setup()
{
  Serial.begin(9600);
  
  Serial.println("Welcome to ALA RgbStripSerial example");
  Serial.println("A=[animation code] Set the animation. See https://github.com/bportaluri/ALA/blob/master/src/AlaLed.h");
  Serial.println("B=[brightness]     Set the brightness [0-100]");
  Serial.println("D=[speed]       Set the duration in milliseconds of the animation cycle");
  Serial.println("C=[color]          Set the color (hexadecimal RGB representation ex. 0xE8A240)");
  Serial.println("P=[palette]        Set the palette.");
  //driver
  pinMode(IN1,OUTPUT);
  pinMode(IN2,OUTPUT);
  pinMode(IN3,OUTPUT);
  pinMode(IN4,OUTPUT);
  //Alarm system
  pinMode(echo,INPUT);
  pinMode(trig,OUTPUT);
  pinMode(pinBuzzer, OUTPUT); //设置pinBuzzer脚为输出状态
  pinMode(vcc,OUTPUT);
}

void loop()
{
  Alarm();
  if (Serial.available())
  {
    int charsRead;
    charsRead = Serial.readBytesUntil('\n', cmdBuffer, sizeof(cmdBuffer) - 1);  //read entire line
    cmdBuffer[charsRead] = '\0';       // Make it a C string
    Serial.print("Sail >"); Serial.println(cmdBuffer);

    if(cmdBuffer[1] != '=' || strlen(cmdBuffer)<3)
    {
      Serial.println("KO");
    }
    else
    {
      switch(toupper(cmdBuffer[0]))
      {
      case 'A':
        motionCmd = atoi(&cmdBuffer[2]);
        break;
//      case 'B':
//        brightness = atoi(&cmdBuffer[2]);
//        Serial.println("OK");
//        break;
//      case 'C':
////        color = strtol(&cmdBuffer[2], 0, 16);
////        palette=alaPalNull;
//        Serial.println("OK");
//        break;
      case 'D':
        speed = atol(&cmdBuffer[2]);
        Serial.println("OK");
        break;
//      case 'P':
//        paletteId = atoi(&cmdBuffer[2]);
//        switch(paletteId)
//        {
//        case 0:
//          palette=0;
//          break;
//        case 1:
//          palette=1;
//          break;
//        case 2:
//          palette=2;
//          break;
//        case 3:
//          palette=3;
//          break;
//        case 4:
//          palette=4;
//          break;
//        case 5:
//          palette=5;
//          break;
//        case 6:
//          palette=6;
//          break;
//        }
//        break;
//
      default:
        Serial.println("KO");
      }
  }
}
speed=int(speed);
MotionService(speed);
}
bool isStart=true;
int lastCmd=211;
void MotionService(int speed){
        switch(motionCmd){
          case 102://left
            TurnLeft(speed);
            break;
          case 302://right
            TurnRight(speed);
            break;
          case 211://up
            Forward(speed);
            break;
          case 213://down
            Backward(speed);
            break;
          case 212://start/stop
            if(isStart){
              Stop();
            }else{
              motionCmd=lastCmd;
            }
            break;
          default:
            break;
        }

}


void TurnRight(int speed){
  if(speed!=1||2||3){
    speed=3;
  }else;
  int Vollevel=int((HIGH/3)*speed);
  digitalWrite(IN1,Vollevel);
  digitalWrite(IN2,LOW);
  digitalWrite(IN3,Vollevel);
  digitalWrite(IN4,LOW);
  isStart=true;
  lastCmd=motionCmd;
  motionCmd=0;
  Serial.println("Yellow smart car turn left");
}

void TurnLeft(int speed){
  if(speed!=1||2||3){
    speed=3;
  }else;
  int Vollevel=int((HIGH/3)*speed);
  digitalWrite(IN1,LOW);
  digitalWrite(IN2,Vollevel);
  digitalWrite(IN3,LOW);
  digitalWrite(IN4,Vollevel);
    isStart=true;
  lastCmd=motionCmd;
  motionCmd=0;
  Serial.println("Yellow smart car turn right");
}

void Forward(int speed){
  if(speed!=1||2||3){
    speed=3;
  }else;
  int Vollevel=int((HIGH/3)*speed);
  digitalWrite(IN1,LOW);
  digitalWrite(IN2,Vollevel);
  digitalWrite(IN3,Vollevel);
  digitalWrite(IN4,LOW);
    isStart=true;
  lastCmd=motionCmd;
  motionCmd=0;
  Serial.println("Yellow smart car Motion forward");
}

void Backward(int speed){
  if(speed!=1||2||3){
    speed=3;
  }else;
  int Vollevel=int((HIGH/3)*speed);
  digitalWrite(IN1,Vollevel);
  digitalWrite(IN2,LOW);
  digitalWrite(IN3,LOW);
  digitalWrite(IN4,Vollevel);
    isStart=true;
  lastCmd=motionCmd;
  motionCmd=0;
  Serial.println("Yellow smart car Motion backword");
}

void Stop(){
  digitalWrite(IN1,LOW);
  digitalWrite(IN2,LOW);
  digitalWrite(IN3,LOW);
  digitalWrite(IN4,LOW);
  isStart=false;
  motionCmd=0;
  Serial.println("Yellow smart car stoped");
}


void Alarm(){
  digitalWrite(vcc,HIGH);
  float instantDistance=distance();
  buzzer(instantDistance);
}


void buzzer(float instantDistance){
  
   long frequency = 500; //频率, 单位Hz  
   long dur=instantDistance*5;
   if(instantDistance<20.00){
      //用tone()函数发出频率为frequency的波形  
      tone(pinBuzzer, frequency,dur);  
      delay(dur); //等待1000毫秒  
      noTone(pinBuzzer);//停止发声  
   }else;  
}

float distance(){
  long IntervalTime=0;
  digitalWrite(trig,1);
  delayMicroseconds(15);
  digitalWrite(trig,0);
  IntervalTime=pulseIn(echo,HIGH);
  float S=IntervalTime/58.00;
  if(S<3300.00){
    Serial.println(S);
    float instantDistance = S;
    S=0;
    delay(50);
    return instantDistance;
  }else;
}



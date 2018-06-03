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
int motionCmd= 0;
float brightness = 0.3;
int paletteId=0;
long duration = 5000;
int palette=0;

void setup()
{
  Serial.begin(9600);
  
  Serial.println("Welcome to ALA RgbStripSerial example");
  Serial.println("A=[animation code] Set the animation. See https://github.com/bportaluri/ALA/blob/master/src/AlaLed.h");
  Serial.println("B=[brightness]     Set the brightness [0-100]");
  Serial.println("D=[duration]       Set the duration in milliseconds of the animation cycle");
  Serial.println("C=[color]          Set the color (hexadecimal RGB representation ex. 0xE8A240)");
  Serial.println("P=[palette]        Set the palette.");
}

void loop()
{

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
        switch(motionCmd){
          case 102://left

            Serial.println("Yellow smart car turn left");
            break;
          case 302://right
            Serial.println("Yellow smart car turn right");
            break;
          case 211://up
            Serial.println("Yellow smart car Motion forward");
            break;
          case 213://down
            Serial.println("Yellow smart car Motion backword");
            break;
          default:
            Serial.println("Error Motion Command");
            break;
        }
        
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
//      case 'D':
//        duration = atol(&cmdBuffer[2]);
//        Serial.println("OK");
//        break;
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
}



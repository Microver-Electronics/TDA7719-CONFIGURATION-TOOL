#include "TDA7719.h"
#include <Wire.h>

// CHANGE THE I2C PINS BELOW, FIND THE RIGHT PINS FOR YOUR BOARD (we mainly worked on an STM32 board so this is why we used PB pins, you can use it with any board)
#define PIN_SDA PB7
#define PIN_SCL PB6

TDA7719 tda;

uint8_t received_msg[21];

void setup() 
{
  Wire.setSDA(PIN_SDA);
  Wire.setSCL(PIN_SCL);
  Wire.begin();
  
  Serial.begin(115200);
  delay(10);
  Serial.println("Microver RCU configuration tool example ON.");
}

void loop() 
{
  if(Serial.available() >= 21) // Here we are receiving the raw register data for TDA7719 audio processor.
  {
    for(int i=0; i<21; i++)
    {
      int j = Serial.read();
      if(j != -1){
          received_msg[i] = (uint8_t)j;
      }
      else{
        Serial.println("WARNING: Missed a byte!");
      }
    } 
    Serial.println("Received configuration from GUI.");
    
    send_configuration();
  }
}

void send_configuration()
{
  tda.sendConfig(received_msg); // This is the function that we added to the library. We have to send 21 bytes of data, otherwise won't work.
  Serial.println("Config sent.");
}

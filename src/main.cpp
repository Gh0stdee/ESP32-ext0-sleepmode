#include <Arduino.h>

#define sleepPin 4

void blink()                                                  //builtin LED blink for half a second
{
  digitalWrite(LED_BUILTIN,1); 
  delay(500);                                                //keeping the LED on for half a second
  digitalWrite(LED_BUILTIN,0);
}

void setup() 
{
  pinMode(sleepPin, INPUT_PULLDOWN);                         //configure sleepPin to be input and default low    
  blink();                                                   //signaling the ESP32 is on
  esp_sleep_enable_ext0_wakeup((gpio_num_t)sleepPin,1);      //wake up ESP32 when reading on sleepPin is high
  delay(1000);                                               //prevent ESP32 going to sleep immediately after waking up
  esp_deep_sleep_start();                                    //enter deep sleep mode
}

void loop()                                                  //No code in loop as waking up after deep sleep will enter setup()
{ 
  
}
/* 
 * MAIN LOOP
 * 
 * THIS PROGRAM WILL POWER ANDY
*/



////////////////////////////////////////////////////////////////////////
////////////////////////   RGB LED STUFF   /////////////////////////////
////////////////////////////////////////////////////////////////////////

#include <Adafruit_NeoPixel.h>
#include "WS2812_Definitions.h"

#define PIN 4
#define LED_COUNT 2   // Be sure to subtract 1 from actual number since ADDRESS begins from ZERO


#define COUNTER_MAX 255 // Check against this value for UPPER limit of State Machine
#define COUNTER_MIN 0   // Check against this value for LOWER limit of State Machine
#define UP 1
#define DOWN -1

byte counter = 0;
char direction = UP;

Adafruit_NeoPixel leds = Adafruit_NeoPixel(LED_COUNT, PIN, NEO_GRB + NEO_KHZ800);   // Create an instance of NeoPixel class



////////////////////////////////////////////////////////////////////////
////////////////////////   MOTOR DRIVER STUFF   ////////////////////////
////////////////////////////////////////////////////////////////////////



////////////////////////////////////////////////////////////////////////
////////////////////////   PIEZO SPEAKER STUFF   ///////////////////////
////////////////////////////////////////////////////////////////////////





void setup()
{

  Serial.begin(9600);



/*

*****************************************
*************** TONE STUFF **************
* ***************************************
  tone(5, 100);
  delay(100);
  tone(5, 100);
  delay(100);
  tone(5, 400);

  noTone(5);

***********************************
*/



}




void loop()
{

    leds.setPixelColor(0, 0, 0, counter);
    leds.setPixelColor(1, 0, counter, 0);
    leds.show();   
    delay(10);


    counter += direction;
    if ( COUNTER_MAX == counter )
      direction = DOWN;
    else if ( COUNTER_MIN == counter )
      direction = UP;


    
}

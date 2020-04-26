/* Edge Lit LED Sign Code (Super Make Something Episode 22: https://youtu.be/kjWepTJXwxw)
 * by: Alex - Super Make Something
 * date: April 22nd, 2020
 * license: Creative Commons - Attribution - Non-Commercial. More information available at: http://creativecommons.org/licenses/by-nc/3.0/
 */

/* This code contains the following functions:
 * - void setup(): initializes LEDs
 * - void loop(): main loop
 * - void fire(): adjusts the RGB color values of the "fire" LED strand
 */

/* Pinout:
 * - LED Vin: pin VCC
 * - LED Gnd: pin GND
 * - Fire LED Dinn: pin 3
 * - Dumpster LED Din: pin 6
 */

#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
  #include <avr/power.h>
#endif

#define PIN_DUMPSTER 6
#define PIN_FIRE 3

Adafruit_NeoPixel stripDumpster = Adafruit_NeoPixel(6, PIN_DUMPSTER, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel stripFire = Adafruit_NeoPixel(6, PIN_FIRE, NEO_GRB + NEO_KHZ800);

void setup() // Initialize LED strips
{
  stripDumpster.begin();
  stripDumpster.setBrightness(255);
  for(int i=0; i<5; i++)
  {
    stripDumpster.setPixelColor(i, stripDumpster.Color(0,255,255));
  }
  stripDumpster.show(); // Initialize all pixels to 'off'
  stripFire.begin();
  stripFire.setBrightness(255);  
}

void loop() // Main loop
{
  fire();
}

void fire()
{
  for(int g=0; g<100; g++) // Increase green channel of RGB color value from 0 to 100
  {
    for(int i=0; i<5; i++)
    {
      stripFire.setPixelColor(i, stripFire.Color(255,g,0)); // Update color for every RGB LED in the strand
    }
    stripFire.show();  // Show change
    delay(50); // Pause
  }

  for(int g=100; g>0; g--) // Decrease green channel of RGB color value from 100 to 0
  {
    for(int i=0; i<5; i++)
    {
      stripFire.setPixelColor(i, stripFire.Color(255,g,0)); // Update color for every RGB LED in the strand
    }
    stripFire.show(); // Show change
    delay(50); // Pause
  }
}

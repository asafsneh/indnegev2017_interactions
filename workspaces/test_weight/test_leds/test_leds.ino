// NeoPixel Ring simple sketch (c) 2013 Shae Erisson
// released under the GPLv3 license to match the rest of the AdaFruit NeoPixel library

#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
  #include <avr/power.h>
#endif

// Which pin on the Arduino is connected to the NeoPixels?
// On a Trinket or Gemma we suggest changing this to 1
#define MISGERET_PIN              12//3

#define SMALL_KANAF_TOP_LEFT_PIN               12//4

#define BIG_KANAF_PIN                5


// How many NeoPixels are attached to the Arduino?
#define NUMPIXELS      59

#define MISGERET_NUMPIXELS      221
#define SMALL_KANAF_NUMPIXELS      59
#define BIG_KANAF_NUMPIXELS      25


// kanaf1 + 2  Misgeret = 121 leds --> PIN 2 --> A & B
// kanaf_top_left PIN 4

// When we setup the NeoPixel library, we tell it how many pixels, and which pin to use to send signals.
// Note that for older NeoPixel strips you might need to change the third parameter--see the strandtest
// example for more information on possible values.
Adafruit_NeoPixel MISGERET_PIXELS = Adafruit_NeoPixel(MISGERET_NUMPIXELS, MISGERET_PIN, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel SMALL_KANAF_PIXELS = Adafruit_NeoPixel(SMALL_KANAF_NUMPIXELS, SMALL_KANAF_TOP_LEFT_PIN, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel BIG_KANAF_PIXELS = Adafruit_NeoPixel(BIG_KANAF_NUMPIXELS, BIG_KANAF_PIN, NEO_GRB + NEO_KHZ800);


int delayval = 10; // delay for half a second

void setup() {
  // This is for Trinket 5V 16MHz, you can remove these three lines if you are not using a Trinket
#if defined (__AVR_ATtiny85__)
  if (F_CPU == 16000000) clock_prescale_set(clock_div_1);
#endif
  // End of trinket special code

  MISGERET_PIXELS.begin(); // This initializes the NeoPixel library.
  SMALL_KANAF_PIXELS.begin(); // This initializes the NeoPixel library.
  BIG_KANAF_PIXELS.begin(); // This initializes the NeoPixel library.
  turn_off();
  
}

void loop() {

  // For a set of NeoPixels the first NeoPixel is 0, second is 1, all the way up to the count of pixels minus one.
  for(int i=0;i<200;i++){
    // pixels.Color takes RGB values, from 0,0,0 up to 255,255,255
    MISGERET_PIXELS.setPixelColor(i, MISGERET_PIXELS.Color(0,0,255)); // Moderately bright green color.
    SMALL_KANAF_PIXELS.setPixelColor(i, SMALL_KANAF_PIXELS.Color(0,0,255)); // Moderately bright green color.
    BIG_KANAF_PIXELS.setPixelColor(i, BIG_KANAF_PIXELS.Color(0,0,255)); // Moderately bright green color.

    MISGERET_PIXELS.show(); 
    SMALL_KANAF_PIXELS.show(); 
    BIG_KANAF_PIXELS.show(); 

    delay(delayval); // Delay for a period of time (in milliseconds).

  }
}




void turn_off() {
    for(int i=0;i<200;i++){
    // pixels.Color takes RGB values, from 0,0,0 up to 255,255,255
    MISGERET_PIXELS.setPixelColor(i, MISGERET_PIXELS.Color(0,0,0)); // Moderately bright green color.
    SMALL_KANAF_PIXELS.setPixelColor(i, SMALL_KANAF_PIXELS.Color(0,0,0)); // Moderately bright green color.
    BIG_KANAF_PIXELS.setPixelColor(i, BIG_KANAF_PIXELS.Color(0,0,0)); // Moderately bright green color.

    MISGERET_PIXELS.show(); 
    SMALL_KANAF_PIXELS.show(); 
    BIG_KANAF_PIXELS.show(); 

    delay(delayval); // Delay for a period of time (in milliseconds).

  }
}

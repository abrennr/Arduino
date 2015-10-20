#include <Adafruit_NeoPixel.h>

#define PIN_1 6
#define PIN_2 10
#define PIN_3 12
 

// Parameter 1 = number of pixels in strip
// Parameter 2 = Arduino pin number (most are valid)
// Parameter 3 = pixel type flags, add together as needed:
//   NEO_KHZ800  800 KHz bitstream (most NeoPixel products w/WS2812 LEDs)
//   NEO_KHZ400  400 KHz (classic 'v1' (not v2) FLORA pixels, WS2811 drivers)
//   NEO_GRB     Pixels are wired for GRB bitstream (most NeoPixel products)
//   NEO_RGB     Pixels are wired for RGB bitstream (v1 FLORA pixels, not v2)
Adafruit_NeoPixel strip_1 = Adafruit_NeoPixel(16, PIN_1, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel strip_2 = Adafruit_NeoPixel(16, PIN_2, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel strip_3 = Adafruit_NeoPixel(16, PIN_3, NEO_GRB + NEO_KHZ800);

uint32_t red = strip_1.Color(255, 0, 0);
uint32_t yellow = strip_2.Color(255, 255, 0);
uint32_t green = strip_3.Color(0, 255, 0);


void setup() {
  // top (red) light
  strip_1.begin();
  strip_1.show(); 
  // middle (yellow) light
  strip_2.begin();
  strip_2.show(); 
  // bottom (green) light
  strip_3.begin();
  strip_3.show(); 
}

void loop() {
  // at each cycle, turn off non-displaying lights first to 
  // avoid double-lighting.
  
  // start with green
  colorFill_1(strip_1.Color(0, 0, 0)); 
  colorFill_2(strip_2.Color(0, 0, 0)); 
  colorFill_3(green); 
  delay(4000);
  // yellow
  colorFill_1(strip_1.Color(0, 0, 0)); 
  colorFill_3(strip_3.Color(0, 0, 0));
  colorFill_2(yellow);  
  delay(2000);
  // red
  colorFill_3(strip_3.Color(0, 0, 0)); 
  colorFill_2(strip_2.Color(0, 0, 0));
  colorFill_1(red); 
  delay(4000);

}


// Fill the dots all at once with a color
void colorFill_1(uint32_t c) {
  for(uint16_t i=0; i<strip_1.numPixels(); i++) {
    strip_1.setPixelColor(i, c);
    
  }
  strip_1.show();
}

void colorFill_2(uint32_t c) {
  for(uint16_t i=0; i<strip_2.numPixels(); i++) {
    strip_2.setPixelColor(i, c);
    
  }
  strip_2.show();
}

void colorFill_3(uint32_t c) {
  for(uint16_t i=0; i<strip_3.numPixels(); i++) {
    strip_3.setPixelColor(i, c);
    
  }
  strip_3.show();
}

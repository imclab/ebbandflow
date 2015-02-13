#include <Adafruit_NeoPixel.h>

#define PINONE 2
#define PINTWO 3
#define PINTHREE 4
#define PINFOUR 5
#define PINFIVE 7

Adafruit_NeoPixel stripOne = Adafruit_NeoPixel(110, PINONE, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel stripTwo = Adafruit_NeoPixel(80, PINTWO, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel stripThree = Adafruit_NeoPixel(80, PINTHREE, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel stripFour = Adafruit_NeoPixel(80, PINFOUR, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel stripFive = Adafruit_NeoPixel(110, PINFIVE, NEO_GRB + NEO_KHZ800);

uint32_t stripLengths[5][2] = {
                          {0, 108},
                          {0, 78},
                          {0, 77},
                          {0, 76},
                          {0, 110}
};

uint32_t white = stripOne.Color(255, 255, 255);
uint32_t magenta = stripOne.Color(255, 255, 255);
uint32_t blue = stripOne.Color(0, 0, 255);
uint32_t limeGreen = stripOne.Color(68, 214, 44);
uint32_t lightBlue = stripOne.Color(60, 132, 202);
uint32_t warmRed = stripOne.Color(249, 66, 58);
uint32_t yellow = stripOne.Color(255, 217, 0);
uint32_t purple = stripOne.Color(255, 70, 255);
uint32_t pink = stripOne.Color(252, 174, 187);
uint32_t grey = stripOne.Color(158, 151, 142);
uint32_t brown = stripOne.Color(134, 109, 75);
uint32_t umber = stripOne.Color(227, 82, 5);
uint32_t paleBlue = stripOne.Color(200, 216, 235);
uint32_t green = stripOne.Color(0, 177, 64);
uint32_t orange = stripOne.Color(253, 141, 28);



const int totalColors = 5;

uint32_t colors[totalColors] = {
  purple,
  orange,
  paleBlue,
  white,
  umber
};


void setup() {  
  stripOne.begin();
  stripTwo.begin();
  stripThree.begin();
  stripFour.begin();
  stripFive.begin();

  stripOne.show(); 
  stripThree.show();
  stripFour.show();
  stripFive.show(); 
}

void loop() {
 
   colorWipeOne(purple); 
   colorWipeTwo(orange); 
   colorWipeThree(paleBlue);
   colorWipeFour(white);
   colorWipeFive(umber);

   //colorCycle(3000);

   // stripFive.setPixelColor(108, white);
   // stripFive.show();

  
}


void colorWipeOne(uint32_t c) {
  for(uint16_t i = stripLengths[0][0]; i < stripLengths[0][1]; i++) {
      stripOne.setPixelColor(i, c);
  }
  stripOne.show();
}

void colorWipeTwo(uint32_t c) {
  for(uint16_t i = stripLengths[1][0]; i < stripLengths[1][1]; i++) {
      stripTwo.setPixelColor(i, c);
  }
  stripTwo.show();
}

void colorWipeThree(uint32_t c) {
  for(uint16_t i = stripLengths[2][0]; i < stripLengths[2][1]; i++) {
      stripThree.setPixelColor(i, c);
  }
  stripThree.show();
}

void colorWipeFour(uint32_t c) {
  for(uint16_t i = stripLengths[3][0]; i < stripLengths[3][1]; i++) {
      stripFour.setPixelColor(i, c);
  }
  stripFour.show();
}

void colorWipeFive(uint32_t c) {
  for(uint16_t i = stripLengths[4][0]; i < stripLengths[4][1]; i++) {
      stripFive.setPixelColor(i, c);
  }
  stripFive.show();
      
}

void colorPush(uint32_t wait) {
  bool keepGoing = true;

  for(int i = 0; i < totalColors; i++)


}

// void colorBlendOne(uint32_t wait) {
//   bool keepGoing = true;
//   int r1 = 255;
//   int g1 = 70;
//   int b1 = 255;

//   for(int i = stripLengths[0][0]; i < stripLengths[0][1]; i++) {
//       stripOne.setPixelColor(i, r1, g1, b1);
//   }
//   stripOne.show();


// }

void colorCycle(uint32_t wait) {
    bool keepGoing = true;

    for(int i = 0; i < totalColors; i++) {
      colorWipeOne(colors[i]); 
      colorWipeTwo(colors[i]); 
      colorWipeThree(colors[i]);
      colorWipeFour(colors[i]);
      colorWipeFive(colors[i]);
      delay(wait); 
         
      if(i > totalColors) {
        i = 0;
      }

    }

}

void rainbow(uint8_t wait) {
  uint16_t i, j;

  for(j=0; j<256; j++) {
    for(i=0; i<stripOne.numPixels(); i++) {
      stripOne.setPixelColor(i, Wheel((i+j) & 255));
    }
    stripOne.show();
    delay(wait);
  }
}

// Slightly different, this makes the rainbow equally distributed throughout
void rainbowCycle(uint8_t wait) {
  uint16_t i, j;

  for(j=0; j<256*5; j++) { // 5 cycles of all colors on wheel
    for(i=0; i< stripOne.numPixels(); i++) {
      stripOne.setPixelColor(i, Wheel(((i * 256 / stripOne.numPixels()) + j) & 255));
    }
    stripOne.show();
    delay(wait);
  }
}



// Input a value 0 to 255 to get a color value.
// The colours are a transition r - g - b - back to r.
uint32_t Wheel(byte WheelPos) {
  WheelPos = 255 - WheelPos;
  if(WheelPos < 85) {
   return stripOne.Color(255 - WheelPos * 3, 0, WheelPos * 3);
  } else if(WheelPos < 170) {
    WheelPos -= 85;
   return stripOne.Color(0, WheelPos * 3, 255 - WheelPos * 3);
  } else {
   WheelPos -= 170;
   return stripOne.Color(WheelPos * 3, 255 - WheelPos * 3, 0);
  }
}


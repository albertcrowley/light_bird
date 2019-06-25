#include <LEDMatrixDriver.hpp>


#include "light_bird.h"


// This draw a moving sprite on your LED matrix using the hardware SPI driver Library by Bartosz Bielawski.
// Example written 16.06.2017 by Marko Oette, www.oette.info

// Define the ChipSelect pin for the led matrix (Dont use the SS or MISO pin of your Arduino!)
// Other pins are Arduino specific SPI pins (MOSI=DIN, SCK=CLK of the LEDMatrix) see https://www.arduino.cc/en/Reference/SPI
const uint8_t LEDMATRIX_CS_PIN = 9;

// Number of 8x8 segments you are connecting
const int LEDMATRIX_SEGMENTS = 1;
const int SEGMENT_WIDTH = 8;
const int LEDMATRIX_WIDTH    = LEDMATRIX_SEGMENTS * SEGMENT_WIDTH;

// The LEDMatrixDriver class instance
LEDMatrixDriver lmd(LEDMATRIX_SEGMENTS, LEDMATRIX_CS_PIN);

void setup() {
  // init the display
  lmd.setEnabled(true);
  lmd.setIntensity(0);   // 0 = low, 15 = high
}

int x = -SEGMENT_WIDTH; // start off to the left
int y = 0;              // start top left
bool s = true;          // start with led on

byte a[8]={ B00000000,
            B00000000,
            B00000000,
            B00000000,
            B00000000,
            B00000000,
            B00000000,
            B00000000};


int ANIM_DELAY = 200;
int SPEEDUP = 10;

void loop() {

  t_field f = create_field(4,6);

  drawField(f);
  int gap = 7;
  int gap_dir = -1;
  int shift_delta = 0;
  while (true) {
    for (int ticks = 0; ticks< 5; ticks++) {
      f = tick(f);

      if (shift_delta == 0 || random(0,10)>5) {
        shift_delta = random(-1,2);
      }
      
      if (f.shift + f.gap + shift_delta < 2 ) shift_delta++;
      if (f.shift +f.gap + shift_delta > 8) shift_delta--;
      add_row(&f, gap, shift_delta);

      drawField(f);
      delay (ANIM_DELAY);      

      if (ANIM_DELAY > SPEEDUP) ANIM_DELAY = ANIM_DELAY-SPEEDUP;
    }
    gap += gap_dir;

    if (gap < 3) {
      gap_dir = 1;
    }
    if (gap > 5) {
      gap_dir = -1;
    }
  }


}


void drawField (t_field f) {
  byte b[8];
  field_to_bytes(f, b);
  drawArray(b);

}

void drawArray ( byte* array) {
  drawSprite( array, 0, 0, 8, 8 );
  lmd.display();
  delay(ANIM_DELAY);  
}

void drawSprite( byte* sprite, int x, int y, int width, int height )
{
  byte mask = B10000000;
  for( int iy = 0; iy < height; iy++ )
  {
    for( int ix = 0; ix < width; ix++ )
    {
      lmd.setPixel(x + ix, y + iy, (bool)(sprite[iy] & mask ));
      mask = mask >> 1;
    }
    mask = B10000000;
  }
}

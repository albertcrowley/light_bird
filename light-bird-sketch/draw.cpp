#include "draw.h"
#include "light_bird.h"
#include <LEDMatrixDriver.hpp>

// spinner
int encoderPosCount = 4; 
int sensorPin = A0;

// DRAWING
int ANIM_DELAY = 150;
int SPEEDUP = 1;
int FLOOR = 100;

char outbuf[1000];

unsigned long poll_timer = 0;
void delayLoop(t_field f,  int d) {
  unsigned long start = millis();
  unsigned long a=0;
  unsigned long b=0;
  unsigned long c=0;
  unsigned long last = start;
  bool playerFlash = true;
  while ( (millis() - start) < d ) {
    if (millis() != last) {
      last = millis();
      poll_timer++;
    }

      a = millis();
      b = millis();  
      drawField(f,(last%120) > 50);
      c = millis();  

      
  }

     
}


void drawField (t_field f, bool playerIntensity) {
    byte b[8];
    field_to_bytes(f, b);
    drawArray(b, playerIntensity);
}

void drawArray ( byte* array, bool playerIntensity) {
    extern LEDMatrixDriver lmd;
    drawSprite( array, 0, 0, 8, 8 );
    drawPlayer(playerIntensity);
    lmd.display(); 
}

void drawSprite( byte* sprite, int x, int y, int width, int height )
{
  extern LEDMatrixDriver lmd;
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

void drawPlayer(int intensity) {
  extern LEDMatrixDriver lmd;
//    for (int x=0; x< 8; x++) {
//        lmd.setPixel(x, 0, 0);
//    }
    lmd.setPixel(encoderPosCount, 0, intensity);
}


// SPINNER 

int checkSpinner() { 
  int divider = 1024/8;
  int sensorValue = analogRead(sensorPin);
  encoderPosCount = sensorValue / divider ;
  
  return encoderPosCount;
 }

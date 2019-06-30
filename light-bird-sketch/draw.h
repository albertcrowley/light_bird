#include <LEDMatrixDriver.hpp>
#include "light_bird.h"

#ifndef DRAW_H
#define DRAW_H

// Define the ChipSelect pin for the led matrix (Dont use the SS or MISO pin of your Arduino!)
// Other pins are Arduino specific SPI pins (MOSI=DIN, SCK=CLK of the LEDMatrix) see https://www.arduino.cc/en/Reference/SPI
const uint8_t LEDMATRIX_CS_PIN = 9;

// Number of 8x8 segments you are connecting
const int LEDMATRIX_SEGMENTS = 1;
const int SEGMENT_WIDTH = 8;
const int LEDMATRIX_WIDTH    =  8; //LEDMATRIX_SEGMENTS * SEGMENT_WIDTH;


void delayLoop(t_field f, int d);

void drawField (t_field f, bool flashPlayerDot);

void drawArray ( byte* array, bool flashPlayerDot);

void drawSprite( byte* sprite, int x, int y, int width, int height );

void drawPlayer(int intensity) ;

int checkSpinner();
#endif //DRAW_H

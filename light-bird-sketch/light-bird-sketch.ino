#include "light_bird.h"
#include "draw.h"



// The LEDMatrixDriver class instance
LEDMatrixDriver lmd(LEDMATRIX_SEGMENTS, LEDMATRIX_CS_PIN);

// This draw a moving sprite on your LED matrix using the hardware SPI driver Library by Bartosz Bielawski.
// Example written 16.06.2017 by Marko Oette, www.oette.info


void setup() {
  // init the display
  lmd.setEnabled(true);
  lmd.setIntensity(0);   // 0 = low, 15 = high

  //spinner
  checkSpinner();
  Serial.begin (9600);

}





void loop() {
  extern int ANIM_DELAY;
  extern int FLOOR;
  extern int SPEEDUP;

  t_field f = create_field(4,6);

  int gap = 7;
  int gap_dir = -1;
  int shift_delta = 0;
  while (true) {    
    for (int ticks = 0; ticks< 4; ticks++) {
      f = tick(f);

      if (shift_delta == 0 || random(0,10)>5) {
        shift_delta = random(-1,2);
      }
      
      if (f.shift + f.gap + shift_delta < 2 ) shift_delta++;
      if (f.shift +f.gap + shift_delta > 8) shift_delta--;
      add_row(&f, gap, shift_delta);

      checkSpinner();

      delayLoop(f, ANIM_DELAY);

      if (ANIM_DELAY > FLOOR) ANIM_DELAY = ANIM_DELAY-SPEEDUP;
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

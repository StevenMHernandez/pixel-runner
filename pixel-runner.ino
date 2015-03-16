#include <TVout.h>
#include "Axis.h"

TVout TV;

int screen_width = 112;
int screen_height = 96;
Axis X(0, screen_width);
Axis Y(1, screen_height);

void setup() {
  TV.begin(NTSC, screen_width, screen_height);
}

void loop() {
  X.updateSpeed();
  Y.updateSpeed();
  if(X.updateCounter()) {
    TV.draw_column(X.location, 0, screen_height, 2);
  }
  if(Y.updateCounter()) {
    TV.draw_row(Y.location, 0, screen_width, 2);
  }
}

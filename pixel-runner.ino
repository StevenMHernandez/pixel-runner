#include <TVout.h>
#include <fontALL.h>
#include "Axis.h"

TVout TV;
Axis X(0, 120);
Axis Y(1, 96);

void setup() {
  TV.begin(NTSC,120,96);
}

void loop() {
  X.updateSpeed();
  Y.updateSpeed();
  if(X.updateCounter()) {
    TV.draw_column(X.location, 1, 96, 2);
  }
  if(Y.updateCounter()) {
    TV.draw_row(Y.location, 1, 120, 2);
  }
  TV.delay(0.1);
}

#ifndef Axis_h
#define Axis_h

#include "Arduino.h"

class Axis
{
  public:
    Axis(int potPin, int size);
    int size;
    int location;
    int speed;
    int updateCounter();
    void updateSpeed();
  private:
    int _potPin;
    int _counter;
    void _updateLocation();
};
#endif

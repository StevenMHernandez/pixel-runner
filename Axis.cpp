#include "Arduino.h"
#include "Axis.h"

int _potMax = 90;

int location = 0;
int speed = 0;
int _potPin;
int _maxSize;
int _counter = 0;

Axis::Axis(int potPin, int maxSize)
{
  _potPin = potPin;
  _maxSize = maxSize;
}

int Axis::updateCounter() {
  _counter += speed;
  if(_counter > _potMax || _counter < -_potMax) {
    _counter = 0;
    Axis::_updateLocation();
    return 1;
  }
  return 0;
}

void Axis::updateSpeed() {
  speed = map(analogRead(_potPin), 0, 1023, -_potMax, _potMax);
}

void Axis::_updateLocation() {
  if(signbit(speed)){
    location--;
  } else {
    location++;
  }
  if(location > _maxSize) {
    location=0;
  }
}

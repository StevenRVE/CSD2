#include <iostream>
#pragma once

class Envelope {
public:
  // constructor and destructor
  Envelope(int length);
  ~Envelope();

  // methods
  void trigger();
  void tick();

  // getters and setters
  void setLength(int length);
  int getLength();
  double getSample();

protected:
  double sample = 0;
  double time = 0;
  int length = 1000; // in samples
};

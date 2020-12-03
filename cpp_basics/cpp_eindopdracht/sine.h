#include "oscillator.h"
#pragma once

class Sine : public Oscillator{
public:
  // constructor and destructor
  Sine(double frequency, double samplerate);
  ~Sine();

  // methods
  void calculate() override;
};

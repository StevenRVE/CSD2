#ifndef _SINE_H_
#define _SINE_H_
#include <iostream>
#include "oscillator.h"

class Sine : public Oscillator
{
public:
  //Constructor and destructor
  Sine(float frequency, double samplerate);
  ~Sine();

  // go to next sample
  void calculate();

private:

};

#endif

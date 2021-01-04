#ifndef _SAW_H_
#define _SAW_H_
#include <iostream>
#include "oscillator.h"

class Saw : public Oscillator
{
public:
  //Constructor and destructor
  Saw(float frequency, double samplerate);
  ~Saw();

  // go to next sample
  void calculate();

  //getters and setters

private:
// int overtonesAmount;
};

#endif

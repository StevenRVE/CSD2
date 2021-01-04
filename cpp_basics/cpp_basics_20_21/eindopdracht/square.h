#ifndef _SQUARE_H_
#define _SQUARE_H_
#include <iostream>
#include "oscillator.h"

class Square : public Oscillator
{
public:
  //Constructor and destructor
  Square(float frequency, double samplerate);
  ~Square();

  // go to next sample
  void calculate();

  //getters and setters

private:
// int overtonesAmount;
};

#endif

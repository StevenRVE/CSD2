#ifndef _SYNTHESIZER_H_
#define _SYNTHESIZER_H_
#include <iostream>

// #include "oscillator.h"
// #include "sine.h"
// #include "saw.h"
// #include "pulse.h"
// #include "envelope.h"

class Synthesizer {
public:
  // constructor
  Synthesizer(double freq, double samplerate, double amplitude);

  // destructor
  ~Synthesizer();

  // methods
  void tick(double samplerate);

  // getters and setters
  double getFreq();
  void setFreq(double freq);

private:
  // // variables
  double freq;
  double samplerate;
  double amplitude;
};

#endif

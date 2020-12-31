#ifndef _SYNTHESIZER_H_
#define _SYNTHESIZER_H_
#include <iostream>
#include "oscillator.h"
#include "sine.h"
// #include "saw.h"
// #include "pulse.h"
// #include "envelope.h"

class Synthesizer {
public:
  // constructor
  Synthesizer(double frequency, double samplerate);

  // destructor
  ~Synthesizer();

  // methods
  void tick(double samplerate);

  Oscillator* chooseOsc(int i);

  // getters and setters
  double getFrequency();
  void setFrequency(double frequency);

private:
  // variables
  double frequency;
  double samplerate;
  double amplitude;

};

#endif

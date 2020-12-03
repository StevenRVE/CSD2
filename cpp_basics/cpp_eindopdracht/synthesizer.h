#include <iostream>
#pragma once

#include "oscillator.h"
#include "sine.h"
#include "saw.h"
#include "pulse.h"
#include "envelope.h"

class Synthesizer {
public:
  // constructor
  Synthesizer(double freq, double length);

  // destructor
  ~Synthesizer();

  // methods
  void trigger();
  void tick(double samplerate);

  // getters and setters
  double getFreq();
  void setFreq(double freq);
  double getSample();

private:
  Sine osc1;
  Saw osc2;
  Pulse osc3;
  Envelope env;
  // variables
  double freq = 300;
  int length =  10000;
  double sample = 0;
};

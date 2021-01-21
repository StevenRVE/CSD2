#ifndef _SYNTHESIZER_H_
#define _SYNTHESIZER_H_
#include <iostream>
#include "oscillator.h"
#include "sine.h"
#include "square.h"
#include "saw.h"

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

  void noteO();
  void noteOff();

  
private:
  // variables
  double frequency;
  double samplerate;
  double amplitude;

};

#endif

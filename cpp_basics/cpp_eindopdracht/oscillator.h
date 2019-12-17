#ifndef _OSCILLATOR_H_
#define _OSCILLATOR_H_
#include <iostream>

class Oscillator
{
public:
  //Constructor and destructor
  Oscillator(double frequency, double samplerate);
  ~Oscillator();

  //return the current sample
  double getSample();
  // go to next sample
  void tick();
  virtual void calculate() = 0;

  //getters and setters
  void setFrequency(double frequency);
  double getFrequency();

  //NOTE - do we need a setter for phase? for now -> not using one

protected:
  double amplitude;
  double frequency;
  double phase;
  // contains the current sample
  double sample;
  double samplerate;
};

#endif

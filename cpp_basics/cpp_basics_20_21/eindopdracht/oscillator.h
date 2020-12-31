#ifndef _OSCILLATOR_H_
#define _OSCILLATOR_H_
#include <iostream>

class Oscillator
{
public:
  // constructor and destructor
  Oscillator(double frequency, double samplerate);
  ~Oscillator();

  // methods
  void tick();
  virtual void calculate() = 0;

  // getters and setters
  double getFrequency();
  void setFrequency(double frequency);
  double getSample();
  double getPhase();

protected:
  // variables
  double amplitude;
  double frequency;
  double phase;
  // -contains the current sample-
  double sample;
  double samplerate;
};

#endif

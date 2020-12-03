#include "oscillator.h"
#pragma once

class Pulse : public Oscillator{
public:
  // constructor and destructor
  Pulse(double frequency, double samplerate, double pwm);
  ~Pulse();

  // methods
  void calculate() override;

  // setters and getters
  void setPWM(double pwm);
  double getPWM();

private:
  // variables
  double pwm = 0.5;
};

#ifndef _SINE_H_
#define _SINE_H_
#include <iostream>

#define SAMPLERATE 44100

class Sine
{
public:
  //Constructor and destructor
  Sine(float frequency);
  ~Sine();


  // go to next sample
  void tick();

  //getters and setters
  void setFrequency(float frequency);
  float getFrequency();
  float getSample();
  //NOTE - do we need a setter for phase? for now -> not using one

private:
  float amplitude;
  float frequency;
  float phase;
  float samplerate;
  // contains the current sample
  float sample;

};

#endif

#include "sine.h"
#include "math.h"

Sine::Sine(float frequency, double samplerate, float amplitude)
: frequency(frequency), samplerate(samplerate), amplitude(amplitude), sample(0), phase(0)
{
  // initialize members
  std::cout << "Sine - constructor\n";
}



Sine::~Sine() {
  std::cout << "Sine - destructor\n";
}


float Sine::getSample() {
  return sample;
}

void Sine::calculate() {
  sample = amplitude * sin(M_PI * 2 * phase);
}

//getters and setters
void Sine::setFrequency(float frequency)
{
  if(frequency >= 20 && <+ 20000){
    this->frequency = frequency;
  }
}

float Sine::getFrequency()
{
  return frequency;
}

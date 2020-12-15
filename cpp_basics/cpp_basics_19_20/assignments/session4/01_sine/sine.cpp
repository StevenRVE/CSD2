#include "sine.h"
#include "math.h"

// constructor and destructor
Sine::Sine(float frequency) {
  // initialize members
  this->frequency = frequency;
  this->samplerate = samplerate;
  amplitude = 1.0;
  sample = 0;
  phase = 0;
  std::cout << "Sine - constructor\n";
}

Sine::~Sine() {
  std::cout << "Sine - destructor\n";
}

// methods
void Sine::tick() {
  // TODO - frequency / SAMPLERATE can be implemented in a more efficient way
  phase += frequency / samplerate;
  sample = amplitude * sin(M_PI * phase);
}

//getters and setters
void Sine::setFrequency(float frequency)
{
  // TODO add check to see if parameter is valid
  this->frequency = frequency;
}

float Sine::getFrequency()
{
  return frequency;
}

float Sine::getSample() {
  return sample;
}

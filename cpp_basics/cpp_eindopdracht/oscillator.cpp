#include "oscillator.h"
#include "math.h"

Oscillator::Oscillator(float frequency, float samplerate) {
  // initialize members
  this->frequency = frequency;
  this->samplerate = samplerate;
  amplitude = 1.0;
  sample = 0;
  phase = 0;
  std::cout << "Oscillator - constructor\n";
}

Oscillator::~Oscillator() {
  std::cout << "Oscillator - destructor\n";
}

float Oscillator::getSample() {
  return sample;
}

void Oscillator::tick(){
  // TODO - frequency / samplerate can be implemented in a more efficient way
  phase += frequency / samplerate;
  calculate();
}

//getters and setters
void Oscillator::setFrequency(float frequency)
{
  // TODO add check to see if parameter is valid
  this->frequency = frequency;
}

float Oscillator::getFrequency()
{
  return frequency;
}

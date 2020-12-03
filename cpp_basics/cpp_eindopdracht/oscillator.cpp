#include "oscillator.h"
#include "math.h"

// constructor //
Oscillator::Oscillator(double frequency, double samplerate) {
  // initialize members
  this->frequency = frequency;
  this->samplerate = samplerate;
  amplitude = 1.0;
  sample = 0;
  phase = 0;
  std::cout << "Oscillator - constructor\n";
}

// destructor //
Oscillator::~Oscillator() {
  std::cout << "Oscillator - destructor\n";
}

// methods //

// go to next sample
void Oscillator::tick(){
  // TODO - frequency / samplerate can be implemented in a more efficient way
  phase += frequency / samplerate;
  calculate();
}

//getters and setters //
double Oscillator::getSample() {
  return sample;
}

double Oscillator::getFrequency()
{
  return frequency;
}

void Oscillator::setFrequency(double frequency)
{
  // TODO add check to see if parameter is valid
  this->frequency = frequency;
}

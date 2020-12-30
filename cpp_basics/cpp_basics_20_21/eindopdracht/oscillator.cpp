#include "oscillator.h"
#include "math.h"

// constructor //
Oscillator::Oscillator(double frequency, double samplerate)
: frequency(frequency), samplerate(samplerate), amplitude(1.0), sample(0), phase(0)
{
  // initialize members
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

double Oscillator::getFrequency()
{
  return frequency;
}

void Oscillator::setFrequency(double frequency)
{
  if(frequency >= 20 && frequency <= 20000){
    this->frequency = frequency;
  }
}

double Oscillator::getSample() {
  return sample;
}

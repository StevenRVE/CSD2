
#include <iostream>
#include "oscillator.h" // "zoek naar deze file binnen de dezelfde map als deze file"

// constructor
Oscillator::Oscillator(float freq)
{
  this->freq = freq;
  std::cout << "\nOscillator - constructor\n";
}

// destructor
Oscillator::~Oscillator()
{
  std::cout << "\nOscillator - destructor\n";
}

void Oscillator::setFreq(float freq)
{
  std::cout << "\nOscillator - setFreq\n";
  if(freq < 0 || freq > 22050)
  {
    std::cout << "ERROR - unable to set the frequency value with value: " << freq
    << "\n";
  }
  this->freq = freq;
}


float Oscillator::getFreq()
{
  return freq;
}

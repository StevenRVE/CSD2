#include "synthesizer.h"

// constructor
Synthesizer::Synthesizer(double frequency, double samplerate)
{
  std::cout << "Synthesizer - constructor\n";
  this->frequency = frequency;
  this->samplerate = samplerate;
}

// destructor
Synthesizer::~Synthesizer(){
  std::cout << "Synthesizer - destructor\n";
}

// getters and setters
double Synthesizer::getFrequency() {
  return frequency;
}

void Synthesizer::setFrequency(double frequency) {
  this->frequency=frequency;
}

// methods
Oscillator* Synthesizer::chooseOsc(int i){
  Oscillator* osc = nullptr;

  if(i == 1){
    osc = new Sine(getFrequency(), samplerate);
  }

  if(i == 2){
    osc = new Square(getFrequency(), samplerate);
  }

  if(i == 3){
    osc = new Saw(getFrequency(), samplerate);
  }

  return osc;
}

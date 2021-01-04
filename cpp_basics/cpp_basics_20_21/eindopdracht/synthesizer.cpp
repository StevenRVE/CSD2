#include "synthesizer.h"

// constructor
Synthesizer::Synthesizer(double frequency, double samplerate)
{
  std::cout << "Synthesizer - constructor\n";
  this->frequency=frequency;
  this->samplerate=samplerate;
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
  // std::cout << "freq is = " << getFrequency() << std::endl;
  Oscillator* osc = nullptr;

  if(i == 1){
    osc = new Sine(440, 44100);
  }

  if(i == 2){
    osc = new Square(440, 44100);
  }

  if(i == 3){
    osc = new Saw(440, 44100);
  }

  return osc;

}

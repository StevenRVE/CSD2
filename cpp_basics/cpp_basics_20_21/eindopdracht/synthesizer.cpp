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

// methods
void Synthesizer::tick(double samplerate) {
  // -tick envelope and oscillator-
  // sample = osc.getSample() * env.getSample();
}

// getters and setters
double Synthesizer::getFrequency() {
  return frequency;
}

void Synthesizer::setFrequency(double frequency) {
  this->frequency=frequency;
}

Oscillator* Synthesizer::chooseOsc(int i){
  // std::cout << "freq is = " << getFrequency() << std::endl;
  Oscillator* osc = nullptr;

  if(i == 1){
  osc =  new Sine(440, 44100);
  }

  return osc;

  // if(i == 2){
  //   return new Saw(frequency, samplerate);
  // }
  // if(i == 3){
  //   return new Square(frequency, samplerate);
  // }
}

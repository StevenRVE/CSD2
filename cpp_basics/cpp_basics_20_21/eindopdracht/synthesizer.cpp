#include "synthesizer.h"


// constructor
Synthesizer::Synthesizer(double freq, double samplerate, double amplitude) : freq(freq), samplerate(samplerate), amplitude(amplitude)
{
  std::cout << "Synthesizer - constructor\n";
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
double Synthesizer::getFreq() {
  return freq;
}

void Synthesizer::setFreq(double freq) {
  this->freq=freq;
}

#include "synthesizer.h"

// constructor
Synthesizer::Synthesizer(double freq, double length) {
  this->freq = freq;
  this->length = length;
  // env.setLength(length);
  // osc1.setFreq(freq);
  // osc1.setAmp(amp);
  // osc2.setFreq(freq);
  // osc2.setAmp(amp);
  // osc3.setFreq(freq);
  // osc3.setAmp(amp);
  std::cout << "Synthesizer - constructor\n";
}

// destructor
Synthesizer::~Synthesizer(){
  std::cout << "Synthesizer - destructor\n";
}

// methods
void Synthesizer::trigger(){
  // env.trigger();
}

void Synthesizer::tick(double samplerate) {
  // -tick envelope and oscillator-
  // env.tick();
  // osc1.tick(samplerate);
  // osc2.tick(samplerate);
  // osc3.tick(samplerate);
  // sample = osc.getSample() * env.getSample();
}

// getters and setters
double Synthesizer::getSample() {
  return sample;
}

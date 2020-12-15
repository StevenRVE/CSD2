#include "sine.h"
#include "math.h"

// constructor and destructor

Sine::Sine(double frequency, double samplerate) : Oscillator(frequency, samplerate) {
  std::cout << "Sine constructor" << "\n";
}

Sine::~Sine(){
  std::cout << "Sine destructor" << "\n";
}

// methods
void Sine::calculate(){
  sample = sin(M_PI * 2 * phase);
}

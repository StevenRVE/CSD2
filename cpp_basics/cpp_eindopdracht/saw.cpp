#include "saw.h"
#include "math.h"

// constructor and destructor

Saw::Saw(double frequency, double samplerate) : Oscillator(frequency, samplerate) {
  std::cout << "Saw constructor" << "\n";
}

Saw::~Saw(){
  std::cout << "Saw destructor" << "\n";
}

// methods
void Saw::calculate(){
  sample = sin(1 - phase * 2);
  if (phase >= 1){
    phase = 0;
  }
}

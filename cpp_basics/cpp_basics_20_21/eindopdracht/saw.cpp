#include "saw.h"
#include "math.h"

Saw::Saw(float frequency, double samplerate)
: Oscillator(frequency, samplerate)
{
  // VRAAG INITIALIZEMENT
  std::cout << "Saw - constructor\n";
}

Saw::~Saw() {
  std::cout << "Saw - destructor\n";
}

void Saw::calculate() {
  double y = 0;
  for(int i=1; i<100; i++){
    y += (sin(M_PI * 2 * phase * i)/i);
  }
  sample = y;
}

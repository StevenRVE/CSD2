#include "sine.h"
#include "math.h"

Sine::Sine(float frequency, double samplerate)
: Oscillator(frequency, samplerate)
{
  // VRAAG INITIALIZEMENT
  std::cout << "Sine - constructor\n";
}

Sine::~Sine() {
  std::cout << "Sine - destructor\n";
}

void Sine::calculate(double phase) {
  sample = amplitude * sin(M_PI * 2 * phase);
}

//getters and setters

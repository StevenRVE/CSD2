#include "square.h"
#include "math.h"

Square::Square(float frequency, double samplerate)
: Oscillator(frequency, samplerate)
{
  // VRAAG INITIALIZEMENT
  std::cout << "Square - constructor\n";
}

Square::~Square() {
  std::cout << "Square - destructor\n";
}

void Square::calculate() {
  double y = 0;
  for(int i=1; i<50; i = i+2){
    y += (sin(M_PI * 2 * phase * i)/i);
  }
  sample = y * 0.5;
}

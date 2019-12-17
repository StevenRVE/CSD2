#include "square.h"
#include "math.h"

// constructor and destructor

Square::Square(double frequency, double samplerate) : Oscillator(frequency, samplerate) {
  std::cout << "Square constructor" << "\n";
}

Square::~Square(){
  std::cout << "Square destructor" << "\n";
}

// methods
void Square::calculate(){
  sample = sin(M_PI * 2 * phase);
  if (sample > 0){
    sample = 1;
  }
  else{
    sample = -1;
  }
}

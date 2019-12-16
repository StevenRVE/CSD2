#include "oscillator.h"

class Sine : public Oscillator{
public:
  // constructor and destructor
  Sine(float frequency, float samplerate);
  ~Sine();

  // methods
  void calculate() override; 
};

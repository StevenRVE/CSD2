#include "oscillator.h"

class Saw : public Oscillator{
public:
  // constructor and destructor
  Saw(float frequency, float samplerate);
  ~Saw();

  // methods
  void calculate() override;
};

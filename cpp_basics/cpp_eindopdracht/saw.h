#include "oscillator.h"

class Saw : public Oscillator{
public:
  // constructor and destructor
  Saw(double frequency, double samplerate);
  ~Saw();

  // methods
  void calculate() override;
};

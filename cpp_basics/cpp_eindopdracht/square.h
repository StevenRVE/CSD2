#include "oscillator.h"

class Square : public Oscillator{
public:
  // constructor and destructor
  Square(float frequency, float samplerate);
  ~Square();

  // methods
  void calculate() override;
};

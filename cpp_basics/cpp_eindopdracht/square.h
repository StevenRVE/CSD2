#include "oscillator.h"

class Square : public Oscillator{
public:
  // constructor and destructor
  Square(double frequency, double samplerate);
  ~Square();

  // methods
  void calculate() override;

  // variables
private:
  double pwm;
};

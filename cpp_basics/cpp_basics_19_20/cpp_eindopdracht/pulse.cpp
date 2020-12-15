#include "pulse.h"
#include "math.h"

// constructor and destructor

Pulse::Pulse(double frequency, double samplerate, double pwm) : Oscillator(frequency, samplerate) {
  std::cout << "Pulse constructor" << "\n";
}

Pulse::~Pulse(){
  std::cout << "Pulse destructor" << "\n";
}

// methods
void Pulse::calculate(){
  sample = sin(M_PI * 2 * phase);
  if (sample > pwm){
    sample = 1;
  }
  else{
    sample = -1;
  }
}

void Pulse::setPWM(double pwm){
  this->pwm = pwm;
}

double Pulse::getPWM(){
  return pwm;
}

#include <iostream>
#include "oscillator.h"

int main()
{
  Oscillator oscillator(220);
  oscillator.setFreq(400);
  std::cout << "\nThe frequency of the oscillator object = " << oscillator.getFreq()
    << "\n";
  return 0;
}

#include <iostream>
#include "instrument.h"

#define LOG(x) std::cout << x << std::endl;

using namespace std;


int main()
{
  Instrument instrument1("banjo", "Fooo");
  Instrument instrument2("drum", "Ratatata");

  instrument1.play();
  instrument2.play();

  // instrument1.setRollTimes(3)
  instrument1.roll(10);

  instrument2.roll(2);
}

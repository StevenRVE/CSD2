#include <iostream>
#include "instrument.h"

#define LOG(x) std::cout << x << std::endl;

using namespace std;


int main()
{
  Instrument instrument1("banjo", "Fooo", 40, 2, 120);
  Instrument instrument2("drum", "Ratatata", 60, 20, 100);

  instrument1.play();
  instrument2.play();

}

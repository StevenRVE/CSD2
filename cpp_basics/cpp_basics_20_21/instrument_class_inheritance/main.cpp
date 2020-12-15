#include <iostream>
#include "instrument.h"
#include "banjo.h"
#include "piano.h"

#define LOG(x) std::cout << x << std::endl;

using namespace std;


int main()
{
  Banjo banjo("banjo", "Ploink");
  Piano piano("piano", "Ping");

  banjo.play();
  piano.play();

  return 0;
}

/*  To run it type
 *  make helloworld
 *  ./helloworld
 *
 */
#include <iostream>
#include <string>
#include "instrument.h"
using namespace std;

int main()
{
  Instrument inst0("ping");

  Instrument inst1("prrrrrrr");

  inst0.roll(8);
  return 0;
}

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
  int rollTimes;

  Instrument inst0("ping");

  Instrument inst1("prrrrrrr");

  cout << "Input number of rollTimes: " << endl;

  cin >> rollTimes;

  inst0.roll(rollTimes);
  return 0;
}

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

  LeadSynth lead1("mainLeadSynth","Weeee", 36, 40);

  BassSynth bass1("mainBassSynth", "Hmmmm", 36, 24);



  cout << "Input mainLeadSynth frequency: " << endl;

  cin >> Pitch;

  lead1.roll(rollTimes);

  // end program
  return 0;
}

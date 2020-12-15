#include <iostream>
#include <string>
#include <thread>
#include "jack_module.h"
#include "math.h"
#include "sine.h"
#include "leadSynth.h"
#include "bassSynth.h"
using namespace std;

int main()
{
  int rollTimes;

  LeadSynth lead1("mainLeadSynth", 36, 40);

  BassSynth bass1("mainBassSynth", 36, 24);

  bass1.play();

  cout << "Input mainLeadSynth rollTimes: " << endl;

  cin >> rollTimes;

  lead1.roll(rollTimes);

  // end program
  return 0;
}

#include "instrument.h"

class LeadSynth : public Instrument{
public:
  // constructor and destructor
  LeadSynth(std::string name, int pitchRange, int lowestNote);
  ~LeadSynth();

  // methods
  void FM();

  void AM();
};

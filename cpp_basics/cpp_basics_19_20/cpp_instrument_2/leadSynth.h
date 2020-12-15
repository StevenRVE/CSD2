#include "instrument.h"

class LeadSynth : public instrument{
public:
  // constructor and destructor
  LeadSynth(std::string name, std::string sound, int pitchRange, int lowestNote);
  ~LeadSynth();

  // methods
  void FM();

  void AM();
};

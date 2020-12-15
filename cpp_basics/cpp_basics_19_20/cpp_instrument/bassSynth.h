#include "instrument.h"

class BassSynth : public Instrument{
public:
  // constructor and destructor
  BassSynth(std::string name, int pitchRange, int lowestNote);
  ~BassSynth();

  // methods
  void subOctave();
};

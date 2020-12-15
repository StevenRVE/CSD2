#include "instrument.h"

class BassSynth : public instrument{
public:
  // constructor and destructor
  BassSynth(std::string name, std::string sound, int pitchRange, int lowestNote);
  ~BassSynth();

  // methods
  void subOctave();

};

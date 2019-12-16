#include "bassSynth.h"

// constructor and destructor

BassSynth::BassSynth(std::string name, int pitchRange, int lowestNote) :
  Instrument(name, sound, pitchRange, lowestNote)
{
  std::cout << "BassSynth::BassSynth - constructor, name: "
    << name << "\n";
  sound = "Brrrr" 
}

BassSynth::~BassSynth(){
  std::cout << "BassSynth::BassSynth - destructor, name: "
    << name << "\n";
}

// methods
void subOctave(){

}

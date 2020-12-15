#include "leadSynth.h"

// constructor and destructor

LeadSynth::LeadSynth(std::string name, std::string sound, int pitchRange, int lowestNote) :
  Instrument(name, sound, pitchRange, lowestNote)
{
  std::cout << "LeadSynth::LeadSynth - constructor, name: "
    << name << "\n";
  sound = "Weeeee";
}

LeadSynth::~LeadSynth(){
  std::cout << "LeadSynth::LeadSynth - destructor, name: "
    << name << "\n";
}

// methods

void LeadSynth::FM(){

}

void LeadSynth::AM(){

}

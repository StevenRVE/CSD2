#include "LeadSynth.h"

// constructor and destructor

LeadSynth::LeadSynth(std::string name, std::string sound, int pitchRange, int lowestNote){
  std::cout << "LeadSynth::LeadSynth - constructor, name: "
    << name << "\n";
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

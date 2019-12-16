#include "BassSynth.h"

// constructor and destructor

BassSynth::BassSynth(std::string name, std::string sound, int pitchRange, int lowestNote){
  std::cout << "BassSynth::BassSynth - constructor, name: "
    << name << "\n";
}

BassSynth::~BassSynth(){
  std::cout << "BassSynth::BassSynth - destructor, name: "
    << name << "\n";
}

// methods

void BassSynth::FM(){

}

void BassSynth::AM(){

}

#include "instrument.h"
#include <unistd.h>

// ___constructor and destructor___
// constructor
Instrument::Instrument(std::string name, std::string sound, int pitchRange, int lowestNote){
  std::cout << "Instrument::Instrument - constructor, name: " << name << "\n";
  setSound(sound);
  this->name = name;
  this->pitchRange = pitchRange;
  this->lowestNote = lowestNote;
}

// destructor
Instrument::~Instrument(){
  std::cout << "Instrument::~Instrument - destructor, name: " << name<< "\n";
}

// ___methods___
// change sound var
void Instrument::setSound(std::string sound){
  this->sound = sound;
}

// print sound
void Instrument::play(){
  std::cout << sound << std::endl;
}

// print sound "rollTimes" times
void Instrument::roll(int rollTimes){
  for (int i=0; i<rollTimes; i++) {
    play();
    usleep(100000);
  }
}

// change rollTimes var
void Instrument::setRollTimes(int rollTimes){
  this->rollTimes = rollTimes;
}

void Instrument::setPitchRange(int pitchRange, int lowestNote){

}

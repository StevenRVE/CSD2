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

// methods
// setters
// change sound var
void Instrument::setSound(std::string sound){
  this->sound = sound;
}

// change rollTimes var
void Instrument::setRollTimes(int rollTimes){
  this->rollTimes = rollTimes;
}

void Instrument::setFreq(int frequency){
  this->frequency = frequency;
}

void Instrument::setAttack(int attack){
  this->attack = attack;
}

void Instrument::setDecay(int decay){
  this->decay = decay;
}

void Instrument::setSustain(double sustain){
  this->sustain = sustain;
}

void Instrument::setRelease(int release){
  this->release = release;
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

void Instrument::setPitchRange(int pitchRange, int lowestNote){
  this->pitchRange = pitchRange;
  this->lowestNote = lowestNote;
}

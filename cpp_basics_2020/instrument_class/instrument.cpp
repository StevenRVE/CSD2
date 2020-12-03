#include "instrument.h"

#define LOG(x) std::cout << x << std::endl;

// constructor and destructor
Instrument::Instrument(std::string name, std::string sound)
{
  LOG("Instrument::Instrument - constructor, name: " << name);
  setSound(sound);
  this->name = name;
}

Instrument::~Instrument()
{
  LOG("Instrument::~Instrument - destructor, name: " << name);
}

// methods
void Instrument::play()
{
  LOG(getSound());
}

void Instrument::roll(int rollTimes)
{
  setRollTimes(rollTimes);
  for (int i=0; i < rollTimes; i++){
    play();
  }
}

std::string Instrument::getSound()
{
  return sound;
}

void Instrument::setSound(std::string sound)
{
  this->sound = sound;
}

void Instrument::setRollTimes(int rollTimes)
{
  this->rollTimes = rollTimes;
}

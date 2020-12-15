#include <iostream>
#include "instrument.h"

#define LOG(x) std::cout << x << std::endl;

// constructor and destructor
Instrument::Instrument(std::string name, std::string sound)
{
  LOG("Instrument::Instrument - constructor, name: " << name);
  this->name = name;
  this->sound = sound;
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

std::string Instrument::getSound()
{
  return sound;
}

void Instrument::setSound(std::string sound)
{
  this->sound = sound;
}

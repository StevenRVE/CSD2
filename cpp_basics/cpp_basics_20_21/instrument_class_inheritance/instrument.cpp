#include "instrument.h"

#define LOG(x) std::cout << x << std::endl;

// constructor and destructor
Instrument::Instrument(std::string name, std::string sound, int pitch, int pitch_MIN, int pitch_MAX)
{
  LOG("Instrument::Instrument - constructor, name: " << name);
  setSound(sound);
  setPitch(pitch);
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

std::string Instrument::getSound()
{
  return sound;
}

void Instrument::setSound(std::string sound)
{
  this->sound = sound;
}

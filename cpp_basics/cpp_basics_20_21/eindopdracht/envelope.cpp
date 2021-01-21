#include "envelope.h"

Envelope::Envelope(double attack, double decay, double sustain, double release)
{
  std::cout << "Envelope - constructor\n"
}

Envelope::~Envelope()
{
  std::cout << "Envelope - destructor\n"
}

// getters and setters
// attack
double Envelope::getAttack()
{
  return attack;
}

void Envelope::setAttack(double attack)
{
  this->attack = attack;
  std::cout << "Attack: " << attack << "\n";
}

// decay
double Envelope::getDecay()
{
  return decay;
}

void Envelope::setDecay(double decay)
{
  this->decay=decay;
  std::cout << "Decay: " << decay << "\n";
}

// sustain
double Envelope::getSustain()
{
  return sustain;
}

void Envelope::setSustain(double sustain)
{
  this->sustain=sustain;
  std::cout << "Sustain: " << sustain << "\n";
}

// release;
double Envelope::getRelease()
{
  return release;
}

void Envelope::setRelease(double release)
{
  this->release=release;
  std::cout << "Release: " << release << "\n";
}

void Envelope::setADSR(double attack, double decay, double sustain, double release)
{
  setAttack(attack);
  setDecay(decay);
  setSustain(sustain);
  setRelease(release);
}

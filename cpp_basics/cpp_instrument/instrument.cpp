#include "instrument.h"


Instrument::Instrument(std::string sound){ // constructor
        setSound(sound);
}

void Instrument::setSound(std::string sound){
  this->sound = sound;
}

void Instrument::getSound(){
  std::cout << sound << std::endl;
}

void Instrument::roll(int rollTimes){
  for (int i=0; i<rollTimes; i++) {
    getSound();
  }
}

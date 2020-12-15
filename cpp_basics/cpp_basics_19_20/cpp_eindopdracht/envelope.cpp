#include "envelope.h"

// constructor and destructor
Envelope::Envelope(int length) {
  this->length = length;
  std::cout << "Envelope - constructor\n";
}

Envelope::~Envelope(){
  std::cout << "Envelope - destructor\n";
}

// methods
void Envelope::trigger() {
  time = 0;
}

void Envelope::tick() {
  if (time < length) {
    sample = 1 - (time / length);
    time++;
  }
}

// getters and setters
void Envelope::setLength(int length) {
  if (length > 0){
    this->length = length;
  } else {
    std::cout << "Error: length must be higher than 0";
  }
}

int Envelope::getLength() {
  return length;
}

double Envelope::getSample() {
  return sample;
}

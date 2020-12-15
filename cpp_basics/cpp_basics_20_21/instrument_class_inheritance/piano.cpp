#include <iostream>
#include "piano.h"
#define LOG(x) std::cout << x << std::endl;

// Constructor and destructor
Piano::Piano(std::string name, std::string sound) : Instrument(name, sound){
  LOG("Constructor Piano");
}

Piano::~Piano(){
  LOG("Destructor Piano");
}

// getters and setters

// methods

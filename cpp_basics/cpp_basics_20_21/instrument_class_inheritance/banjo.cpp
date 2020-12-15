#include <iostream>
#include "banjo.h"
#define LOG(x) std::cout << x << std::endl;

// Constructor and destructor
Banjo::Banjo(std::string name, std::string sound) : Instrument(name, sound){
  LOG("Constructor Banjo");
}

Banjo::~Banjo(){
  LOG("Destructor Banjo");
}

// getters and setters

// methods

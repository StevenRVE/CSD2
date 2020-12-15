#include "pet.h"

// constructor and destructor
Pet::Pet(std::string name, int age){
  std::cout << "Pet::constructor, name: " << name << std::endl;
}

Pet::~Pet(){
  std::cout << "Pet::destructor, name: " << name << std::endl;
}

// getters and setters
std::string Pet::getName(){
  return name;
}
int Pet::getAge(){
  return age;
}

void Pet::setName(std::string name){
  this->name = name;
}

void Pet::setAge(int age){
  this->age = age;
}
// methods

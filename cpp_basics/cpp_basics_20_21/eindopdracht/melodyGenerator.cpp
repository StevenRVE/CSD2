#include <iostream>
#include <time.h> /* time */
#include <stdlib.h> /* srand, rand */
#include <vector>
#include <math.h>
// #include <algorithm>
#include <chrono>
#include <thread>
#include "melodyGenerator.h"
#include "synthesizer.h"

// constructor and destructor
MelodyGenerator::MelodyGenerator()
{
  std::cout << "MelodyGenerator - constructor\n";
}

MelodyGenerator::~MelodyGenerator()
{
  std::cout << "MelodyGenerator - destructor\n";
}

// methods
void MelodyGenerator::randomSeed()
{
  srand (time(NULL));
}

void MelodyGenerator::generateScale(int startPos, int midiBaseValue)
{
  int storeNumber = midiBaseValue;

  if (startPos >= 0 && startPos <= scaleFormula.size()){
    // first add values from index startPos to new vector
    for(int i = startPos; i < scaleFormula.size(); i++){
      storeNumber = storeNumber + scaleFormula.at(i);
      int frequency = mtof(storeNumber);
      newScale.push_back(frequency);
    }
    // add remaining values to new vector
    for(int i = 0; i < startPos; i++){
      storeNumber = storeNumber + scaleFormula.at(i);
      int frequency = mtof(storeNumber);
      newScale.push_back(frequency);
    }
  }
}

double MelodyGenerator::randomFrequency(){
  int randomNumber = rand() % 7;
  newFrequency = newScale.at(randomNumber);
  return newFrequency;
  // std::cout << scale.at(randomNumber) << "\n";
}

double MelodyGenerator::mtof(int midiValue){
  int a = 440; //frequency of A (common value is 440Hz)
  return (a / 32.0) * pow(2.0, ((midiValue - 9.0) / 12.0));
}

double MelodyGenerator::generateMelody(){
   double frequency = randomFrequency();
   return frequency;
}

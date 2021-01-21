#include <chrono>
#include <thread>
#include <iostream>
#include <algorithm>
#include "melodyGenerator.h"
#include "synthesizer.h"

MelodyGenerator::MelodyGenerator()
{
  std::cout << "MelodyGenerator - constructor\n";
}

MelodyGenerator::~MelodyGenerator()
{
  std::cout << "MelodyGenerator - denstructor\n";
}

int MelodyGenerator::mtof()
{

}

// void MelodyGenerator::test(){
//   time_t start, finish;
//   time(&start);
//
//   float timestamp = 1.000;
//
//   bool running = true;
//   while (running)
//   {
//     time(&finish);
//
//     float duration = difftime(finish, start);
//
//     if(duration >= timestamp){
//        setFrequency(getFrequency()+100);
//        std::cout << "frequency is " << getFrequency() << "\n";
//     }
//     else{
//       std::this_thread::sleep_for(std::chrono::milliseconds(1));
//     }
//   }
// }

// getters and setters

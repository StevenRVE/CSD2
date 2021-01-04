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


// void chooseScale(){
// // Major scale
//   int scale [] = {2,2,1,2,2,2,1}
// }

// void rotate(vector<int>& vec, int d)
// {
//     // Base case
//     if (d == 0)
//         return;
//
//     // Push first d elements from the beginning
//     // to the end and remove those elements
//     // from the beginning
//     for (int i = 0; i < d; i++)
//     {
//         // adding first element at
//         // the end of vector
//         vec.push_back(vec[0]);
//
//         // removing first element
//         vec.erase(vec.begin());
//     }
//
//     // Print the rotated array
//     for (int i = 0; i < vec.size(); i++)
//     {
//         cout << vec[i] << " ";
//     }
// }

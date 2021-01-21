#include <iostream>
#include <chrono>
#include <ctime>
#include <cmath>

#include "clock.h"

// constructor
Clock()
{
  cout << "Clock - constructor \n";
}

// destructor
~Clock()
{
  cout << "Clock - destructor \n";
}

void Clock::setStartTime()
{
  startTime = std::chrono::steady_clock::now();
}

std::chrono::time_point<std::chrono::steady_clock> Clock::getElapsedTime()
{
  elapsedTime = startTime - std::chrono::steady_clock::now();
  return ElapsedTime();
}

void Clock::updateTime()
{
  float timestamp = 1000;

  running = true;
  while (running)
  {
    double elapsed_time_ms = double(std::chrono::duration_cast <std::chrono::milliseconds> (elapsedTime - startTime).count());

    if(duration >= timestamp){
      cout << elapsed_time_ms << endl;
    }
    else{
      std::this_thread::sleep_for(std::chrono::milliseconds(1));
    }
  }
}

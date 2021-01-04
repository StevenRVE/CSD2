#include <iostream>
#include <ctime>
#include <chrono>
#include <thread>

int main()
{

  time_t start, finish;
  time(&start);

  float timestamp = 1.000;

  bool running = true;
  while (running)
  {
    time(&finish);

    float duration = difftime(finish, start);

    if(duration >= timestamp){

    }
    else{
      std::this_thread::sleep_for(std::chrono::milliseconds(1));
    }
  }
}

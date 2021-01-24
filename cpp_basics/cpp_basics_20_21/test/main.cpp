#include <iostream>
#include <vector>
#include <chrono>
#include <ctime>
#include <thread>

void generateMelody(){
  time_t start, finish;
  time(&start);

  float timestamp = 1.000;

  bool running = true;
  while (running)
  {
    time(&finish);

    float duration = difftime(finish, start);

    if(duration >= timestamp){
       int x = 1;
       std::cout << "frequency is: " << duration << "\n";
       time(&start);
       // return frequency;
    }
    else{
      std::this_thread::sleep_for(std::chrono::milliseconds(1));
    }
  }
}

int main()
{
  generateMelody();

return 0;
}

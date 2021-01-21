#ifndef _CLOCK_H_
#define _CLOCK_H_

class Clock {
public:
  // constructor
  Clock();

  // destructor
  ~Clock();

  // methods
  void setStartTime();

  void getElapsedTime();

  void updateTime();


protected:
  std::chrono::time_point<std::chrono::steady_clock> startTime;
  std::chrono::time_point<std::chrono::steady_clock> elapsedTime;
  bool running = false;

};

#endif

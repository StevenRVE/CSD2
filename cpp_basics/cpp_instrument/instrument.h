#include <string>
#include <iostream>

class Instrument
{
  public: // members
    Instrument(std::string sound);

    void setSound(std::string sound);

    void getSound();

    void roll(int rollTimes);

  private:
    std::string sound;
};

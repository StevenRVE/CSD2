#include <iostream>

class Instrument
{
  public: //members
    // constructor and destructor
    Instrument(std::string name, std::string sound);

    ~Instrument();

    // methods
    void play();
    void roll(int rollTimes);

    // getters and setters
    std::string getSound();
    void setSound(std::string sound);
    void setRollTimes(int rollTimes);
  protected:
    // variables
    std::string name;
    std::string sound;
    int rollTimes;

};

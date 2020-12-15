#include <iostream>

class Instrument
{
  public: //members
    // constructor and destructor
    Instrument(std::string name, std::string sound, int pitch, int pitch_MIN, int pitch_MAX);

    ~Instrument();

    // methods
    void play();


    // getters and setters
    std::string getSound();
    void setSound(std::string sound);

  protected:
    // variables
    std::string name;
    std::string sound;
    int pitch;
    int pitchMIN;
    int pitchMAX;
};

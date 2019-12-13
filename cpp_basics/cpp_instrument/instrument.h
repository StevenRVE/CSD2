#ifndef _INSTRUMENT_H_
#define _INSTRUMENT_H_
#include <string>
#include <iostream>

class Instrument
{
  public: // members
    // ___constructor_and_destructor__
    Instrument(std::string sound);

    ~Instrument();

    // ___methods___
    void setSound(std::string sound);

    void setPitchRange(int pitchRange);

    void

    void play();

    void roll(int rollTimes);

    void setRollTimes(int rollTimes);

  private:
    // ___variables___
    std::string sound;

    std::string name;

    int pitchRange;

    int pitch;

    int rollTimes;
};

#endif

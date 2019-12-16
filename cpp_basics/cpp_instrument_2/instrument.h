#ifndef _INSTRUMENT_H_
#define _INSTRUMENT_H_
#include <string>
#include <iostream>

class Instrument
{
  public: // members
    // constructor and destructor
    Instrument(std::string sound);

    ~Instrument();

    // methods
    void setSound(std::string sound);

    void setPitchRange(int pitchRange, int lowestNote);

    void play();

    void roll(int rollTimes);

    void setRollTimes(int rollTimes);

  protected:
    // variables
    std::string sound;

    std::string name;

    // pitchRange
    int pitchRange;
    int lowestNote;

    int frequency;

    int rollTimes;

    // ADSR
    int attack;
    int decay;
    double sustain;
    int release;
};

#endif

#ifndef _INSTRUMENT_H_
#define _INSTRUMENT_H_
#include <string>
#include <iostream>

class Instrument
{
  public: // members
    // ___constructor_and_destructor__
    Instrument(std::string sound, std::string name, int pitchRange, int lowestNote);

    ~Instrument();

    // ___methods___
    void setSound(std::string sound);

    void setFreq(int frequency);
    
    void setAttack(int attack);
    void setDecay(int decay);
    void setSustain(double sustain);
    void setRelease(int release);

    void play();

    void roll(int rollTimes);

    void setRollTimes(int rollTimes);

    void setPitchRange(int pitchRange, int lowestNote);
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

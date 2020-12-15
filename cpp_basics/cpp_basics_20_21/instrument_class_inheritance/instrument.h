#ifndef _INSTRUMENT_H_
#define _INSTRUMENT_H_


class Instrument
{
  public: //members
    // constructor and destructor
    Instrument(std::string name, std::string sound);
    ~Instrument();

    // methods
    void play();

    // getters
    int getPitch();
    void setPitch(std::string sound);

    // setters
    std::string getSound();
    void setSound(std::string sound);

  protected:
    // variables
    std::string name;
    int pitch;
    int pitch_MIN;
    int pitch_MAX;
    std::string sound;
};

#endif

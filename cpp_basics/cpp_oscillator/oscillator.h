
class Oscillator
{
  // public, private, protected
public:
  Oscillator(float freq); // constructor
  ~Oscillator(); // destructor

  void setFreq(float freq); // setter
  float getFreq(); // getter

private:
  float freq;
};

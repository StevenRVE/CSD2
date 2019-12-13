#define SAMPLERATE 44100

class Sine {
public:
  // constructor and destructor
  Sine(float frequency);
  ~Sine()

  // return the current sample
  float getSample();
  // go to next sample
  void tick();

  // getters and setters
  void setFrequency(float frequency);

private:
  float amplitude;
  float frequency;
  float phase;
  float sample;
}

#include <vector>

class MelodyGenerator
{
public:
  // constructor and destructor
  MelodyGenerator();
  ~MelodyGenerator();

  // methods
  void randomSeed();
  double randomFrequency();
  void generateScale(int startPos, int midiBaseValue);
  double mtof(int midiValue);
  double generateMelody();
  // // getters and setters
  // void setFrequency(double frequency);
  // double getFrequency();
  // void setNewFrequency(double newFrequency);
  // double getNewFrequency();

private:
  std::vector<int> scaleFormula {0,2,2,1,2,2,2,1};
  std::vector<int> newScale {};
  int startPos;
  int midiBaseValue;
  int midiValue = 60;
  double frequency;
  double newFrequency;
};

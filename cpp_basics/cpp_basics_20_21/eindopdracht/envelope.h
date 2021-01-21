#ifndef _ENVELOPE_H_
#define _ENVELOPE_H_

class Envelope {
public:
  // constructor
  Envelope(double attack, double decay, double sustain, double release);

  // destructor
  ~Envelope();

  // getters and setters
  double getAttack();
  void setAttack(double attack);

  double getDecay();
  void setDecay(double decay);

  double getSustain();
  void setSustain(double sustain);

  double getRelease();
  void setRelease(double release);

protected:
  double attack;
  double decay;
  double sustain;
  double release;
};

#endif

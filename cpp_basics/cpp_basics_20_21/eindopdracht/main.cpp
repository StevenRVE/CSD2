// libraries
#include <iostream>
#include <string>
#include <thread>
#include <ctime>
#include <chrono>
#include "jack_module.h"
#include "math.h"

// OSCILLATORS
#include "oscillator.h"
#include "sine.h"
#include "square.h"
#include "saw.h"

// SYNTHS
#include "synthesizer.h"

// FM, AM, LFO
// #include "clock.h"

// MelodyGenerator
#include "melodyGenerator.h"

// define PI * 2
#define PI_2 6.28318530717959

int main(int argc,char **argv)
{
  // -create a JackModule instance-
  JackModule jack;

  int clock1;
  int clock2;

  // -init the jack, use program name as JACK client name-
  jack.init(argv[0]);
  double samplerate = jack.getSamplerate();

  // -create a synth instance with frequency
  Synthesizer synth1 (440, samplerate);
  Synthesizer synth2 (220, samplerate);

  Oscillator* osc1 = synth1.chooseOsc(3);
  Oscillator* osc2 = synth2.chooseOsc(1);

  MelodyGenerator melody1;
  melody1.randomSeed();
  melody1.generateScale(3, 60);

  MelodyGenerator melody2;
  melody2.randomSeed();
  melody2.generateScale(3, 48);

  // -assign a function to the JackModule::onProces-
  jack.onProcess = [&](jack_default_audio_sample_t *inBuf,
     jack_default_audio_sample_t *outBuf, jack_nframes_t nframes) {

    for(unsigned int i = 0; i < nframes; i++) {
      outBuf[i] = (osc1->getSample()* 0.2) + (osc2->getSample() * 0.5 );
      osc1->setFrequency(synth1.getFrequency());
      osc2->setFrequency(synth2.getFrequency());
      osc1->tick();
      osc2->tick();

      if(i == 255){
        clock1 += 1;
        clock2 += 1;

        if (clock1 == 50){
          clock1 = 0;
          int x = melody1.generateMelody();
          synth1.setFrequency(x);
        }
        if (clock2 == 100){
          clock2 = 0;
          int x = melody2.generateMelody();
          synth2.setFrequency(x);
        }
      }
    }

    return 0;
  };

  jack.autoConnect();

  // -keep the program running and listen for user input, q = quit -
  std::cout << "\n\nPress 'q' when you want to quit the program.\n";
  bool runningQ = true;
  while (runningQ)
  {
    switch (std::cin.get())
    {
      case 'q':
        runningQ = false;
        jack.end();
        break;
    }
  }

  // // -keep the program running and listen for user input, q = quit -
  // std::cout << "\n\nPress 'g' when you want to quit the program.\n";
  // bool runningG = true;
  // while (runningG)
  // {
  //   switch (std::cin.get())
  //   {
  //     case 'g':
  //       melody.generateMelody();
  //   }
  // }

  // -end the program-
  return 0;
} // main()

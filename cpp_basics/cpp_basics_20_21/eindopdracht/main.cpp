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
// #include "melodyGenerator.h"

// define PI * 2
#define PI_2 6.28318530717959

int main(int argc,char **argv)
{
  // -create a JackModule instance-
  JackModule jack;

  // -init the jack, use program name as JACK client name-
  jack.init(argv[0]);
  double samplerate = jack.getSamplerate();

  // -create a synth instance with frequency
  Synthesizer synth (440, samplerate);

  Oscillator* osc1 = synth.chooseOsc(1);
  Oscillator* osc2 = synth.chooseOsc(2);

  synth.setFrequency(220);

  // MelodyGenerator melody;


  // -assign a function to the JackModule::onProces-
  jack.onProcess = [&](jack_default_audio_sample_t *inBuf,
     jack_default_audio_sample_t *outBuf, jack_nframes_t nframes) {

    for(unsigned int i = 0; i < nframes; i++) {
      outBuf[i] = (osc1->getSample()* 0.9) + (osc2->getSample() * 0.2 );
      osc1->setFrequency(synth.getFrequency());
      osc2->setFrequency(synth.getFrequency());
      osc1->tick();
      osc2->tick();
    }

    return 0;
  };

  jack.autoConnect();

  // -keep the program running and listen for user input, q = quit -
  std::cout << "\n\nPress 'q' when you want to quit the program.\n";
  bool running = true;
  while (running)
  {
    switch (std::cin.get())
    {
      case 'q':
        running = false;
        jack.end();
        break;
    }
  }

  // -end the program-
  return 0;
} // main()

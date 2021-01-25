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

// MelodyGenerator
#include "melodyGenerator.h"

// define PI * 2
#define PI_2 6.28318530717959

int main(int argc,char **argv)
{
  // create a JackModule instance
  JackModule jack;

  // clock variables
  int clock1;
  int clock2;
  int clock3;
  int clockTime1;
  int clockTime2;
  int clockTime3;

  // user input variables
  int userInput1;
  int userInput2;
  int userInput3;
  int chooseWaveShape;

  bool leadSynthOn = false;
  bool bassSynthOn = false;
  bool fmSynthOn = false;

  // Ask user input to choose which Synth to use
  std::cout << "\n"
            <<"This is Steven's C++ synthesizer\n"
            << "First, let's choose which synth you want to use.\n"
            << "________________________________________________\n"
            << "Press 1: LeadSynth\n"
            << "Press 2: BassSynth\n"
            << "Press 3: LeadSynth and BassSynth\n"
            << "Press 4: FM Synth\n"
            << "Enter answer here and press ENTER: ";

  std::cin >> userInput1;

  if (userInput1 == 1 || userInput1 == 2 || userInput1 == 3 || userInput1 == 4){
    if (userInput1 == 1){
      leadSynthOn = true;
      std::cout << "You choose the LeadSynth" << "\n";
    }
    else if (userInput1 == 2){
      bassSynthOn = true;
      std::cout << "You choose the bassSynth" << "\n";
    }
    else if(userInput1 == 3){
      leadSynthOn = true;
      bassSynthOn = true;
      std::cout << "You choose the LeadSynth and BassSynth" << "\n";
    }
    else if(userInput1 == 4){
      fmSynthOn = true;
      std::cout << "You choose the FM Synth" << "\n";
    }
    else {
      std::cout << "Sorry that wasn't what I requested. ";
      return 0;
    }
  }

  // Ask user how fast they want the melody to play
  std::cout << "\n"
            <<"The melodyGenerator will generate a melody.\n"
            <<"How fast do you want it to play?\n"
            << "Press 1: slow\n"
            << "Press 2: medium\n"
            << "Press 3: fast\n"
            << "Enter answer here and press ENTER: ";

    std::cin >> userInput2;

    if (userInput2 == 1 || userInput2 == 2 || userInput2 == 3){
      if (userInput2 == 1){
        clockTime1 = 100;
        clockTime2 = 200;
        clockTime3 = 100;
        std::cout << "You choose slow" << "\n";
      }
      else if (userInput2 == 2){
        clockTime1 = 50;
        clockTime2 = 100;
        clockTime3 = 50;
        std::cout << "You choose medium" << "\n";
      }
      else if(userInput2 == 3){
        clockTime1 = 25;
        clockTime2 = 50;
        clockTime3 = 25;
        std::cout << "You choose fast" << "\n";
      }
      else {
        std::cout << "Sorry that wasn't what I requested.";
        return 0;
      }
    }

  // Ask user which waveshape they want to use
  std::cout << "\n"
            <<"Which waveshapes do you want to use?\n"
            << "Press 1: sine\n"
            << "Press 2: square\n"
            << "Press 3: saw\n"
            << "Enter answer here and press ENTER: ";

  std::cin >> userInput3;

  if (userInput3 == 1 || userInput3 == 2 || userInput3 == 3){
    chooseWaveShape = userInput3;
  }
  else {
    std::cout << "Sorry that wasn't what I requested.";
    return 0;
  }

  std::cout << "leadSynthOn: " << leadSynthOn << "\n"
            << "bassSynthOn: " << bassSynthOn << "\n"
            << "fmSynthOn: " << fmSynthOn << "\n";

  // init the jack, use program name as JACK client name
  jack.init(argv[0]);
  double samplerate = jack.getSamplerate();

  // create synth instances with frequency
  // leadSynth
  Synthesizer leadSynth (440, samplerate);
  // bassSynth
  Synthesizer bassSynth (440, samplerate);

  // FM Synth
  Synthesizer fmSynthCarrier(440, samplerate);
  Synthesizer fmSynthModular(440, samplerate);
  double fmRatio = 2;

  // create oscillators and choose waveforms
  Oscillator* oscLeadSynth = leadSynth.chooseOsc(chooseWaveShape);
  Oscillator* oscBassSynth = bassSynth.chooseOsc(chooseWaveShape);

  Oscillator* fmOscCarrier = fmSynthCarrier.chooseOsc(chooseWaveShape);
  Oscillator* fmOscModular = fmSynthModular.chooseOsc(chooseWaveShape);

  // create melodyGenerators and generate 3 different melody's
  MelodyGenerator melody1;
  melody1.randomSeed();
  melody1.generateScale(1, 72);

  MelodyGenerator melody2;
  melody2.generateScale(1, 36);

  MelodyGenerator melody3;
  melody3.generateScale(6, 60);

  // assign a function to the JackModule::onProces
  jack.onProcess = [&](jack_default_audio_sample_t *inBuf,
     jack_default_audio_sample_t *outBuf, jack_nframes_t nframes) {

    for(unsigned int i = 0; i < nframes; i++) {
      outBuf[i] = (oscLeadSynth->getSample()* 0.2) + (oscBassSynth->getSample() * 0.4 )
                    + ((fmOscCarrier->getSample() * fmOscModular->getSample())/4);
      oscLeadSynth->setFrequency(leadSynth.getFrequency());
      oscBassSynth->setFrequency(bassSynth.getFrequency());
      fmOscCarrier->setFrequency(fmSynthCarrier.getFrequency());
      fmOscModular->setFrequency(fmSynthModular.getFrequency());

      if (leadSynthOn == true){
        oscLeadSynth->tick();
      }
      if (bassSynthOn == true){
        oscBassSynth->tick();
      }
      if (fmSynthOn == true){
        fmOscCarrier->tick();
        fmOscModular->tick();
      }

      // count+=1 every 255 nFrames (this is roughly every 5.7 milliseconds)
      if(i == 255){
        clock1 += 1;
        clock2 += 1;
        clock3 += 1;

        // generate new melody notes for every oscillator at seperate times
        if (clock1 == clockTime1){
          clock1 = 0;
          double newFrequency = melody1.generateMelody();
          leadSynth.setFrequency(newFrequency);
        }
        if (clock2 == clockTime2){
          clock2 = 0;
          double newFrequency = melody2.generateMelody();
          bassSynth.setFrequency(newFrequency);
        }
        if (clock3 == clockTime3){
          clock3 = 0;
          double newFrequency = melody3.generateMelody();
          fmSynthCarrier.setFrequency(newFrequency);
          fmSynthModular.setFrequency(newFrequency*fmRatio);
        }
      }
    }

    return 0;
  }; // jack.onProcess

  jack.autoConnect();

  // keep the program running and listen for user input, q = quit
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

  // end the program
  return 0;
} // main()

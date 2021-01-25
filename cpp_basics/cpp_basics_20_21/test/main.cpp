#include <iostream>
#include <string.h>

int main()
{
  string userInput1;
  int userInput2;
  int userInput3;
  bool leadSynthOn = false;
  bool bassSynthOn = false;
  bool fmSynthOn = false;

  // Ask user input
  std::cout << "\n"
            <<"This is Steven's cpp synthesizer\n"
            << "First, let's choose which synth you want to use.\n"
            << "________________________________________________\n"
            << "Press 1: for LeadSynth\n"
            << "Press 2: for BassSynth\n"
            << "Press 3: for LeadSynth and BassSynth\n"
            << "Press 4: for FM Synth\n"
            << "Press 5: for chaos\n";

  std::cin >> userInput1;
  std::cout << userInput1 << "\n";

  if (userInput1 == 1 || userInput1 == 2 || userInput1 == 3 || userInput1 == 4 || userInput1 == 5){
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
    else if(userInput1 == 5){
      leadSynthOn = true;
      bassSynthOn = true;
      fmSynthOn = true;
      std::cout << "Here comes the choas!" << "\n";
    }
  } else {
    std::cout << "Sorry that wasn't what I requested. Please enter an integer value from 1-5.";
    std::cin >> userInput1;
  }

return 0;
}

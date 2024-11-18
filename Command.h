#ifndef COMMAND_H
#define COMMAND_H

#include <cstring>
#include <vector>

using namespace std;



class Command {
 public:
  //Methods
  Command(char firstWord[], char secondWord[]);
  char* getCommandWord();
  char* getSecondWord();
  bool isUnknown(); //if the command entered is unkown/not valid
  bool hasSecondWord(); //if the commmand is able to have a second word input
  
private:
  //Variables

  char commandWord[20];
  char secondWord[20];
};

#endif

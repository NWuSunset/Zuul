#include <cstring>
#include <iostream>
#include "Command.h"

using namespace std;

Command::Command(char firstWord[], char secondWord[]) {
  strcpy(commandWord, firstWord);
  strcpy(this->secondWord, secondWord);
}

char* Command::getCommandWord() {
  char* toReturn = commandWord;
  return toReturn;
}

char* Command::getSecondWord() {
  char* toReturn = secondWord;
  return toReturn;
}

bool Command::isUnknown() { //returning true if commandWord is NULL (test if it works) 
  return (commandWord == NULL);
}

bool Command::hasSecondWord() {
  return (secondWord != NULL);
}


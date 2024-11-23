#include <cstring>
#include <iostream>
#include "Command.h"

using namespace std;

//Handles commands
Command::Command(char firstWord[], char secondWord[]) {
  if (firstWord != nullptr) {
  strcpy(commandWord, firstWord);
  strcpy(this->secondWord, secondWord);
  }
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
  return (commandWord == nullptr);
}

bool Command::hasSecondWord() {
  return (secondWord[0] != '\0');
}


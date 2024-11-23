#include "CommandWords.h"
#include <cstring>
#include <iostream>

using namespace std;

//Holds the list of commands basically
CommandWords::CommandWords() = default;

void CommandWords::listCommands() {
  //list all the available commands
  for (int i = 0; i < comNum - 1; i++) {
    cout << validCommands[i] << ", ";
  }
  cout << validCommands[comNum - 1] << "." << endl; //the last command end with a period
}

bool CommandWords::isCommand(char command[]) {
  //Loop through commands
  for (int i = 0; i < comNum; i++) {
    if (strcasecmp(command, validCommands[i]) == 0) {
        return true; //will return true if one of the commands matches
      }
  }
  return false;
}


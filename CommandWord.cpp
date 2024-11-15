#include "CommandWords.h"
#include <cstring>
#include <iostream>

using namespace std;

CommandWords::CommandWords() {

}

void CommandWords::listCommands() {
  //list all the avalible commands
  for (int i = 0; i < comNum - 1; i++) {
    cout << validCommands[i] << ", ";
  }
  cout << validCommands[comNum - 1] << "." << endl; //the last command end with a period
}

bool CommandWords::isCommand(char command[]) {
  //Loop through commands
  for (int i = 0; i < comNum; i++) {
    if (strcmp(command, validCommands[i]) == 0) {
        return true; //will return true if one of the commands matches
      }
  }
  return false;
}


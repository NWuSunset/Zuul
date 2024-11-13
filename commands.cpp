#include <cstring>
#include "commands.h"

using namespace std;

commands::commands() {
  //add commands to the validCommand array
  strcpy(validCommands[0], "go");
  strcpy(validCommands[1], "quit");
  strcpy(validCommands[2], "help");
  strcpy(validCommands[3], "inventory");
  strcpy(validCommands[4], "get");
  strcpy(validCommands[5], "drop");
  strcpy(validCommands[6], "listrooms");
}

void commands::listCommands() {
  //list all the avalible commands
}

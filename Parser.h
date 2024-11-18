#include <cstring>
#include "CommandWords.h"
#include "Command.h"
using namespace std;


//Making a parser class for practice. And to make getting commands from the player easier
class Parser {
 public:
  Parser();
  Command* getCommand();

private:
  CommandWords* newCommand = new CommandWords();
  char input[40]; 
  char firstWord[20];
  char secondWord[20];
};

#include <cstring>
#include <vector>

using namespace std;



class CommandWords {
 public:
  //Methods
  CommandWords();
  void listCommands();
  bool isCommand(char command[]);

private:
  //Variables
  char validCommands[7][20] = {"go", "quit", "help", "inventory", "get", "drop", "listrooms"}; //array of cstring
  int comNum = 7; //number of commands
};

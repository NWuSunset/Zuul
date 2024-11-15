#include "Parser.h"
#include <iostream>
#include <cstring>

Parser::Parser() {
  
}

CommandWords* getCommand() {
  cin.getline(input, 40);
}

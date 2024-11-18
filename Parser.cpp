#include "Parser.h"
#include <iostream>
#include <cstring>

Parser::Parser() {
  
}

Command* Parser::getCommand() { 
  cin.getline(input, 40);

  int split = 0;
  //Split at a space to get the first and second words
  while (!isspace(input[split])) { //incriment until we hit a space
	split++; 
      }   

      for (int i = 0; i < split; i++) { //Add the first word to it's own array
	firstWord[i] = input[i];
      }
      //firstWord[split] = '\0'; //add null character to the end

      for (int i = split+1; i < strlen(input); i++) { //Add second Word to it's own array
	secondWord[i] = input[i];
      }
      //secondWord[strlen(input)] = '\0';
      
      if (newCommand->isCommand(firstWord)) {
	return new Command(firstWord, secondWord);
      } else {

      }
  }


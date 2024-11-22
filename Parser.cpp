#include "Parser.h"
#include <iostream>
#include <cstring>

Parser::Parser() {
  
}

Command* Parser::getCommand() { 
  cin.getline(input, 40);

  char* token = strtok(input, " "); //find first word as before a space
  if (token != NULL) { //If the first word exists
    strcpy(firstWord, token); //then copy it into the first word cstring
    cout << token << endl;
  } else {
    firstWord[0] = '\0'; //Set firstWord null  if token is null
  }


  //move onto the next token. Null indicates using the same pointer to the input
  token = strtok(NULL, " "); 
  if (token != NULL) { //Now check the second word
    strcpy(secondWord, token);
      cout << token << endl;
  } else {
    secondWord[0] = '\0'; //basically set it to NULL/isn't valid
  }

  // Remove spaces from the second word
    char* temp = strtok(NULL, " ");
	    while (temp != NULL) {
	    strcat(secondWord, temp);
	    temp = strtok(NULL, " ");
	  }
  
  
  /*
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
      */

  
      //Check if the firstCommand is valid, and has a second valid command
      if (newCommand->isCommand(firstWord)) { //if the first word is valid 
	return new Command(firstWord, secondWord);
      } else {
	return new Command(NULL, secondWord); //Command is invalid (null command)
      }
  }

void Parser::showCommands() { //So we can call list commands through a parser
  newCommand->listCommands();
}


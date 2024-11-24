#include "Parser.h"
#include <iostream>
#include <cstring>

Parser::Parser() = default;

//Parser splits commands into separate parts and passes them back.
Command* Parser::getCommand() {
    cin.getline(input, 40);

    char* token = strtok(input, " "); //find first word (word before the first space)
    if (token != nullptr) {
        //If the first word exists
        strcpy(firstWord, token); //then copy it into the first word cstring
    } else {
        firstWord[0] = '\0'; //Set firstWord null  if token is null
    }
    //cout << firstWord << endl;

    //move onto the next token. Null indicates using the same pointer to the input
    token = strtok(nullptr, " ");
    if (token != nullptr) {
        //Now check the second word
        strcpy(secondWord, token);

        // Remove spaces from the second word
        char* temp = strtok(nullptr, " "); //temp is the second word in the string
        while (temp != nullptr) {
            //while we still have words in the string
            strcat(secondWord, temp); //combine the cstring together
            temp = strtok(nullptr, " "); //then move onto the next word
        }
    } else {
        secondWord[0] = '\0'; //basically set it to NULL/isn't valid
    }
    //cout << secondWord << endl;
    //Check if the firstCommand is valid, and has a second valid command
    if (newCommand->isCommand(firstWord)) {
        //if the first word is valid
        return new Command(firstWord, secondWord);
    }
    return new Command(nullptr, secondWord); //Command is invalid (null command)
}

void Parser::showCommands() {
    //So we can call list commands through a parser
    newCommand->listCommands();
}

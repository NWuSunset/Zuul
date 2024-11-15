#include <iostream>
#include <cstring>
#include <vector>
#include "Rooms.h"
#include "Command.h"
#include "Parser.h"

int main() {
  char testChar[20] = "Test Char";
  bool gameEnd = false;
  
  vector<Rooms*> rooms;
  char roomName[20];
  char itemName[20]; //separate arrays for rooms and items for clarity
  char exitDir[20];
  
  strcpy(roomName, "Test Room"); //copy the string into the roomName array
  Rooms* testRoom = new Rooms(roomName); //so it can be passed in as a cstring
  rooms.push_back(testRoom);

  strcpy(itemName, "Test Item");
  testRoom->setItem(itemName);

  strcpy(roomName, "Room 2");
  Rooms* testRoom2 = new Rooms(roomName);
  rooms.push_back(testRoom2);

  strcpy(exitDir, "NORTH"); 
  testRoom->setExit(exitDir, testRoom2);

  cout << "debug" << endl; //to set a breakpoint to

  Parser newParser;

  newParser.getCommand();
  
  while (!gameEnd) {
    //commands* newCommand = Parser->getCommand();
    //gameEnd = processCommand(newCommand);
  }
  return 0;
}

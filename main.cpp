#include <iostream>
#include <cstring>
#include <vector>
#include "Rooms.h"
#include "commands.h"

int main() {
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
  return 0;
}

#include <iostream>
#include <cstring>
#include <vector>
#include "Rooms.h"
#include "Command.h"
#include "Parser.h"

void createRooms(vector<Rooms*> &);


int main() {
  Parser parser; //Parser can remain on the stack
  Rooms currentRoom; //and current room
  
  /*Rooms* outside, theatre, pub, bathroomOne, lab, office, computerLab, physics, chemistry, biology, language,
    cafeteria, secretRoom, math, bathroomTwo, english, engineeringLab; List of all the rooms */
  
  bool gameEnd = false;

  
  vector<Rooms*> rooms;
  char roomName[20];
  char itemName[20]; //separate arrays for rooms and items for clarity
  char exitDir[20];
  
  createRooms(rooms);
  
  while (!gameEnd) {
    //commands* newCommand = Parser->getCommand();
    //gameEnd = processCommand(newCommand);
  }
  return 0;
}

void createRooms(vector<Rooms*> &rooms) {
  char roomDir[20];
  char itemName[20];
  char exitDir[20];

  strcpy(roomDir, "You are on the outside of the school");
  Rooms* outside = new Rooms(roomDir);
  rooms.push_back(outside);

  strcpy(roomDir, "You are in the theater room");
  Rooms* theater = new Rooms(roomDir);
  rooms.push_back(theater);

  strcpy(roomDir, "You are now in the student store");
  Rooms* studentStore = new Rooms(roomDir);
  rooms.push_back(studentStore);

  strcpy(roomDir, "You are in Bathroom one");
  Rooms* bathroomOne = new Rooms(roomDir);
  rooms.push_back(bathroomOne);

  strcpy(roomDir, "You are in the science lab");
  Rooms* lab = new Rooms(roomDir);
  rooms.push_back(lab);

  //continue adding more rooms.
}

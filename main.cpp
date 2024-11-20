#include <iostream>
#include <cstring>
#include <vector>
#include "Rooms.h"
#include "Command.h"
#include "Parser.h"

void createRooms(vector<Rooms*> &, Rooms* &currentRoom);
bool executeCommand(Command* command);

int main() {
  Parser* parser = new Parser; //Parser
  Rooms* currentRoom; //and current room 
  bool gameEnd = false;

  vector<Items*> inventory; //vector of item pointers
  vector<Rooms*> rooms; //vector of room pointers
  char roomName[20];
  char itemName[20]; //separate arrays for rooms and items for clarity
  char exitDir[20];
  
  createRooms(rooms, currentRoom);


  //Print the game intro screen


  //Play the game
  while (!gameEnd) { //keep playing until the game ends
    cout << "S+EHROWEHRO" << endl;
    Command* command = parser->getCommand();
    gameEnd = executeCommand(command); //wait for the quit command basically
  }
  return 0;
}

bool executeCommand(Command* command) {
  bool quit = false;


  return quit;
}



void createRooms(vector<Rooms*> &rooms, Rooms* &currentRoom) {
  char roomDir[40];
  char itemName[20];
  char exitDir[20];

  char NORTH[] = "NORTH";
  char SOUTH[] = "SOUTH";
  char EAST[] = "EAST";
  char WEST[] = "WEST";

  //adding 
  strcpy(roomDir, "You are on the outside of the school");
  Rooms* outside = new Rooms(roomDir);
  rooms.push_back(outside);

  strcpy(roomDir, "You are in the theater room");
  Rooms* theater = new Rooms(roomDir);
  rooms.push_back(theater);

  strcpy(roomDir, "You are now in the student store");
  Rooms* studentStore = new Rooms(roomDir);
  studentStore->toggleLock(); //Lock the student store
  rooms.push_back(studentStore);

  strcpy(roomDir, "You are in Bathroom one");
  Rooms* bathroomOne = new Rooms(roomDir);
  rooms.push_back(bathroomOne);

  strcpy(roomDir, "You are in the science lab");
  Rooms* lab = new Rooms(roomDir);
  rooms.push_back(lab);

  strcpy(roomDir, "You are in the office");
  Rooms* office = new Rooms(roomDir);
  rooms.push_back(office);

  strcpy(roomDir, "You are in the computer lab");
  Rooms* computerLab = new Rooms(roomDir);
  rooms.push_back(computerLab);

  strcpy(roomDir, "You are in the physics lab");
  Rooms* physics = new Rooms(roomDir);
  rooms.push_back(physics);

  strcpy(roomDir, "You are in the chemistry lab");
  Rooms* chemistry = new Rooms(roomDir);
  rooms.push_back(chemistry);

  strcpy(roomDir, "You are in the biology lab");
  Rooms* biology = new Rooms(roomDir);
  rooms.push_back(biology);

  strcpy(roomDir, "You are in the language room");
  Rooms* language = new Rooms(roomDir);
  rooms.push_back(language);

  strcpy(roomDir, "You are in the cafeteria");
  Rooms* cafeteria = new Rooms(roomDir);
  rooms.push_back(cafeteria);
 
  strcpy(roomDir, "You are in a secret room");
  Rooms* secretRoom = new Rooms(roomDir);
  secretRoom->toggleLock(); //secret room is locked
  rooms.push_back(secretRoom);

  strcpy(roomDir, "You are in the math room");
  Rooms* math = new Rooms(roomDir);
  rooms.push_back(math);

  strcpy(roomDir, "You are in bathroom two");
  Rooms* bathroomTwo = new Rooms(roomDir);
  rooms.push_back(bathroomTwo);

  strcpy(roomDir, "You are in the english room");
  Rooms* english = new Rooms(roomDir);
  rooms.push_back(english);

  strcpy(roomDir, "You are in the engineering lab");
  Rooms* engineeringLab = new Rooms(roomDir);
  rooms.push_back(engineeringLab);

  //Room exits
  outside->setExit(EAST, theater);
  outside->setExit(WEST, studentStore);
  outside->setExit(NORTH, computerLab);
  outside->setExit(SOUTH, lab);

  theater->setExit(WEST, outside);
  theater->setExit(EAST, math);
  theater->setExit(NORTH, bathroomTwo);

  studentStore->setExit(EAST, outside);
  studentStore->setExit(WEST, bathroomOne);

  bathroomOne->setExit(EAST, studentStore);

  lab->setExit(NORTH, outside);
  lab->setExit(SOUTH, chemistry);
  lab->setExit(EAST, office);
  lab->setExit(WEST, physics);

  office->setExit(EAST, language);
  office->setExit(WEST, lab);

  computerLab->setExit(SOUTH, outside);
  computerLab->setExit(EAST, english);
  computerLab->setExit(WEST, engineeringLab);

  physics->setExit(EAST, lab);

  chemistry->setExit(NORTH, lab);
  chemistry->setExit(SOUTH, biology);

  biology->setExit(NORTH, chemistry);

  language->setExit(EAST, cafeteria);
  language->setExit(WEST, office);

  cafeteria->setExit(NORTH, math);
  cafeteria->setExit(EAST, secretRoom);
  cafeteria->setExit(WEST, language);

  secretRoom->setExit(WEST, cafeteria);

  math->setExit(NORTH, english);
  math->setExit(SOUTH, cafeteria);
  math->setExit(WEST, theater);

  bathroomTwo->setExit(NORTH, english);
  bathroomTwo->setExit(SOUTH, theater);

  english->setExit(SOUTH, bathroomTwo);
  english->setExit(EAST, math);
  english->setExit(WEST, computerLab);

  engineeringLab->setExit(EAST, computerLab);

  currentRoom = outside; //currentRoom pointer points to outside to start
  
  //items
  Items* iphone = new Items;
  strcpy(iphone->description, "Broken Iphone");

  strcpy(itemName, "Funny device");
  computerLab->setItem(itemName);

  strcpy(itemName, "Student Store key");
  chemistry->setItem(itemName);

  strcpy(itemName, "Snack Pass"); //if player has the snack pass they get obtain snacks in the secret room
  studentStore->setItem(itemName);

  strcpy(itemName, "Lock Pick");
  engineeringLab->setItem(itemName);

  strcpy(itemName, "Snacks");
}

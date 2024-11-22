#include <iostream>
#include <cstring>
#include <vector>
#include "Rooms.h"
#include "Command.h"
#include "Parser.h"

void createRooms(vector<Rooms*> &, Rooms* &currentRoom, vector<Items*> &inventory);
bool executeCommand(Command* command, vector<Items*> &inventory, Rooms* &currentRoom, Parser* parser);
void printHelp(Parser* parser);
bool goRoom(Command* command, Rooms* &currentRoom);
bool quit(Command* command);
void printInventory(vector<Items*> &inventory);
bool getItem(Command* command, vector<Items*> &inventory, Rooms* &currentRoom);
bool dropItem(Command* command, vector<Items*> &inventory, Rooms* &currentRoom);
void listRooms();
bool hasItem(char item[], vector<Items*> &inventory);

int main() {
  Parser* parser = new Parser; //Parser
  Rooms* currentRoom; //and current room 
  bool gameEnd = false;

  vector<Items*> inventory; //vector of item pointers
  vector<Rooms*> rooms; //vector of room pointers
  char roomName[20];
  char itemName[20]; //separate arrays for rooms and items for clarity
  char exitDir[20];
  
  createRooms(rooms, currentRoom, inventory);


  //Print the game intro screen


  //Go to Chem room to get student store key. Go to student store to get snack pass. Go to engineering lab to get lockpick. Unlock secret rooms and have snack pass to win.
  //Play the game
  while (!gameEnd) { //keep playing until the game ends
    cout << "S+EHROWEHRO" << endl;
    Command* command = parser->getCommand();
    gameEnd = executeCommand(command, inventory, currentRoom, parser); //wait for the quit command basically
  }
  return 0;
}

bool executeCommand(Command* command, vector<Items*> &inventory, Rooms* &currentRoom, Parser* parser) {
  bool wantToQuit = false;
  char commandWord[20];
  if (command->isUnknown()) {
    cout << "Unknown command.." << endl;
  }

  strcpy(commandWord, command->getCommandWord()); 
  
  if (strcasecmp(commandWord, "help") == 0) { //if the command is help
    //Print help.
    printHelp(parser);
  } else if (strcasecmp(commandWord, "go") == 0) {
    wantToQuit = goRoom(command, currentRoom);
  } else if (strcasecmp(commandWord, "quit") == 0) {
    wantToQuit = quit(command);
  } else if (strcasecmp(commandWord, "inventory") == 0) {
    printInventory(inventory);
  } else if (strcasecmp(commandWord, "get") == 0) {
    wantToQuit = getItem(command, inventory, currentRoom);
  } else if (strcasecmp(commandWord, "drop") == 0) {
    dropItem(command, inventory, currentRoom);
  } else if (strcasecmp(commandWord, "listrooms") == 0) {
    listRooms();
  }
  return wantToQuit;
}

bool goRoom(Command* command, Rooms* &currentRoom) {
  char direction[20];
  if (!command->hasSecondWord()) {
    cout << "Go where?" << endl;
    return false;
  }

  strcpy(direction, command->getSecondWord());

  Rooms* nextRoom = currentRoom->getExit(direction);

  if (nextRoom == nullptr) { //check if this will actually ever be null in the rooms.cpp
    cout << "There is no exit that way" << endl;
  } else if (strcasecmp(nextRoom->getDescription(), "You are now in the student store") == 0 && nextRoom->isLocked()) {
    cout << "Hmm. The student store is locked, I wonder if there is a key lying around somewhere" << endl;
  } else if (strcasecmp(nextRoom->getDescription(),  "You are in a secret room") == 0 && nextRoom->isLocked()) {
    cout << "Hmm. This door is locked. I wonder where I could find a lockpick" << endl;
    } else {
    currentRoom = nextRoom; //go to the next room.
    cout << currentRoom->getDescription();
  }
return false;
}


bool getItem(Command* command, vector<Items*> &inventory, Rooms* &currentRoom) {
  char item[20];

  if (!command->hasSecondWord()) {
    cout << "Get what?" << endl;
    return false;
  }

  strcpy(item, command->getSecondWord());

  //get the item.
  Items* newItem = currentRoom->getItem(item);

  if (newItem == nullptr) {
    cout << "That item isn't here" << endl;
  } else {

    //Check if we have the win condition in the inventory
    
    if (!hasItem(item, inventory)) {
      cout << "You need a snack pass to get the snacks here. I wonder what place would have a snack pass, probably somewhere with a lot of snacks" << endl;
	return false;
      }

    //Put in inventory
    inventory.push_back(newItem);
    currentRoom->removeItem(item);
    cout << "Picked up: " << item << endl;

    //check if the item was for progression (give hints to the player)
    if (strcasecmp(item, "Student Store key") == 0 ) {

    } else if (strcasecmp(item, "Snack Pass") == 0 ) {

    } else if (strcasecmp(item, "Lock Pick") == 0 ) {

    } else if (strcasecmp(item, "Snacks") == 0 ) {
      cout << "You go some good snacks! You WIN!" << endl;
      return true; //will end the game
    }
  }
  return false;
}

bool dropItem(Command* command, vector<Items*> &inventory, Rooms* &currentRoom) {
  char item[20];
  bool inInv = false;
  int itemIndex = -1;

  if (!command->hasSecondWord()) {
    cout << "Drop what?" << endl;
    return false;
  }

  strcpy(item, command->getSecondWord()); //create a cstring of the item

  //loop through the inventory and drop the respective item.
  for (vector<Items*>::iterator it = inventory.begin(); it != inventory.end(); it++) {
    if (strcasecmp((*it)->getDescription(), item) == 0) {
      itemIndex = it - inventory.begin();
      inInv = true;
      break;
    }
  }

  if (!inInv) {
    cout << "That isn't in your inventory" << endl;
  } else {
    //Delete the item pointer of the inventory
    delete(inventory.at(itemIndex));
    inventory.erase(inventory.begin() + itemIndex); //remove it from the vector
    //Add that item to the room (will create a new item pointer)
    currentRoom->setItem(item);
    cout << "Dropped: " << item << endl;
  }
  return false;
}

void printInventory(vector<Items*> &inventory) {
  cout << "You are carrying: " << endl;
  for (vector<Items*>::iterator it = inventory.begin(); it != inventory.end(); it++) {
    cout << (*it)->getDescription();
    cout << ", ";
  }
}

void printHelp(Parser* parser) {
  char input[20];

  cout << "You are in a school and are kinda hungry but no one seems to be here" << endl;
  cout << "List of commands you can do: " << endl;
  parser->showCommands();

  cout << "\n" << "Do you want a hint on what to do? (yes, no)" << endl;
  cin.getline(input, 20);
  if (strcasecmp(input, "yes") == 0) {
    cout << "I hear there may be a secret room in the cafeteria. Maybe there are snacks in there" << endl;
  }
}

void listRooms() {
  char roomList[17][40] = { "Outside", "Theater", "Student Store", "Bathroom one", "Lab", "Office", "Computer Lab", "Physics room",
			"Chemistry room", "Biology room", "Language room", "Cafeteria", "Secret Room (I wonder what's in there)",
			"Math room", "Bathroom two", "English Room", "Engineering lab" };
    for (int i = 0; i < 17; i++) {
      cout << roomList[i] << ", ";
    }
}

bool hasItem(char item[], vector<Items*> &inventory) {
  for (vector<Items*>::iterator it = inventory.begin(); it != inventory.end(); it++) {
    if (strcasecmp((*it)->getDescription(), item) == 0) {
      return true;
    }
  }
  return false;
}

bool quit(Command* command) {
  if (command->hasSecondWord()) {
    cout << "If you actually want to quit only type 'Quit' in the input"  << endl;
    return false;
  } else {
    return true; //quits the game
  }
}


void createRooms(vector<Rooms*> &rooms, Rooms* &currentRoom, vector<Items*> &inventory) {
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
  inventory.push_back(iphone);
  
  strcpy(itemName, "Funny device");
  computerLab->setItem(itemName);

  strcpy(itemName, "Student Store key");
  chemistry->setItem(itemName);

  strcpy(itemName, "Snack Pass"); //if player has the snack pass they get obtain snacks in the secret room
  studentStore->setItem(itemName);

  strcpy(itemName, "Lock Pick");
  engineeringLab->setItem(itemName);

  strcpy(itemName, "Snacks");
  //Go to Chem room to get student store key. Go to student store to get snack pass. Go to engineering lab to get lockpick. Unlock secret rooms and have snack pass to win.

}

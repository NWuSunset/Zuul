#include "Rooms.h"
#include <iostream>
#include <cstring>
#include <map>
#include <vector>

//Class that contains all the things needed for Rooms
Rooms::Rooms(char description[]) { //description of room set on constructor
  strcpy(this->description, description);
  cout << "Room Constructor" << endl;
}

Rooms::Rooms() = default; //empty constructor

void Rooms::setExit(char direction[], Rooms* neighbor) {
  char* temp = new char[20]; //technically allocated memory would be leaked, but rooms are never deleted so it should be fine...
  strcpy(temp, direction);
  exits[temp] = neighbor;
  //exits.insert({temp, neighbor});
}

Rooms* Rooms::getExit(char direction[]) {
  for (pair<char* const, Rooms*> & exit : exits) { //iterate over all exits in the map
    if (strcasecmp(exit.first, direction) == 0) { //exit.first corresponds to the direction char*
      return exit.second; //return the corresponding room
    }
  }
  return nullptr; //return null if there are no exits that direction
}

void Rooms::printRoomExits() { //Telling the player where exits are and what items are in the room
  cout << "Exits: " << endl;
  //get an iterator of the same type of map
  //for (map<char*, Rooms*>::iterator it = exits.begin(); it != exits.end(); it++)
  for (pair<char* const, Rooms*> & exit : exits) { //This does the same thing as above. (iterates through exits)
    cout << exit.first << ", "; //first is the key, second would be the value
  } 
  cout << '\n';  
}

char* Rooms::getDescription() {
  char* toReturn = description;
  return toReturn;
}

void Rooms::getLongDescription() {
  cout << description << endl;
  printRoomExits();
  cout << "Items in room: ";
  printRoomItems();
  cout << endl;
}

void Rooms::setItem(char newItem[]) {
  Items* item = new Items;
  strcpy(item->description, newItem);
  items.push_back(item); //add it to the room's item vector
}

Items* Rooms::getItem(char description[]) { //return an item based on the name
  for (it = items.begin(); it != items.end(); ++it) {
    if (strcasecmp(description, (*it)->description) == 0) { //if the items match
      return *it; //return the item it is pointing to.
    }
  }
  return nullptr; //return null if no items of that name are found
}

void Rooms::removeItem(char description[]) {
  //Loop through room items
  for (it = items.begin(); it != items.end(); ++it) {
     if (strcmp(description, this->description) == 0) {
      delete *it; //delete the item the iterator is pointing to
      items.erase(it); //erase it from the vector
    }
  }
}

void Rooms::printRoomItems() { //Prints out all items in a room
  //Loop through the vector of items
  for (Items* & item : items) { //I just discovered range based loop. (faster to type than an iterator).
    char* output = item->getDescription();
    cout << output << " " << endl;
  }
}

void Rooms::toggleLock() {
  if (!locked) {
    locked = true;
  } else {
    locked = false;
  }
}

bool Rooms::isLocked() {
  return locked;
}

//Rooms destructor is not needed but nice to have just in case :)
Rooms::~Rooms() {
  // Delete allocated memory
  for (pair<char* const, Rooms*>& exit : exits) {
    delete[] exit.first;
  }
  // Free the dynamically allocated memory for items
  for (Items*& item : items) {
    delete item;
  }
}

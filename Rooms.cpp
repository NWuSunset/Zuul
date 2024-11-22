#include "Rooms.h"
#include <iostream>
#include <cstring>
#include <map>
#include <vector>

/*Functionality:
  Entering message/constructor.
  Possible exit paths. (map)
  -Itme Structure Items in rooms (getters + Setters)
  -Room Description
  
 */


Rooms::Rooms(char description[]) { //description of room set on constructor
  strcpy(this->description, description);
  cout << "Room Constructor" << endl;
}

Rooms::Rooms() {
  //Empty constructor
}

void Rooms::setExit(char direction[], Rooms* neighbor) {
  exits.insert({direction, neighbor});
}

Rooms* Rooms::getExit(char direction[]) {
  char* temp = direction;
  return exits[temp];  //return the Room associated with this direction

  //!! check if it returns null when no direction exits for it
}

void Rooms::printRoomExits() { //Telling the player where exits are and what items are in the room
  cout << "Exits: " << endl;
  map<char*, Rooms*>::iterator it; //get an iterator of the same type of map
  for (it = exits.begin(); it != exits.end(); it++) {
    cout << it->first << ", "; //first is the key, secound would be the value
  } 
  cout << '\n';  
}

char* Rooms::getDescription() {
  char* toReturn = description;
  return toReturn;
}

void Rooms::setItem(char newItem[]) { //set an item to the room (this would create a new item)
  Items* item = new Items;
  strcpy(item->description, newItem);
  items.push_back(item); //add it to the room's item vector
}

Items* Rooms::getItem(char description[]) { //return an item based on the name?
  for (it = items.begin(); it != items.end(); it++) {
    if (strcmp(description, this->description) == 0) {
      return *it; //return the item it is pointing to.
    }
  }
  return nullptr; //return null if no items of that name are found
}

void Rooms::removeItem(char description[]) {
  //Loop through room items
  for(it = items.begin(); it != items.end(); it++) {
     if (strcmp(description, this->description) == 0) {
      delete *it; //delete the item the iterator is pointing to
      items.erase(it); //erase it from the vector
    }
  }
}

void Rooms::printRoomItems() { //Prints out all items in a room
  vector<Items*>::iterator it;
  //Loop through the vector of items
  for (it = items.begin(); it != items.end(); it++) {
    char* output = (*it)->getDescription();
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

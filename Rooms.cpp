#include "Rooms.h"
#include <iostream>
#include <cstring>
#include <map>

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

void Rooms::setExits(char direction[], Rooms* neighbor) {
  exits.insert({direction, neighbor});
}

Rooms* Rooms::getExit(char direction[]) {
  char* temp = direction;
  return exits[temp]; //return the Room associated with this direction 
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

void Rooms::setItem(char newItem[]) {
  Items* item = new Items;
  strcpy(item->description, newItem);
}

void Rooms::getItems() {
  
}

void Rooms::removeItem(char item[]) {
  //Loop through room items
}

void Rooms::printRoomItems() {

}

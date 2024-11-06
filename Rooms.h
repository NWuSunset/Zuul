#include <map>

using namespace std;

class Rooms {
public:
  Rooms(char description[]);
  
  struct Items { 
    char description[20];
    char* getDescription() {
      char* toReturn = description;
      return toReturn;
    }
  };

  //Methods
  void setExits(char direction[], Rooms* neighbor);
  Rooms* getExit(char direction[]);
  void printRoomExits();
  char* getDescription();
  void setItem(char newItem[]);
  void getItems();
  void removeItem();
  void printRoomItems();
  
  //Variables
  map<char*, Rooms*> exits; //maping the director to the neighboring room
  vector<Items*> items;
  char description[20];

  
  
};

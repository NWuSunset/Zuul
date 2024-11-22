#include <map>
#include <vector>

using namespace std;

 struct Items {
    char description[20];
    char* getDescription() {
      char* toReturn = description;
      return toReturn;
    }
  };


class Rooms {
public:
  Rooms(char description[]);
  Rooms();

  //Methods
  void setExit(char direction[], Rooms* neighbor);
  Rooms* getExit(char direction[]);
  void printRoomExits();
  char* getDescription();
  void setItem(char newItem[]);
  Items* getItem(char description[]);
  void removeItem(char description[]);
  void printRoomItems();
  void toggleLock();
  bool isLocked();
  
private:
  //Variables
  map<char*, Rooms*> exits; //maping the director to the neighboring room
  vector<Items*> items;
  char description[40];
  vector<Items*>::iterator it; //items iterator
  bool locked = false; //rooms aren't locked by default
};

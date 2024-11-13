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
 

  //Methods
  void setExit(char direction[], Rooms* neighbor);
  char* getExit(char direction[]);
  void printRoomExits();
  char* getDescription();
  void setItem(char newItem[]);
  Items* getItem(char description[]);
  void removeItem(char description[]);
  void printRoomItems();

private:
  //Variables
  map<char*, Rooms*> exits; //maping the director to the neighboring room
  vector<Items*> items;
  char description[20];
  vector<Items*>::iterator it; //items iterator
};

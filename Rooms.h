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
    ~Rooms();

    //Methods
    void setExit(char direction[], Rooms* neighbor);
    Rooms* getExit(char direction[]);
    void printRoomExits();
    char* getDescription();
    void getLongDescription();
    void setItem(char newItem[]);
    Items* getItem(char description[]);
    void removeItem(char description[]);
    void printRoomItems();

private:
    //Variables
    map<char*, Rooms*> exits; //mapping the direction to the neighboring room in that direction
    vector<Items*> items;
    char description[40]{};
    vector<Items*>::iterator it; //items iterator
    bool locked = false; //rooms aren't locked by default
};

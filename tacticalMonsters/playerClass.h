#ifndef PLAYERCLASS_H
#define PLAYERCLASS_H

#include <string>

using namespace std;

class Player {
private:
    string name;
public:

    Player(string playerName);
    string getName() const;
};

#endif // PLAYERCLASS_H

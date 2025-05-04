#include "playerClass.h"

Player::Player(string playerName):name(playerName){}

string Player::getName() const {
    return name;
}

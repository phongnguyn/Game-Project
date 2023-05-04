#include "player.h"
#include <string>

#ifndef WARRIOR_H
#define WARRIOR_H

using namespace std;

class Warrior: public Player
{
private:
    std::string _weapon;
public:
    Warrior(string name, int health, int damage, string weapon);
    void swingWeapon(Player* opponent);
};

#endif
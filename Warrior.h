#include "Player.h"
#include "header.h"

#ifndef WARRIOR_H
#define WARRIOR_H

using namespace std;

class Warrior: public Player
{
private:
    std::string _weapon;
public:
    Warrior(float health, float damage, string weapon, float stamina);
    void swingWeapon(Player* opponent);
};

#endif
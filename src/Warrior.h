#include "Player.h"
#include "header.h"

#ifndef WARRIOR_H
#define WARRIOR_H

class Warrior: virtual public Player
{
private:
    string _weapon;
public:
    Warrior() {}
    Warrior(string);
    void swingWeapon();
};

Warrior::Warrior(string weapon) {_weapon = weapon;}

void Warrior::swingWeapon() {
    if (ShowName()) {cout << __FUNCTION__; return;}
    
    cout << " with a " << _weapon << endl; 
    getOpponent()->takeDamage(20);
}

#endif
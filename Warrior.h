#include "Player.h"
#include "header.h"

#ifndef WARRIOR_H
#define WARRIOR_H

class Warrior: virtual public Player
{
private:
    string _weapon;
public:
    Warrior();
    Warrior(float health, float damage, string weapon, float stamina);
    void swingWeapon();
};

Warrior::Warrior() {}

void Warrior::swingWeapon() {
    if (ShowName()) {cout << __FUNCTION__; return;}
    
    cout << " with a " << _weapon << endl; 
    getOpponent()->takeDamage(Warrior::getDamge());
}

Warrior::Warrior(float health, float damage, string weapon, float stamina) {
    _weapon = weapon;
    setHealth(health);
    setDamage(damage);
    setStamina(stamina);
} 

#endif
#include "Player.h"
#include "header.h"

#ifndef WARRIOR_H
#define WARRIOR_H

//high health, high stamina class, low functionality
class Warrior: virtual public Player
{
private:
    //string _weapon;
public:
    //constructors
    Warrior();
    Warrior(int health, float damage, int stamina);

    //virtual function
    virtual void takeDamage(int damage) = 0;

    //warrior ability
    //void swingWeapon();
};

//constructors
Warrior::Warrior() {}
Warrior::Warrior(int health, float damage, int stamina){
    setHealth(health);
    setDamageMultiplier(damage);
    setStamina(stamina);
}

//swings weapon at opponent does 30 damage takes 30 stamina
/*void Warrior::swingWeapon() {
    getOpponent()->takeDamage(30);
    setStamina(getStamina() - 30);
}*/

#endif
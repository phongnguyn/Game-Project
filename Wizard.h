#include "Player.h"
#include <string>

#ifndef WIZARD_H
#define WIZARD_H

class Wizard: virtual public Player 
{
private:

public:
    Wizard();
    Wizard(int health, int damage, int mana);
    void castSpell();
};

Wizard::Wizard() {}

void Wizard::castSpell() { 
    if (ShowName()) {cout << __FUNCTION__; return;}
    
    getOpponent()->takeDamage(Wizard::getDamge());
}

Wizard::Wizard(int health, int damage, int stamina) {
    Wizard::setHealth(health);
    Wizard::setDamage(damage);
    setStamina(stamina);
} 
#endif
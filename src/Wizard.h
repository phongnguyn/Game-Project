#include "Player.h"
#include <string>

#ifndef WIZARD_H
#define WIZARD_H

class Wizard: virtual public Player 
{
private:

public:
    Wizard();
    void castSpell();
};

Wizard::Wizard() {}

void Wizard::castSpell() { 
    if (ShowName()) {cout << __FUNCTION__; return;}
    
    getOpponent()->takeDamage(20);
}

#endif
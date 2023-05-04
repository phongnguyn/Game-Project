#include "Player.h"
#include <string>

#ifndef WIZARD_H
#define WIZARD_H

class Wizard: public Player 
{
private:
    int _mana;
public:
    Wizard(string name, int health, int damage, int mana);
    void castSpell(Player* opponent);
};

#endif
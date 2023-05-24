#include "header.h"
#include "Warrior.h"
#include "Wizard.h"

#ifndef GANDALF_H
#define GANDALF_H

class Gandalf: public Warrior, Wizard

{
private:
    
public:
    Gandalf();
    Gandalf(float health, string weapon, float stamina);
    void showAbilities(int);
    void excecuteAbilities(int);
    ~Gandalf();
};

typedef void (Gandalf::*GandalfAbilities)();

Gandalf::Gandalf() {}

void Gandalf::showAbilities(int n) {
    setShowName(true); 
    switch (n)
    {
    case 1:
        Gandalf::castSpell();
        break;
    case 2:
        swingWeapon();
        break;
    case 3:
        heal();
        break;
    case 4:
        meditate();
        break;

    }; 
    setShowName(false);}

void Gandalf::excecuteAbilities(int n) {
    switch (n)
    {
    case 1:
        Gandalf::castSpell();
        break;
    case 2:
        swingWeapon();
        break;
    case 3:
        heal();
        break;
    case 4:
        meditate();
        break;
    }; 
}

Gandalf::Gandalf(float health, string weapon, float stamina) : Warrior(weapon)
{
    setHealth(health);
    setStamina(stamina);
    setNumAbilities(4);
}

Gandalf::~Gandalf()
{
}



#endif
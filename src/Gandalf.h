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
    Gandalf(float health, float damage, string weapon, float stamina);
    void showAbilities(int);
    void excecuteAbilities(int);
    ~Gandalf();
};

typedef void (Gandalf::*GandalfAbilities)();

Gandalf::Gandalf() {
    setNumAbilities(2);
}

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
    }; 
}

Gandalf::Gandalf(float health, float damage, string weapon, float stamina)
{
    Wizard(health, damage, stamina);
    Warrior(health, damage, weapon, stamina);
}

Gandalf::~Gandalf()
{
}



#endif
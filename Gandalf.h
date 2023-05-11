#include "header.h"
#include "Warrior.h"
#include "Wizard.h"

#ifndef GANDALF_H
#define GANDALF_H

class Gandalf: public Warrior, Wizard

{
private:
    GandalfAbilities Abilities[2];
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
    GandalfAbilities Abilities[] = {&castSpell, &swingWeapon};
}

void Gandalf::showAbilities(int n) {setShowName(true); Abilities[n]; setShowName(false);}

void Gandalf::excecuteAbilities(int n) {Abilities[n];}

Gandalf::Gandalf(float health, float damage, string weapon, float stamina)
{
    Wizard(health, damage, stamina);
    Warrior(health, damage, weapon, stamina);
}

Gandalf::~Gandalf()
{
}



#endif
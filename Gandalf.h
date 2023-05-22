#include "header.h"
#include "Warrior.h"
#include "Wizard.h"

#ifndef GANDALF_H
#define GANDALF_H

class Gandalf: public Warrior, Wizard

{
public:
    //constructors
    Gandalf();
    Gandalf(float health, float stamina, string _name);
    //ability functionality
    void showAbilities(int);
    int excecuteAbilities(int);

    ~Gandalf();
};

//constructors
Gandalf::Gandalf() {  }
Gandalf::Gandalf(float health, float stamina, string _name){
    setName(_name);
    setNumAbilities(4);
    setHealth(health);
    setStamina(stamina);
}

//displays ability names
void Gandalf::showAbilities(int n) {
    setShowName(true); 
    switch (n)
    {
    case 1:
        castSpell();
        break;
    case 2:
        heal();
        break;
    case 3:
        swingWeapon();
        break;
    case 4:
        meditate();
    }; 
    setShowName(false);
}

//controls ability execution
int Gandalf::excecuteAbilities(int n) {
    //initial selection
    switch (n)
    {
    case 1:
        return castSpell();
        break;
    case 2:
        return heal();
        break;
    case 3:
        return swingWeapon();
        break;
    case 4:
        return meditate();
        break;
    };

    return 0;
    
}

Gandalf::~Gandalf()
{
}



#endif
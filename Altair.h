#include "header.h"
#include "Warrior.h"
#include "Assasin.h"

#ifndef ALTAIR_H
#define ALTAIR_H

class Altair : public Warrior, Assasin
{
public:
    //constructors
    Altair();
    Altair(float health, float stamina, string _name);
    //controls ability functionality
    void showAbilities(int);
    int excecuteAbilities(int);

    ~Altair();
};

//constructors
Altair::Altair() {  }
Altair::Altair(float health, float stamina, string _name)
{
    setName(_name);
    setNumAbilities(5);
    setHealth(health);
    setStamina(stamina);
}


//displays abilities to user
void Altair::showAbilities(int n) {
    setShowName(true); 
    switch (n)
    {
        case 1:
            swingWeapon();
            break;
        case 2:
            meditate();
            break;
        case 3:
            shank();
            break;
        case 4:
            evade();
            break;
        case 5:
            counter();
            break;
    }; 
    setShowName(false);
}

//controls ability execution
int Altair::excecuteAbilities(int n) {
    //initial selection
    switch (n)
    {
        case 1:
            return swingWeapon();
            break;
        case 2:
            return meditate();
            break;
        case 3:
            return shank();
            break;
        case 4:
            return evade();
            break;
        case 5:
            return counter();
            break;
    }; 

    return 0;
    
}

Altair::~Altair()
{
}

#endif
#include "header.h"
#include "Warrior.h"
#include "Tanker.h"

#ifndef REINHARDT_H
#define REINHARDT_H



class Reinhardt: public Warrior, public Tanker
{
public:
    //constructors
    Reinhardt();
    Reinhardt(float health, float stamina, string _name);
    //ability functionality
    void showAbilities(int);
    int excecuteAbilities(int);
    //destructor
    ~Reinhardt();
};

//constructors
Reinhardt::Reinhardt(){}
Reinhardt::Reinhardt(float health, float stamina, string _name) {
    setName(_name);
    setNumAbilities(4);
    setHealth(health);
    setStamina(stamina);
}

//displays abilities to user
void Reinhardt::showAbilities(int n) {
    setShowName(true); 
    switch (n)
    {
    case 1:
        bash();
        break;
    case 2:
        block();
        break;
    case 3:
        swingWeapon();
        break;
    case 4:
        meditate();
        break;
    }; 
    setShowName(false);
}

//controls ability execution
int Reinhardt::excecuteAbilities(int n) {
    //initial selection
    switch (n)
    {
    case 1:
        return bash();
        break;
    case 2:
        return block();
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


Reinhardt::~Reinhardt()
{
}

#endif
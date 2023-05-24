#include "header.h"
#include "Warrior.h"
#include "Tanker.h"

#ifndef REINHARDT_H
#define REINHARDT_H



class Reinhardt: public Warrior, public Tanker
{
private:
public:
    Reinhardt();
    Reinhardt(float health, string weapon, float stamina);
    void showAbilities(int);
    void excecuteAbilities(int);
    ~Reinhardt();
};

Reinhardt::Reinhardt() {}

Reinhardt::Reinhardt(float health, string weapon, float stamina) : Warrior(weapon) {
    setHealth(health);
    setStamina(stamina);
    setNumAbilities(4);    
}

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
    setShowName(false);}

void Reinhardt::excecuteAbilities(int n) {
    switch (n)
    {
    case 1:
        Reinhardt::bash();
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
}

Reinhardt::~Reinhardt()
{
}

#endif
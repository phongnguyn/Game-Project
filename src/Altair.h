#include "header.h"
#include "Warrior.h"
#include "Assasin.h"

#ifndef ALTAIR_H
#define ALTAIR_H

class Altair : public Warrior, Assasin
{
public:
    Altair();
    Altair(float, string, float);
    void showAbilities(int);
    void excecuteAbilities(int);
    ~Altair();
};

Altair::Altair() {
}

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

void Altair::excecuteAbilities(int n) {
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
}

Altair::Altair(float health, string weapon, float stamina) : Warrior(weapon)
{
    setHealth(health);
    setStamina(stamina);
    setNumAbilities(5); 
}

Altair::~Altair()
{
}

#endif
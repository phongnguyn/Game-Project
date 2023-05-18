#include "header.h"
#include "Warrior.h"
#include "Assasin.h"

#ifndef ALTAIR_H
#define ALTAIR_H

class Altair : public Warrior, Assasin
{
public:
    Altair();
    Altair(float health, float damage, string weapon, float stamina);
    void showAbilities(int);
    void excecuteAbilities(int);
    ~Altair();
};

Altair::Altair() {
    setNumAbilities(4); 
}

void Altair::showAbilities(int n) {
    setShowName(true); 
    switch (n)
    {
    case 1:
        Altair::swingWeapon();
        break;
    case 2:
        Altair::shank();
        break;
    case 3:
        evade();
        break;
    case 4:
        counter();
        break;
    }; 
    setShowName(false);
}

void Altair::excecuteAbilities(int n) {
    switch (n)
    {
    case 1:
        Altair::swingWeapon();
        break;
    case 2:
        Altair::shank();
        break;
    case 3:
        evade();
        break;
    case 4:
        counter();
        break;
    };
}

Altair::Altair(float health, float damage, string weapon, float stamina)
{
    Warrior(health, damage, weapon, stamina);
    Assasin(health, damage, weapon, stamina);
}

Altair::~Altair()
{
}

#endif
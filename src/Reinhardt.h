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
    Reinhardt(float health, float damage, string weapon, float stamina);
    void showAbilities(int);
    void excecuteAbilities(int);
    ~Reinhardt();
};

Reinhardt::Reinhardt() {
    setNumAbilities(3);
}

Reinhardt::Reinhardt(float health, float damage, string weapon, float stamina) {
    Warrior(health, damage, weapon, stamina);
    Tanker(health, damage, stamina);
}

void Reinhardt::showAbilities(int n) {
    setShowName(true); 
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
    }; 
}

Reinhardt::~Reinhardt()
{
}

#endif
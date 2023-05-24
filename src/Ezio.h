#include "header.h"
#include "Assasin.h"
#include "Wizard.h"

#ifndef EZIO_H
#define EZIO_H

class Ezio: public Assasin, Wizard

{
private:
    
public:
    Ezio();
    Ezio(float health, string weapon, float stamina);
    void showAbilities(int);
    void excecuteAbilities(int);
    ~Ezio();
};

Ezio::Ezio() {
}

void Ezio::showAbilities(int n) {
    setShowName(true); 
    switch (n)
    {
    case 1:
        Ezio::castSpell();
        break;
    case 2:
        Ezio::shank();
        break;
    case 3:
        evade();
        break;
    case 4:
        counter();
        break;
    case 5:
        heal();
        break;
    }; 
    setShowName(false);
}

void Ezio::excecuteAbilities(int n) {
    switch (n)
    {
    case 1:
        castSpell();
        break;
    case 2:
        shank();
        break;
    case 3:
        evade();
        break;
    case 4:
        counter();
        break;
    case 5:
        heal();
        break;
    };
}

Ezio::Ezio(float health, string weapon, float stamina) : Assasin(weapon)
{
    setHealth(health);
    setStamina(stamina);
    setNumAbilities(5); 
}

Ezio::~Ezio()
{
}


#endif
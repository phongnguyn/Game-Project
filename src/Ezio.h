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
    Ezio(float health, float damage, string weapon, float stamina);
    void showAbilities(int);
    void excecuteAbilities(int);
    ~Ezio();
};

Ezio::Ezio() {
    setNumAbilities(4); 
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
    }; 
    setShowName(false);
}

void Ezio::excecuteAbilities(int n) {
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
    };
}

Ezio::Ezio(float health, float damage, string weapon, float stamina)
{
    Wizard(health, damage, stamina);
    Assasin(health, damage, weapon, stamina);
}

Ezio::~Ezio()
{
}


#endif
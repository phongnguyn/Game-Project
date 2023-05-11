#include "header.h"
#include "Assasin.h"
#include "Wizard.h"

#ifndef EZIO_H
#define EZIO_H

typedef void(Ezio::*EzioAbilities)();

class Ezio: public Assasin, Wizard

{
private:
    EzioAbilities Abilities[4];
public:
    Ezio();
    Ezio(float health, float damage, string weapon, float stamina);
    void showAbilities(int);
    void excecuteAbilities(int);
    ~Ezio();
};

Ezio::Ezio() {
    setNumAbilities(4); 
    EzioAbilities Abilities[] = {&castSpell, &shank, &evade, &counter};
}

void Ezio::showAbilities(int n) {setShowName(true); Abilities[n](); setShowName(false);}

void Ezio::excecuteAbilities(int n) {Abilities[n]();}

Ezio::Ezio(float health, float damage, string weapon, float stamina)
{
    Wizard(health, damage, stamina);
    Assasin(health, damage, weapon, stamina);
}

Ezio::~Ezio()
{
}


#endif
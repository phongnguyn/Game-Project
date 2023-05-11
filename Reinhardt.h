#include "header.h"
#include "Warrior.h"
#include "Tanker.h"

#ifndef REINHARDT_H
#define REINHARDT_H



class Reinhardt: public Warrior, public Tanker
{
private:
    ReinhardtAbilities Abilities[3] = {&bash, &block, &swingWeapon};
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

void Reinhardt::showAbilities(int n) {setShowName(true); invoke(Abilities[n]); setShowName(false);}

void Reinhardt::excecuteAbilities(int n) {Abilities[n]();}

Reinhardt::~Reinhardt()
{
}

typedef void(Reinhardt::*ReinhardtAbilities)();
#endif
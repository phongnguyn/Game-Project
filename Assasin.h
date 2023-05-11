#include "Player.h"


#ifndef ASSASIN_H
#define ASSASIN_H

class Assasin: virtual public Player
{
private:
    string _weapon;
public:
    Assasin();
    Assasin(float health, float damage, string weapon, float stamina);
    void shank();
    void evade();
    void counter();  
    ~Assasin();
};

Assasin::Assasin() {}

Assasin::Assasin(float health, float damage, string weapon, float stamina)
{
    _weapon = weapon;
    setHealth(health);
    setDamage(damage);
    setStamina(stamina);
}

void Assasin::counter() {
    if (ShowName()) {cout << __FUNCTION__; return;}
}

void Assasin::evade() {if (ShowName()) {cout << __FUNCTION__; return;}}

void Assasin::shank() {if (ShowName()) {cout << __FUNCTION__; return;}}

Assasin::~Assasin()
{
}


#endif 
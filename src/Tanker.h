#include "Player.h"

#ifndef TANKER_H
#define TANKER_H

class Tanker: virtual public Player
{
private:
    float armor;
public:
    Tanker();
    void block(); 
    void bash();
    ~Tanker();
};

Tanker::Tanker() {}

void Tanker::block() {
    if (ShowName()) {cout << __FUNCTION__; return;}
    setDamageMultiplier(0.5);
    setStamina(getStamina() + 25);
}

void Tanker::bash() {
    if (ShowName()) {cout << __FUNCTION__; return;}
    setDamageMultiplier(1);
    getOpponent()->takeDamage(20);
    setStamina(getStamina() - 20);
}

Tanker::~Tanker()
{
}


#endif
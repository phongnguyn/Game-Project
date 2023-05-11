#include "Player.h"

#ifndef TANKER_H
#define TANKER_H

class Tanker: virtual public Player
{
private:
    float armor;
public:
    Tanker();
    Tanker(float health, float damage, float stamina);
    void block(); 
    void bash();
    ~Tanker();
};

Tanker::Tanker() {}

Tanker::Tanker(float health, float damage, float stamina) {
    setHealth(health);
    setDamage(damage);
    setStamina(stamina);
}

void Tanker::block() {
    if (ShowName()) {cout << __FUNCTION__; return;}
}

void Tanker::bash() {
    if (ShowName()) {cout << __FUNCTION__; return;}
}

Tanker::~Tanker()
{
}


#endif
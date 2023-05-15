#include "Player.h"

#ifndef TANKER_H
#define TANKER_H


//tanker class high health, low attack damage, low efficiency
class Tanker: virtual public Player
{
private:
    float armor;
public:
    //constructors
    Tanker();
    Tanker(float health, float damage, float stamina);

    //virtual function
    virtual void takeDamage(int damage) = 0;

    //tanker attacks
    void block(); 
    void bash();

    //destructor
    ~Tanker();
};



//constructors
Tanker::Tanker() {
    setHealth(200);
    setDamageMultiplier(1);
    setStamina(100);
}
Tanker::Tanker(float health, float damage, float stamina) {
    setHealth(health);
    setDamageMultiplier(damage);
    setStamina(stamina);
}

//blocks 50% of incoming damage regains 25 stamina
void Tanker::block() {
    setDamageMultiplier(0.5);
    setStamina(getStamina() + 25);
}

//reduces opponent health 10 points damage, reduces stamina by 20 points
void Tanker::bash() {
    getOpponent()->takeDamage(20);
    setStamina(getStamina() - 20);
}

Tanker::~Tanker(){
}


#endif
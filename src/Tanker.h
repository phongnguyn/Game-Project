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
    if (ShowName()) {cout << __FUNCTION__ << " (regains 20 stamina, blocks significant damage)\n"; return;}
    //functionality
    setDamageMultiplier(0.5 + rand() % 25/100);
    setStamina(getStamina() + 20);

    //display
    cout << getName() <<" used Block, 20 stamina regained\n";
    cout << "Next attack on " << getName() << " will do reduced damage\n\n";

    setExecuted(true);
}

void Tanker::bash() {
    if (ShowName()) {cout << __FUNCTION__<< " (uses 15 stamina, does high damage)\n"; return;}
    
    setDamageMultiplier(1);

    if(getStamina() - 15 >= 0){
        //functionality
        int damage = 15 + rand() % 15;
        getOpponent()->takeDamage(damage);
        setStamina(getStamina() - 15);
        //display
        cout << getName() << " used Bash, " << damage << " damage dealt to " << getOpponent()->getName();
        cout << endl << getName() << " lost 15 stamina\n\n";
        
        setExecuted(true);
    }else {
        cout << "not enough stamina select a different ability\n";
    }
}

Tanker::~Tanker()
{
}


#endif
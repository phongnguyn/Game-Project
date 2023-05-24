#include "Player.h"


#ifndef ASSASIN_H
#define ASSASIN_H

class Assasin: virtual public Player
{
private:
    string _weapon;
public:
    Assasin() {}
    Assasin(string);
    void shank();
    void evade();
    void counter();  
    ~Assasin();
};

Assasin::Assasin(string weapon) {_weapon = weapon;}

void Assasin::counter() {
    if (ShowName()) {cout << __FUNCTION__ << " (regains 15 stamina, reduces incoming damage by small amount)\n"; return;}

    //functionality
    setDamageMultiplier(0.9 + rand() % 5 / 100);
    setStamina(getStamina() + 15);

    //display
    cout << getName() << " used counter, stamina increased by 15 points\n";
    cout << "next attack on " << getName() << " will do reduced damage\n\n";

    setExecuted(true);
}

void Assasin::evade() {
    if (ShowName()) {cout << __FUNCTION__ <<  " (uses 40 stamina, stops all incoming damage)\n"; return; }

    setDamageMultiplier(1);

    if (getStamina() - 40 >= 0){
        //functionality
        setStamina(getStamina() - 40);
        //display
        cout << getName() << " used evade, next attack on " << getName() << " will deal no damage\n";
        cout << getName() << " lost 40 stamina\n\n";

        setExecuted(true);
    }else{
        cout << "not enough stamina, select another ability\n";
    }
}

void Assasin::shank() {
    if (ShowName()) {cout << __FUNCTION__<< " (uses 5 stamina does small damage)\n"; return;}

    setDamageMultiplier(1);

    if (getStamina() - 5 >= 0){
        //functionality
        setStamina(getStamina() - 5);
        int damage = 5 + rand() % 5;
        getOpponent()->takeDamage(damage);
        //display
        cout << getName() << " used shank and dealt " << damage << " damage to " << getOpponent()->getName() << endl;
        cout << getName() << " lost 5 stamina\n\n";

        setExecuted(true);
    }else{
        cout << "not enough stamina, please select another ability\n";
    }
}

Assasin::~Assasin()
{
}


#endif 
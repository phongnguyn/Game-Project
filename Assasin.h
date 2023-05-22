#include "Player.h"


#ifndef ASSASIN_H
#define ASSASIN_H

class Assasin: virtual public Player
{
private:
    float damageMult = 0;
public:
    //constructors
    Assasin();
    Assasin(float health, float stamina);
    //abilities
    int shank();
    int evade();
    int counter();  
    void takeDamage(int _damage);

    ~Assasin();
};

//constructors
Assasin::Assasin() {}
Assasin::Assasin(float health, float stamina)
{
    setHealth(health);
    setStamina(stamina);
}

//regains stamina by 15 points reduces incoming damage by between 5-10%
int Assasin::counter() {
    if (ShowName()) {cout << __FUNCTION__ << " (regains 15 stamina, reduces incoming damage by small amount)"; return 0;}
    //functionality
    damageMult = 0.05 + rand() % 5 / 100;
    setStamina(getStamina() + 15);

    //display
    cout << getName() << " used counter, stamina increased by 15 points\n";
    cout << "next attack on " << getName() << " will do reduced damage\n\n";
    return 1;
}

//uses 40 stamina blocks all incoming damage
int Assasin::evade() {
    if (ShowName()) {cout << __FUNCTION__ << " (uses 40 stamina, stops all incoming damage)"; return 0;}
    if (getStamina() - 40 >= 0){
        //functionality
        damageMult = 1;
        setStamina(getStamina() - 40);
        //display
        cout << getName() << " used evade, next attack on " << getName() << " will deal no damage\n";
        cout << getName() << " lost 40 stamina\n\n";
        return 1;
    }else{
        cout << "not enough stamina, select another ability\n";
        return 0;
    }
}

//uses 5 stamina does between 5-10 damage
int Assasin::shank() {
    if (ShowName()) {cout << __FUNCTION__ << " (uses 5 stamina does small damage)"; return 0;}
    if (getStamina() - 5 >= 0){
        //functionality
        setStamina(getStamina() - 5);
        int damage = 5 + rand() % 5;
        getOpponent()->takeDamage(damage);
        //display
        system("clear");
        cout << getName() << " used shank and dealt " << damage << " damage to " << getOpponent()->getName() << endl;
        cout << getName() << " lost 5 stamina\n\n";
        return 1;
    }else{
        cout << "not enough stamina, please select another ability\n";
        return 0;
    }
    
}

//controls taking damage
void Assasin::takeDamage(int _damage){
    setHealth(getHealth() - (1-damageMult)*_damage);
    damageMult = 0;
}

Assasin::~Assasin()
{
}


#endif 
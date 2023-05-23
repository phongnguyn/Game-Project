#include "Player.h"
#include "header.h"

#ifndef WARRIOR_H
#define WARRIOR_H

class Warrior: virtual public Player
{
private:
    string _weapon;
public:
    Warrior() {}
    Warrior(string);
    void swingWeapon();
    void meditate();
};

Warrior::Warrior(string weapon) {_weapon = weapon;}

void Warrior::swingWeapon() {
    //shows ability name / functionality
    if (ShowName()) {cout << __FUNCTION__<< " (does large damage reduces stamina by 20)"; return;}

    //ability functionality
    if((getStamina() - 20) >= 0){
        //functionality
        int damage = 20 + rand() % 20;
        getOpponent()->takeDamage(damage);
        setStamina(getStamina() - 20); 
        //display
        cout << getName() << " hit " << getOpponent()->getName() << " with a sword dealing " << damage;
        cout << " damage\n" << getName() << " lost 10 stamina\n\n";
        setExecuted(true);
    }else{
        cout << "Not enough stamina, select a different ability\n";
    }

}

void Warrior::meditate() {
    //shows ability name / functionality
    if (ShowName()) {cout << __FUNCTION__ << " (regains 30 Stamina)";}

    //ability functionality
    setStamina(getStamina() + 30);

    cout << getName() << " used meditate 30 stamina regained\n\n";

    setExecuted(true);
}

#endif
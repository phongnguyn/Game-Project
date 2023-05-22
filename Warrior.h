#include "Player.h"
#include "header.h"

#ifndef WARRIOR_H
#define WARRIOR_H

class Warrior: virtual public Player
{
public:
    //constructors
    Warrior();
    Warrior(float health, float stamina);
    //abilities
    int swingWeapon();
    int meditate();
};

//constructors
Warrior::Warrior() {}
Warrior::Warrior(float health, float stamina){
    setHealth(health);
    setStamina(stamina);
} 

//does a maximum of 40 damage reduces stamina by 20
int Warrior::swingWeapon() {
    //shows ability name
    if (ShowName()) {cout << __FUNCTION__ << " (does large damage reduces stamina by 20)"; return 0;}

    //ability functionality
    if((getStamina() - 20) >= 0){
        //functionality
        int damage = 20 + rand() % 20;
        getOpponent()->takeDamage(damage);
        setStamina(getStamina() - 20); 
        //display
        cout << getName() << " hit " << getOpponent()->getName() << " with a sword dealing " << damage;
        cout << " damage\n" << getName() << " lost 10 stamina\n\n";
        return 1;
    }else{
        cout << "Not enough stamina, select a different ability\n";
        return 0;
    }

    //functionality
    int damage = 20 + rand() % 20;
    getOpponent()->takeDamage(damage);
    setStamina(getStamina() - 10); 
    //display
    system("clear");
    cout << getName() << " hit " << getOpponent()->getName() << " with a sword dealing " << damage;
    cout << " damage\n" << getName() << " lost 10 stamina\n\n";
}

//regains 30 stamina
int Warrior::meditate(){
    //shows ability name
    if (ShowName()) {cout << __FUNCTION__ << " (regains 30 Stamina)"; return 0;}

    //ability functionality
    setStamina(getStamina() + 30);

    cout << getName() << " used meditate 30 stamina regained\n\n";
    return 1;
}


#endif
#include "Player.h"
#include <string>

#ifndef WIZARD_H
#define WIZARD_H

class Wizard: virtual public Player 
{
public:
    //constructors
    Wizard();
    Wizard(int health, int mana);

    //abilities
    int castSpell();
    int heal();
};

//constructors
Wizard::Wizard() {
    Wizard(0,0);
}
Wizard::Wizard(int health, int stamina) {
    setHealth(health);
    setStamina(stamina);
} 


//deals 20- 30 damage, reduces stamina by 20
int Wizard::castSpell() { 
    //shows ability name / functionality
    if (ShowName()) {cout << __FUNCTION__ << " (uses 20 stamina, does large damage)"; return 0;}

    //controls ability functionality
    if((getStamina() - 20)  >= 0 ){
        setStamina(getStamina() - 20);
        int damage = 20 + rand() % 10 ;
        getOpponent()->takeDamage(damage);
        //display
        cout << getName() << " Cast a spell and dealt " << damage << " damage to " << getOpponent()->getName();
        cout << endl << getName() << " lost 20 stamina\n\n";
        return 1;
    }else {
        cout << "not enough stamina select another ability\n";
        return 0;
    }
}

//uses 15 stamina restores 10 health
int Wizard::heal(){
    //shows ability name
    if (ShowName()) {cout << __FUNCTION__ << " (uses 15 stamina, restores 10 health)"; return 0;}

    //ability functionality
    if(getStamina() - 15 > 0){
        setHealth(getHealth() + 10);
        setStamina(getStamina() - 15);
        cout << getName() <<" used heal and regained 10 health\n\n";
        return 1;
    }else{
        cout << "not enough stamina select another ability\n";
        return 0;
    }
}
#endif
#include "Player.h"
#include <string>

#ifndef WIZARD_H
#define WIZARD_H

class Wizard: virtual public Player 
{
private:

public:
    Wizard();
    void castSpell();
    void heal();
};

Wizard::Wizard() {}

void Wizard::castSpell() { 
    //shows ability name / functionality
    if (ShowName()) {cout << __FUNCTION__<< " (uses 20 stamina, does large damage)\n"; return;}

    //controls ability functionality
    if((getStamina() - 20)  >= 0 ){
        setStamina(getStamina() - 20);
        int damage = 20 + rand() % 10 ;
        getOpponent()->takeDamage(damage);
        //display
        cout << getName() << " Cast a spell and dealt " << damage << " damage to " << getOpponent()->getName();
        cout << endl << getName() << " lost 20 stamina\n\n";

        setExecuted(true);
    }else {
        cout << "not enough stamina select another ability\n";
    }
}

void Wizard::heal(){
    //shows ability name / functionality
    if (ShowName()) {cout << __FUNCTION__ << " (uses 15 stamina, restores 10 health)\n"; return;}

    //ability functionality
    if(getStamina() - 15 >= 0){
        setHealth(getHealth() + 10);
        setStamina(getStamina() - 15);
        cout << getName() <<" used heal and regained 10 health\n\n";

        setExecuted(true);
    }else{
        cout << "not enough stamina select another ability\n";
    }
}

#endif
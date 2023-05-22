#include "Player.h"

#ifndef TANKER_H
#define TANKER_H

class Tanker: virtual public Player
{
private:
    float damageMult = 0;
public:
    //constructors
    Tanker();
    Tanker(float health, float stamina);

    //abilities / functionality
    void takeDamage(int _damage);
    int block(); 
    int bash();
    
    //destructors
    ~Tanker();
};

//constructors
Tanker::Tanker(){
    Tanker(0,0);
}
Tanker::Tanker(float health, float stamina){
    setHealth(health);
    setStamina(stamina);
}


//reduces incoming damage by between 50 - 75% regains 20 stamina
int Tanker::block() {
    //displays ability name
    if (ShowName()) {cout << __FUNCTION__ << " (regains 20 stamina, blocks significant damage)"; return 0;}
    //functionality
    damageMult = 0.5 + rand() % 25/100;
    setStamina(getStamina() + 20);

    //display
    cout << getName() <<" used Block, 15 stamina regained\n";
    cout << "Next attack on " << getName() << " will do reduced damage\n\n";
    return 1;
}   

//uses 15 stamina does between 15 and 30 damage
int Tanker::bash() {
    //displays ability name
    if (ShowName()) {cout << __FUNCTION__ << " (uses 15 stamina, does high damage)"; return 0;}
    
    if(getStamina() - 15 >= 0){
        //functionality
        int damage = 15 + rand() % 15;
        getOpponent()->takeDamage(damage);
        setStamina(getStamina() - 15);
        //display
        cout << getName() << " used Bash, " << damage << " damage dealt to " << getOpponent()->getName();
        cout << endl << getName() << " lost 15 stamina\n\n";
        return 1;
    }else {
        cout << "not enough stamina select a different ability\n";
        return 0;
    }

}

//overides take damage function
void Tanker::takeDamage(int _damage){
    setHealth(getHealth() - (1-damageMult)*_damage);
    damageMult = 0;
}


Tanker::~Tanker()
{
}


#endif
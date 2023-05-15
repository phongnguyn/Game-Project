#include "header.h"
#include "Warrior.h"
#include "Tanker.h"

#ifndef REINHARDT_H
#define REINHARDT_H



class Reinhardt: public Warrior, public Tanker
{
private:
public:
    //constructors
    Reinhardt();
    Reinhardt(int health, float damage, int stamina, string _name);
    
    //shows abilities for user selection, executes abilities
    void showAbilities();

    //controls take damage
    void takeDamage(int damage){
        setHealth(getHealth() - damage);
    }
   
    //destructor
    ~Reinhardt();
};

//constructors
Reinhardt::Reinhardt(){
    setHealth(150);
    setStamina(150);
    setDamageMultiplier(1);
    string name = "";
    //add input checks
    cout << "please enter name: ";
    cin >> name;
    setName(name);
}
Reinhardt::Reinhardt(int health, float damage, int stamina, string _name){
    setHealth(health);
    setStamina(stamina);
    setDamageMultiplier(damage);
    setName(_name);
}

void Reinhardt::showAbilities() {
    string input = "";
    cout << "Select Attack\n";
    cout << "1 : Swing Sword (does 30 damgae reduces stamina by 30)";
    cout << "2 : Bash (does 20 damage reduces stamina by 20)";
    cout << "3 : Block (reduces next attack damage by half increases stamina by 25)";
    //need to insert checks for this input
    cin >> input;
    
    switch (stoi(input))
    {
    case 1:
        //swingWeapon();
        break;
    case 2:
        bash();
        break;
    case 3:
        block();
        break;
    }; 
}


Reinhardt::~Reinhardt()
{
}

#endif
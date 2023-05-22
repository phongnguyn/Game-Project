#include "header.h"

#ifndef PLAYER_H
#define PLAYER_H

using namespace std;

class Player
{
private:
    int abilityExecuted;
    string name;
    float health;
    float stamina;
    Player* opponent;
    int numAbilities = 0;
    bool showName = false; 
public:
    //purely virtual functions
    virtual void showAbilities(int) {}
    virtual int excecuteAbilities(int) {}

    //controls take damage
    virtual void takeDamage(int _damage);

    //getters / setters
    int getAbilityExecuted();
    void setAbilityExecuted(int n);
    void setHealth(int _health);
    float getHealth();
    void setStamina(float _stamina);
    float getStamina();
    Player* getOpponent();
    void setOpponent(Player*);
    void setNumAbilities(int);
    int getNumAbilities();
    bool ShowName() {return showName;}
    void setShowName(bool _showName) {showName = _showName;} 
    void setName(string name);
    string getName();
};

//controls take damage
void Player::takeDamage(int _damage){
    health = health - _damage;
}

//getters / setters
int Player::getAbilityExecuted(){
    return abilityExecuted;
}

void Player::setAbilityExecuted(int n){
    abilityExecuted = n;
}

void Player::setHealth(int _health){
    health = _health;
}

float Player::getHealth(){
    return health;
}

void Player::setStamina(float _stamina){
    stamina = _stamina;
}

float Player::getStamina(){
    return stamina;
}

Player* Player::getOpponent(){
    return opponent;
}

void Player::setOpponent(Player* opp){
    opponent = opp;
}

void Player::setNumAbilities(int _numAbilities){
    numAbilities = _numAbilities;
}

int Player::getNumAbilities(){
    return numAbilities;
}

void Player::setName(string _name){
    name = _name;
}

string Player::getName(){
    return name;
}

#endif
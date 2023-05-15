#include "header.h"

#ifndef PLAYER_H
#define PLAYER_H

using namespace std;

class Player
{
private:

    int health;
    //damage multiplier controls defense functionality, must be set to 1 when attacking
    float damageMultiplier = 1;
    int stamina;
    Player* opponent;
    string name;
    //int numAbilities = 0;
    //bool showName = false; 
public:
    virtual void takeDamage(int _damage) = 0;
    //virtual void showAbilities(int) = 0;
    //virtual void excecuteAbilities(int) = 0;

    //getters and setters
    void setHealth(int _health);
    int getHealth();

    void setDamageMultiplier(float _damage);
    float getDamgeMultiplier();

    void setStamina(float _stamina);
    int getStamina();

    void setName(string _name);
    string getName();

    Player* setOpponent();
    Player* getOpponent();

    //void setOpponent(auto);
    //void setNumAbilities(int);
    //int getNumAbilities();
    //bool ShowName() {return showName;}
    //void setShowName(bool _showName) {showName = _showName;} 
};

void Player::setHealth(int _health) {
    health = _health;
}

int Player::getHealth() {
    return health;
}

void Player::setDamageMultiplier(float _damage) {
    damageMultiplier = _damage;
}

//float Player::getDamge() {return damage;}

void Player::setStamina(float _stamina) {
    stamina = _stamina;
}

int Player::getStamina() {
    return stamina;
}

void Player::setName(string _name){
    name = _name;
}
string Player::getName(){
    return name;
}

Player* Player::getOpponent() {return opponent;}

//void Player::setOpponent(auto opp) {opponent = opp;}

//void Player::setNumAbilities(int _numAbilities) {numAbilities = _numAbilities;}

//int Player::getNumAbilities() {return numAbilities;}

#endif
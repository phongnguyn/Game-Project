#include "header.h"

#ifndef PLAYER_H
#define PLAYER_H

using namespace std;

class Player
{
private:
    string name;
    float health;
    float stamina;
    Player* opponent;
    int numAbilities = 0;
    bool showName = false; 
    float damageMultiplier = 1;
    bool executed = false;
public:
    virtual void takeDamage(int _damage) {setHealth(getHealth() - damageMultiplier * _damage);}
    virtual void showAbilities(int) {}
    virtual void excecuteAbilities(int) {}
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
    void setDamageMultiplier(float _damageMultiplier);
    void setName(string name);

    //set and get executed state of the character's abilities;
    void setExecuted(bool _executed) {executed = _executed;}
    bool getExecuted() {return executed;}  
    
    string getName();
};

void Player::setHealth(int _health) {health = _health;}

float Player::getHealth() {return health;}

void Player::setStamina(float _stamina) {stamina = _stamina;}

float Player::getStamina() {return stamina;}

Player* Player::getOpponent() {return opponent;}

void Player::setOpponent(Player* opp) {opponent = opp;}

void Player::setNumAbilities(int _numAbilities) {numAbilities = _numAbilities;}

int Player::getNumAbilities() {return numAbilities;}

void Player::setDamageMultiplier(float _damageMultiplier) {
    damageMultiplier = _damageMultiplier;
}

void Player::setName(string _name){
    name = _name;
}

string Player::getName(){
    return name;
}

#endif
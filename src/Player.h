#include "header.h"

#ifndef PLAYER_H
#define PLAYER_H

using namespace std;

class Player
{
private:
    float health;
    float damage;
    float stamina;
    Player* opponent;
    int numAbilities = 0;
    bool showName = false; 
public:
    virtual void takeDamage(int _damage) {}
    virtual void showAbilities(int) {}
    virtual void excecuteAbilities(int) {}
    void setHealth(int _health);
    float getHealth();
    void setDamage(int _damage);
    float getDamge();
    void setStamina(float _stamina);
    float getStamina();
    Player* getOpponent();
    void setOpponent(Player*);
    void setNumAbilities(int);
    int getNumAbilities();
    bool ShowName() {return showName;}
    void setShowName(bool _showName) {showName = _showName;} 
};

void Player::setHealth(int _health) {health = _health;}

float Player::getHealth() {return health;}

void Player::setDamage(int _damage) {damage = _damage;}

float Player::getDamge() {return damage;}

void Player::setStamina(float _stamina) {stamina = _stamina;}

float Player::getStamina() {return stamina;}

Player* Player::getOpponent() {return opponent;}

void Player::setOpponent(Player* opp) {opponent = opp;}

void Player::setNumAbilities(int _numAbilities) {numAbilities = _numAbilities;}

int Player::getNumAbilities() {return numAbilities;}

#endif
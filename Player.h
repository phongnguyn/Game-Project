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
public:
    virtual void takeDamage(int _damage);
    void setHealth(int _health);
    float getHealth();
    void setDamage(int _damage);
    float getDamge();
    void setStamina(float _stamina);
    float getStamina();
};

#endif
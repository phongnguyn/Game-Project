#include "header.h"

#ifndef PLAYER_H
#define PLAYER_H

using namespace std;

class Player
{
private:
    string _name;
    int _health;
    int _damage;
public:
    virtual void takeDamage(int damage);
    void setName(string name);
    string getName();
    void setHealth(int health);
    int getHealth();
    void setDamage(int damage);
    int getDamge();
};

#endif
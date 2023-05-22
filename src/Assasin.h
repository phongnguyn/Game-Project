#include "Player.h"


#ifndef ASSASIN_H
#define ASSASIN_H

class Assasin: virtual public Player
{
private:
    string _weapon;
public:
    Assasin() {}
    Assasin(string);
    void shank();
    void evade();
    void counter();  
    ~Assasin();
};

Assasin::Assasin(string weapon) {_weapon = weapon;}

void Assasin::counter() {
    if (ShowName()) {cout << __FUNCTION__; return;}
}

void Assasin::evade() {
    if (ShowName()) {cout << __FUNCTION__; return;}
    setDamageMultiplier(0);
}

void Assasin::shank() {if (ShowName()) {cout << __FUNCTION__; return;}}

Assasin::~Assasin()
{
}


#endif 
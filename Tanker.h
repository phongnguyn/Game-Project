#include "Player.h"

#ifndef TANKER_H
#define TANKER_H

class Tanker: public Player
{
private:
    float armor;
public:
    Tanker(float _health, float _damage);
    void block(); 
    void bash();
    ~Tanker();
};

Tanker::Tanker(float _health, float _damage) {
}

void Tanker::block() {
}

void Tanker::bash() {}

Tanker::~Tanker()
{
}


#endif
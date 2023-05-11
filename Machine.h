#include "header.h"
#include "Player.h"
#include "Reinhardt.h"
#include "Ezio.h"
#include "Gandalf.h"
#include "Person.h"

#ifndef MACHINE_H
#define MACHINE_H

class Machine: public Person 
{
private:
    Player* player;
public:
    Machine();
    void chooseAbilities();
    Player* getPlayer();
    ~Machine();
};

Machine::Machine() 
{
    int id = rand() % 4 + 1;
    switch(id) {
        case 1: {
            player = new Reinhardt(120, 25, "Sword", 50);
            break;
        }
        case 2: {
            player = new Ezio(120, 25, "katana", 50);
            break;
        }
        case 3:
            player = new Gandalf(120, 25, "katana", 50);
            break;
        case 4:

            break;
    }
}

void Machine::chooseAbilities() {
    int option = rand() % player->getNumAbilities() + 1;
    getPlayer()->excecuteAbilities(option);
}

Player* Machine::getPlayer() {return player;}

Machine::~Machine()
{
}

#endif
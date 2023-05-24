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
    
public:
    Machine();
    void chooseAbilities();
    ~Machine();
};

Machine::Machine() : Person(rand() % 4 + 1) {getPlayer()->setName("Machine");}

void Machine::chooseAbilities() {
    int option = rand() % getPlayer()->getNumAbilities() + 1;
    cout << "Machine uses ";
    getPlayer()->setShowName(true);
    getPlayer()->excecuteAbilities(option);
    getPlayer()->setShowName(false);
    getPlayer()->excecuteAbilities(option);
}

Machine::~Machine()
{
}

#endif
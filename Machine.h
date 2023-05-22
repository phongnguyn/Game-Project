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
public:
    //constructor
    Machine();
    //machine ability choice
    void chooseAbilities();

    ~Machine();
};

//constructor
Machine::Machine(): 
    Person(rand() % 4 + 1, 1) {  }

//controls machine ability choice


void Machine::chooseAbilities() {
    
    int option = rand() % getPlayer()->getNumAbilities()+1;
    while (getPlayer()->excecuteAbilities(option) == 0){
        int option = rand() % getPlayer()->getNumAbilities()+1;
    }
}

Machine::~Machine()
{
}

#endif
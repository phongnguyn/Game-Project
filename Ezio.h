#include "header.h"
#include "Assasin.h"
#include "Wizard.h"

#ifndef EZIO_H
#define EZIO_H

class Ezio: public Assasin, Wizard

{
public:
    //constructors
    Ezio();
    Ezio(float health, float stamina, string _name);
    //controls ability functionality
    void showAbilities(int);
    int excecuteAbilities(int);

    ~Ezio();
};

//constructors
Ezio::Ezio() {  }
Ezio::Ezio(float health, float stamina, string _name)
{
    setName(_name);
    setNumAbilities(5);
    setHealth(health);
    setStamina(stamina);
}

//displays abilities to user
void Ezio::showAbilities(int n) {
    setShowName(true); 
    switch (n)
    {
        case 1:
            castSpell();
            break;
        case 2:
            heal();
            break;
        case 3:
            shank();
            break;
        case 4:
            evade();
            break;
        case 5:
            counter();
            break;
    }; 
    setShowName(false);
}

//controls ability execution
int Ezio::excecuteAbilities(int n) {
    //initial selection
    switch (n)
    {
    case 1:
        return castSpell();
        break;
    case 2:
        return heal();
        break;
    case 3:
        return shank();
        break;
    case 4:
        return evade();
        break;
    case 5:
        return counter();
        break;
    };

    return 0;
    
}

Ezio::~Ezio()
{
}


#endif
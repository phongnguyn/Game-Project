#include "header.h"
#include "Player.h"
#include "Reinhardt.h"
#include "Ezio.h"
#include "Gandalf.h"
#include "Altair.h"

#ifndef PERSON_H
#define PERSON_H

class Person 
{
private:
    Player* player;
public:
    Person();
    Person(int);
    virtual void chooseAbilities();
    Player* getPlayer();
    ~Person();
};

Person::Person(/* args */)
{
}

Person::Person(int id) 
{
    switch(id) {
        case 1: {
            player = new Reinhardt(90, "Sword", 50);
            break;
        }
        case 2: {
            player = new Ezio(60, "katana", 50);
            break;
        }
        case 3: {
            player = new Gandalf(70, "katana", 50);
            break;
        }
        case 4:
            player = new Altair(70, "katana", 50);
            break;
    }
}

void Person::chooseAbilities() {
    cout << player->getName() << " choose one of these abilities from 1 to " << player->getNumAbilities() << "\n";
    for (int i = 0; i < player->getNumAbilities(); i ++) {
        cout << i + 1 << ": ";
        player->showAbilities(i + 1);
    }

    int num = 0;

    player->setExecuted(false);
    while (!player->getExecuted()) {
        while (!(cin >> num) || (num > player->getNumAbilities()) || (num < 1)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "invalid input, try again please select from 1 to " << player->getNumAbilities() << "\n";
        }

        player->excecuteAbilities(num);
    }
}

Player* Person::getPlayer() {return player;}

Person::~Person()
{
}


#endif
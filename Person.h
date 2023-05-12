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
            player = new Reinhardt(120, 25, "Sword", 50);
            break;
        }
        case 2: {
            player = new Ezio(120, 25, "katana", 50);
            break;
        }
        case 3: {
            player = new Gandalf(120, 25, "katana", 50);
            break;
        }
        case 4:
            player = new Altair(120, 25, "katana", 50);
            break;
    }
}

void Person::chooseAbilities() {
    cout << "please choose one of these abilities\n";
    for (int i = 0; i < player->getNumAbilities(); i ++) {
        cout << i << " ";
        player->showAbilities(i);
        cout << "\n";
    }
    int num = 0;
    while (!(cin >> num) || (num < player->getNumAbilities() + 1) || (num > 0)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "invalid input, try again\n";
    }
    player->excecuteAbilities(num);
}

Player* Person::getPlayer() {return player;}

Person::~Person()
{
}


#endif
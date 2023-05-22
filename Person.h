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
    //constructors
    Person();
    Person(int, int);
    //controls ability choice
    virtual void chooseAbilities();
    //getter
    Player* getPlayer();
    ~Person();
};

//constructors
Person::Person(/* args */)
{
}
Person::Person(int id, int isMachine) 
{
    string _name;
    if (isMachine){
        _name = "Computer";
    }else{
        cout << "Please Enter Name: ";
        cin >> _name;
    }

    switch(id) {
        case 1: {
            player = new Reinhardt(120, 50, _name);
            break;
        }
        case 2: {
            player = new Ezio(120, 50, _name);
            break;
        }
        case 3: {
            player = new Gandalf(120, 50, _name);
            break;
        }
        case 4:
            player = new Altair(120, 50, _name);
            break;
    }
}

//controls ability choice
void Person::chooseAbilities() {
    int completed = 0;
    cout << player->getName() << "'s turn!\n choose one of these abilities\n";
    for (int i = 1; i <= player->getNumAbilities(); i ++) {
        cout << i << " ";
        player->showAbilities(i);
        cout << "\n";
    }
    while(completed == 0){
        int num = 0;
        while (!(cin >> num) || !(num < player->getNumAbilities() + 1) || !(num > 0)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "invalid input, try again\n";
        }
        completed = player->excecuteAbilities(num);
    }
    
    //player->excecuteAbilities(num);
}

//getter
Player* Person::getPlayer(){
    return player;
}

Person::~Person()
{
}


#endif
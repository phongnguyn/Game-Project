#include "header.h"
#include "Player.h"
#include "Person.h"
#include "Machine.h"

#ifndef WIN_H
#define WIN_H

class Win
{
private:
    int mode = 10;
    int stage = 0;
    Person* player1;
    Person* player2;
public:
    //constructors
    Win();

    //gameplay functionality
    void check_stage();
    void selectionScreen();
    int characterSelectionScreen();
    void gamePlay();
    void gameOver();
    int getStage() {return stage;}

    //destructor
    ~Win();
};

//constructor
Win::Win(){ }

//controls functionality after game finishes
void Win::gameOver() {
    //Outputs winner
    system("clear");
    if(player1->getPlayer()->getHealth() > 0){
        cout  << player1->getPlayer()->getName() << " Won!\n";
    }else{
        cout << player2->getPlayer()->getName() << "Won!\n";
    }
    cout << "press 'y' to replay 'n' to exit game!\n";
    //determines whether to replay
    string in;
    while (!(cin >> in) && !(in == "y" && in == "n")) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "invalid input, try again\n";
    }

    if(in == "y"){
        stage = 0;
    }else{
        stage = 5;
    }
}

//displays players stats
void display(Person* _player){
    cout << _player->getPlayer()->getName() << endl;
    cout << "Health: " << _player->getPlayer()->getHealth() << endl;
    cout << "Stamina: " << _player->getPlayer()->getStamina() << endl;
    cout << endl;
}

//controls gameplay
void Win::gamePlay() {
    system("clear");
    display(player1);
    display(player2);

    while (player1->getPlayer()->getHealth() > 0 && player2->getPlayer()->getHealth() > 0) {
        player1->chooseAbilities();
        if(player2->getPlayer()->getHealth() > 0){
            player2->chooseAbilities();
            display(player1);
            display(player2);
        }
    }
    stage++;
}

//controls character selection
int Win::characterSelectionScreen() {
    cout << "list of characters:\n";
    cout << "1 : Reinhardt\n";
    cout << "2 : Ezio\n";
    cout << "3 : Gandalf\n";
    cout << "4 : Altair\n";
    int num = 0;
    while ((cout << "please select a character labeled 1 to 4: ") && !(cin >> num) || (num > 4) || (num < 1)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "invalid input, try again\n";
    }
    return num;
}

//controls gamemode selection and player allocation
void Win::selectionScreen() {
    while ((cout << "please select the game mode, O: single player, 1: multiplayer:") && !(cin >> mode) || (mode > 1) || (mode < 0)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "invalid input, try again\n";
    }
    player1 = new Person(characterSelectionScreen(), 0);

    if (mode) {
        player2 = new Person(characterSelectionScreen(), 0);
    }   else player2 = new Machine();

    player1->getPlayer()->setOpponent(player2->getPlayer());  
    player2->getPlayer()->setOpponent(player1->getPlayer()); 
    stage ++;
}

//determines which stage to show to user
void Win::check_stage() {
    switch(stage) {
        case 0:
            selectionScreen();
            break;
        case 1:
            gamePlay();
            break;
        case 2:
            gameOver();
            break;
    }
}

Win::~Win()
{
}


#endif
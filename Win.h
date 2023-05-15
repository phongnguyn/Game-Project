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
    //constructor
    Win(/* args */);

    //determines stage to play
    void check_stage();

    //determines whether single or multiplayer will be played
    void selectionScreen();

    //controls character selection
    int characterSelectionScreen();

    //controls gameplay
    void gamePlay();

    //controls functionality after game end
    void gameOver();

    //returns stage player is currently in 
    int getStage() {return stage;}
    ~Win();
};

Win::Win(/* args */)
{
    
}

//controls functionality after game ends
void Win::gameOver() {
    cout << "Player 1 " << (player1->getPlayer()->getHealth() < 0) ? "lost" : "win \n";
    cout << ((mode) ? "Player 2" : "Machine") << (player2->getPlayer()->getHealth() < 0) ? "lost" : "win \n";
    cout << "Play Again? (y/n)\n";
    string in;
    while (!(cin >> in) && !(in == "y" && in == "n")) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "invalid input, try again\n";
    }
}

//controls gameplay
void Win::gamePlay() {
    while (player1->getPlayer()->getHealth() > 0 && player2->getPlayer()->getHealth() > 0) {
        player1->chooseAbilities();
        player2->chooseAbilities();
    }
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

//controls gametype selection
void Win::selectionScreen() {
    while ((cout << "please select the game mode, O: single player, 1: multiplayer:") && !(cin >> mode) || (mode > 1) || (mode < 0)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "invalid input, try again\n";
    }
    player1 = new Person(characterSelectionScreen());

    if (mode) {
        player2 = new Person(characterSelectionScreen());
    }   else player2 = new Machine();

    //player1->getPlayer()->setOpponent(player2->getPlayer());  
   // player2->getPlayer()->setOpponent(player1->getPlayer()); 
    stage ++;
}

//determines what stage of gameplay should be running
void Win::check_stage() {
    switch(stage) {
        case 0:
            Win::selectionScreen();
            break;
        case 1:
            Win::gamePlay();
            break;
        case 2:

            break;
    }
}

Win::~Win()
{
}


#endif
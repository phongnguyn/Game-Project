#include <iostream>
#include <stdlib.h>
#include "Player.h"
#include "Warrior.h"
#include "Tanker.h"
#include "Reinhardt.h"
using namespace std;

//used to ensure input is integer
bool check_int(string i){
    if (i.length() > 1) return true;
    if(isdigit(i[0])) return false;
    return true;
}

//determines single player (1) or multiplayer (2)
int modeSelect(){
    //gathers input
    string input = "";
    cout << "SELECT MODE!\n";
    cout << "type 1 for single player 2 for two player\n";
    cout << "game mode: ";
    cin >> input;
    cout << input << endl;
    cout << check_int(input);

    //ensures valid input
    while(check_int(input)|| stoi(input) < 1 || stoi(input) > 2){
        system("clear");
        cout << "SELECT MODE!\n";
        cout << "type 1 for single player 2 for two player\n";
        cout << "please enter valid input!\n";
        cout << "game mode: ";
        cin >> input;
    }

    return stoi(input);
}



//determines character selection
int characterSelect(){
    //gets input
    string input = "";
    system("clear");
    cout << "CHARACTER SELECTION!\n\n";
    cout << "type corresponding number to select character\n";
    cout << "1 : Reinhardt - about Reinhardt\n";
    cout << "2 : Ezio - about Ezio\n";
    cout << "3 : Gandalf - about Gandalf\n";
    cout << "4 : Altair - about Altair\n";
    cin >> input ;

    //ensures valid input
    while (check_int(input) || stoi(input) < 1 || stoi(input) > 4){
        system("clear");
        cout << "CHARACTER SELECTION!\n\n";
        cout << "type corresponding number to select character\n";
        cout << "PLEASE ENTER VALID INPUT\n";
        cout << "1 : Reinhardt - about Reinhardt\n";
        cout << "2 : Ezio - about Ezio\n";
        cout << "3 : Gandalf - about Gandalf\n";
        cout << "4 : Altair - about Altair\n";
        cin >> input ;
    }

    return stoi(input);
}

//Character stats
void display(Player* _character){
    cout << "Player: " << _character->getName() << endl;
    cout << "Health: " << _character->getHealth()<< endl;
    cout << "Stamina: " << _character->getStamina()<< endl;
}

void gameplay(Reinhardt* _char){
    _char->showAbilities();
}


//single player gameplay
void Multiplayer(){
    //allocates / creates characters
    Player* character1;
    int character1ID = characterSelect();
    if(character1ID == 1){
        character1 = new Reinhardt();
    }

    int character2ID = characterSelect();
    Player* character2;
    if(character2ID == 1){
        character2 = new Reinhardt();
    }

    //displays stats
    display(character1);
    cout << "\n\n";
    display(character2);

    cout << character1->getName() << "'s turn!\n";
    void gameplay();
}

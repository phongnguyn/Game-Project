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
    Person** player;
    string _filename = "saved.txt";
public:
    Win(/* args */);
    void check_stage();
    void loadingScreen();
    void selectionScreen();
    int characterSelectionScreen(string);
    void displayStat(Person*);
    void gamePlay();
    void gameOver();
    int getStage() {return stage;}
    ~Win();
};

Win::Win(/* args */)
{
    player = new Person*[2];
}

void Win::gameOver() {
    fstream _file;

    const auto now = std::chrono::system_clock::now();
    const std::time_t t_c = std::chrono::system_clock::to_time_t(now);

    _file.open(_filename, ios::out);

    _file << std::ctime(&t_c) << ": ";
    //Outputs winner and save winner to a saved file
    if(player[0]->getPlayer()->getHealth() > 0){
        cout  << player[0]->getPlayer()->getName() << " Won!\n";
        if (_file.is_open()) {
            _file << player[0]->getPlayer()->getName() << " Won!\n";
        }
    }else{
        cout << player[1]->getPlayer()->getName() << "Won!\n";
        if (_file.is_open()) {
            _file << player[1]->getPlayer()->getName() << " Won!\n";
        }
    }
    cout << "press 'y' to replay 'n' to exit game!\n";

    _file.close();
    //determines whether to replay
    string in;
    while (!(cin >> in) && !(in == "y" && in == "n")) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "invalid input, try again by selecting y or n\n";
    }
    if (in == "y") {system("clear"); stage = 0;}
    
    else stage ++;
}

void Win::displayStat(Person* _player) {
    cout << _player->getPlayer()->getName() << endl;
    cout << "Health: " << _player->getPlayer()->getHealth() << endl;
    cout << "Stamina: " << _player->getPlayer()->getStamina() << endl;
    cout << endl;
}

void Win::gamePlay() {
    while (player[0]->getPlayer()->getHealth() > 0 && player[1]->getPlayer()->getHealth() > 0) {
        system("clear");
        displayStat(player[0]);
        displayStat(player[1]);
        player[0]->chooseAbilities();

        if (player[1]->getPlayer()->getHealth() <= 0) break;

        player[1]->chooseAbilities();

        cout << "Press Any Key to Continue\n";
        getchar();
        getchar();
    }
    stage ++;
}

//controls character selection

int Win::characterSelectionScreen(string name) {
    
    int num = 0;
    while ((cout << name << " selects: ") && !(cin >> num) && (num > 4) || (num < 1)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "invalid input, try again by selecting a number from 1 to 4 \n";
    }
    return num;
}

//controls gamemode selection and player allocation

void Win::selectionScreen() {
    while ((cout << "please select the game mode\n 1: single player\n 2: multiplayer\n") && !(cin >> mode) || (mode > 2) || (mode < 1)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "invalid input, try again by selecting either 1 or 2 \n";
    }

    cout << "list of characters:\n";
    cout << "1 : Reinhardt\n";
    cout << "2 : Ezio\n";
    cout << "3 : Gandalf\n";
    cout << "4 : Altair\n";

    player[0] = new Person(characterSelectionScreen("Player 1"));
    player[0]->getPlayer()->setName("Player 1");

    if (mode == 2) {
        player[1] = new Person(characterSelectionScreen("Player 2"));
        player[1]->getPlayer()->setName("Player 2");
    }   else player[1] = new Machine();

    player[0]->getPlayer()->setOpponent(player[1]->getPlayer());  
    player[1]->getPlayer()->setOpponent(player[0]->getPlayer()); 
    stage ++;
}

void Win::loadingScreen() {
    cout << "0 : new game \n";
    cout << "1 : load game history \n";
    int mode;
    fstream _file;
    while (!(cin >> mode) || (mode > 1) || (mode < 0)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "invalid input, try again please select either 0 or 1 \n";
    }

    if (mode) {
        _file.open(_filename, ios::in);
        if (_file.is_open()) {
            string line;
            while (getline(_file, line)) cout << line << endl;
            _file.close();
        }
        cout << "Press any key to continue\n"; 
        getchar();
        getchar();

    }
    stage ++;
}

void Win::check_stage() {
    system("clear");
    switch(stage) {
        case 0: 
            loadingScreen();
            break;
        case 1:
            Win::selectionScreen(); //inheritance, 
            break;
        case 2:
            Win::gamePlay();
            break;
        case 3:
            Win::gameOver();
            break;
    }
}

Win::~Win()
{
    delete [] player;
}


#endif
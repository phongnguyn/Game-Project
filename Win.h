#include "header.h"
#include "Player.h"

#ifndef WIN_H
#define WIN_H

class Win
{
private:
    sf::RenderWindow* window;
    int stage = 0;
    Player* player;
public:
    Win(/* args */);
    void check_stage();
    void gameStarted();
    void gamePlay();
    void gameOver();
    ~Win();
};

Win::Win(/* args */)
{
    window = new sf::RenderWindow(sf::VideoMode(200, 200), "SFML works!");
}

void Win::check_stage() {
    switch(stage) {
        case 0:
            
        break;
        case 1:

        break;
        case 2:

        break;
        
    }
}

Win::~Win()
{
}


#endif
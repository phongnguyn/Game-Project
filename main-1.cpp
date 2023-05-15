#include <iostream>
using namespace std;

int modeSelect();
int characterSelect();
void Multiplayer();


int main(){
    modeSelect();
    if(modeSelect() == 2){
        Multiplayer();
    }
    return 0;
}
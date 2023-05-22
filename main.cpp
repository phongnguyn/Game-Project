#include "header.h"
#include "Win.h"

int main() {
    //instantiates window
    Win win;
    srand(time(NULL));
    
    cout << "Let the battle begin!" << endl;
    
    //game loop
    while (win.getStage() < 5) {
        win.check_stage();
    }
    
    return 0;
}

#include "header.h"
#include "Win.h"

int main() {
    Win win;
    srand(time(NULL));
    
    cout << "Let the battle begin!" << endl;
    
    while (win.getStage() < 5) {
        win.check_stage();
    }
    
    return 0;
}

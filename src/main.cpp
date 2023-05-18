#include "header.h"
#include "Win.h"

int main() {
    Win win;
    srand(time(NULL));
    
    cout << "Do you want to know about the Characters' info before playing? (y/n)\n";

    string op;
    while (!(cin >> op) && !(op == "y" && op == "n")) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "invalid input, try again\n";
    }

    if (op == "y") system("google-chrome https://phongnguyn.github.io/Game-Project/");

    system("clear");

    cout << "Let the battle begin!" << endl;
    
    while (win.getStage() < 5) {
        win.check_stage();
    }
    
    return 0;
}

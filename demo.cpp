#include "demo.h"

void PrintMenu() {
    cout << "\n\n1. Play game\n"
        "2. Exit Program";
}

void PlayGame() {
    Game newGame;

    newGame.Play();
}
void ExitMessage() {
    cout << "\n\nProgram will exit\n";
}
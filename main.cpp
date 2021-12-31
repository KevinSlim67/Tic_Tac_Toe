#include "libraries.h"
#include "board\printBoard.cpp"
#include "board\updateBoard.cpp"

#include "moves\inputMove.cpp"
#include "moves\generateMove.cpp"

void checkGameState();

int main() {
printBoard();
while (true) {
    inputMove();
    updateBoard();
    //checkGameState();
    generateMove();
    updateBoard();
    //checkGameState();
    }

system("pause");
return 0;
}

void checkGameState() {
     /* 
    if (check function) {
        insert win function
    } else {
        insert lose function
    }

    if (player.moves_count + computer.moves_count == 9) {
        insert draw function
    }
    */
}
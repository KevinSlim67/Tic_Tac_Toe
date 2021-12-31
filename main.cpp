#include "libraries.h"
#include "board\printBoard.cpp"
#include "moves\inputMove.cpp"
#include "board\updateBoard.cpp"

int main() {
printBoard();
while (true) {
    inputMove();
    updateBoard();
    }

system("pause");
return 0;
}
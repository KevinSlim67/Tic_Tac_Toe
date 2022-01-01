#include "libraries.h"
#include "board\printBoard.cpp"
#include "board\updateBoard.cpp"

#include "moves\inputMove.cpp"
#include "moves\generateMove.cpp"

#include "checkVictory.cpp"

int main() {
    printBoard();

    while (true) {
        inputMove();
        updateBoard();

        if (checkVictory(player)) {
            cout << endl;
            cout << "**** Congratulation, you have won ! ****\n" << endl;
            goto end;
        }

        generateMove();
        updateBoard();

        if (checkVictory(computer)) {
            cout << endl;
            cout << "**** Sorry, you have lost ! :( ****\n" << endl;
            goto end;
        }

        if (player.moves_count + computer.moves_count == 9) {
            cout << endl;
            cout << "**** It's a tie ! ****\n" << endl;
            goto end; 
        }
    }
end: //when the code reaches goto end;
     //it will come to this point
    system("pause");
    return 0;
}

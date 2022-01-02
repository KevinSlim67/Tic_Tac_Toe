#include "colors.cpp"
#include <cstdlib> //for system("pause");

#include "board\printBoard.cpp"
#include "board\updateBoard.cpp"

#include "moves\inputMove.cpp"
#include "moves\generateMove.cpp"

#include "checkVictory.cpp"
#include "selectFirstPlayer.cpp"

#include <ctime> //for time(0)

void playerStartsFirst();
void computerStartsFirst();
void win();
void lose();
void tie();

int main() {
    srand(time(0));
    printBoard();

    if (selectFirstPlayer() == 1) {
        playerStartsFirst();
    } else {
        computerStartsFirst();
    }

    system("pause");
    return 0;
}

void playerStartsFirst() {
    while (true) {
        inputMove();
        updateBoard();

        if (checkVictory(player)) {
            win();
            break;
        }

        //the tie is always going to happen after the player's turn
        //meaning there's no point in putting it after generateMove()
        //since it'll never happen after the computer's turn
        if (player.moves_count + computer.moves_count == 9) {
            tie();
            break;
        }

        generateMove();
        updateBoard();

        if (checkVictory(computer)) {
            lose();
            break;
        }
    }
}

void computerStartsFirst() {
     while (true) {
        
        generateMove();
        updateBoard();

        if (checkVictory(computer)) {
            win();
            break;
        }
        

        //the tie is always going to happen after the computer's turn
        //meaning there's no point in putting it after inputMove()
        //since it'll never happen after the player's turn
        if (player.moves_count + computer.moves_count == 9) {
            tie();
            break;
        }

        inputMove();
        updateBoard();

        if (checkVictory(player)) {
            win();
            break;
        }
    }
}

void win() {
    cout << endl;
    printYellow("**** Congratulation, you have won ! :) ****\n");
}

void lose() {
    cout << endl;
    printRed("**** Sorry, you have lost ! :( ****\n");
}

void tie() {
    cout << endl;
    printBrown("**** It's a tie ! :| ****\n");
}


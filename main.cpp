#include "libraries.h"
#include "board\printBoard.cpp"
#include "board\updateBoard.cpp"

#include "moves\inputMove.cpp"
#include "moves\generateMove.cpp"

#include "checkVictory.cpp"

void win();
void lose();
void tie();

int main() {
    printBoard();

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

    system("pause");
    return 0;
}

void win() {
    cout << endl;
    SetConsoleTextAttribute(h, 10); //changes the color of the text to green from that point on
    cout << "**** Congratulation, you have won ! :) ****\n" << endl;
    SetConsoleTextAttribute(h, 15); //changes the color of the text to white from that point on
}

void lose() {
    cout << endl;
    SetConsoleTextAttribute(h, 12); //changes the color of the text to light red from that point on
    cout << "**** Sorry, you have lost ! :( ****\n" << endl;
    SetConsoleTextAttribute(h, 15); //changes the color of the text to white from that point on
}

void tie() {
    cout << endl;
    SetConsoleTextAttribute(h, 6); //changes the color of the text to brow from that point on
    cout << "**** It's a tie ! :| ****\n" << endl;
    SetConsoleTextAttribute(h, 15); //changes the color of the text to white from that point on
}


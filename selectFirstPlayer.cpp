#include "libraries.h"
#include "variables.h"

#include "board\printBoard.cpp"
#include "board\updateBoard.cpp"

#include "moves\inputMove.cpp"
#include "moves\generateMove.cpp"

#include "checkVictory.cpp"

void win();
void lose();
void tie();

//this function indicates on the screen which player starts first and returns 1 or 2 which is used in an if
//statement to know which function playerStartsFirst() or computerStartsFirst() is run
int selectFirstPlayer () {
    int result = (rand() % 2) + 1;
    if (result == 1) {
        printYellow(player.name);
        printYellow( " is starting !\n");
    } else {
        printRed(computer.name);
        printRed( " is starting !\n");
    }
    return result;
}

void playerStartsFirst() {
    while (true) {
        inputMove();
        updateBoard();

        if (checkVictory(player, computer)) {
            win();
            break;
        }

        //the tie is always going to happen after the player's turn
        //meaning there's no point in putting it after generateMove()
        //since it'll never happen after the computer's turn
        if (tiles_used == 9) {
            tie();
            break;
        }

        generateMove();
        updateBoard();

        if (checkVictory(computer, player)) {
            lose();
            break;
        }
    }
}

void computerStartsFirst() {
     while (true) {
        
        generateMove();
        updateBoard();

        if (checkVictory(computer, player)) {
            lose();
            break;
        }
        

        //the tie is always going to happen after the computer's turn
        //meaning there's no point in putting it after inputMove()
        //since it'll never happen after the player's turn
        if (tiles_used == 9) {
            tie();
            break;
        }

        inputMove();
        updateBoard();

        if (checkVictory(player, computer)) {
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
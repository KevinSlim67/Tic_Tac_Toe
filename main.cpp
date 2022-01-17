#include "colors.cpp"
#include <cstdlib> //for system("pause");
#include <string>

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
void inputDifficulty();

int main() {
    srand(time(0));
    inputDifficulty();
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
    printGray("**** It's a tie ! :| ****\n");
}

using std::string;
void inputDifficulty() {
    do {
        cout << "Please select a difficulty (Easy/Medium/Hard): ";
        getline(cin,difficulty);
        for (int i = 0; i < difficulty.length(); i++) {
            difficulty[i] = tolower(difficulty[i]);
        //transforms every character in this string to lowercase
        //this makes conditions later on easier to deal with
        }
    } while (difficulty.compare("easy") != 0 && difficulty.compare("medium") && difficulty.compare("hard"));
}

#include <cstdlib> //for system("pause");
#include "selectFirstPlayer.cpp"
#include <ctime> //for time(0)

void inputDifficulty();
string playAgain();
void setValues();

int main() {
    srand(time(0)); //chooses random seed for which the rand() functions will use

    do {
        inputDifficulty();
        setValues();
        printBoard();

        if (selectFirstPlayer() == 1) {
            playerStartsFirst();
        } else {
            computerStartsFirst();
        }

    } while (playAgain().compare("restart") == 0);

    system("pause");
    return 0;
}

//this function lets the user input the difficulty they wish to play on
using std::string;
void inputDifficulty() {
    do {
        cout << "Please select a difficulty (Easy/Medium/Hard): ";
        cin >> difficulty;
        for (int i = 0; i < difficulty.length(); i++) {
            difficulty[i] = tolower(difficulty[i]);
        //transforms every character in this string to lowercase
        //this makes conditions later on easier to deal with
        }
    } while (difficulty.compare("easy") != 0 && difficulty.compare("medium") != 0 && difficulty.compare("hard") != 0);
}

//checks if the player wants to play again
string playAgain() {
    string check_restart;
    cout << "If you wish to play again, write \"restart\", if not, write anything else : ";
    cin >> check_restart;
    for (int i = 0; i < check_restart.length(); i++) {
            check_restart[i] = tolower(check_restart[i]);
    }

    if (check_restart.compare("restart") == 0) {
        system("cls"); //clears screen
    }

    return check_restart;
}

//sets important values for the game back to 0, NULL, or false
void setValues() {
    tiles_used = 0;
    for (int i = 0; i < DIMENSION; i++) {
        for (int j = 0; j < DIMENSION; j++) {
            tiles[i][j].hasValue = false ;
            tiles[i][j].value = {NULL};
        }
    }
    
    player.moves_count = 0;
    computer.moves_count = 0;
}
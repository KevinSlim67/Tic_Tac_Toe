#include "colors.cpp"
#include <cstdlib> //for system("pause");

#include "selectFirstPlayer.cpp"

#include <ctime> //for time(0)

void inputDifficulty();

int main() {
    srand(time(0)); //chooses random seed for which the rand() functions will use
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

//this function lets the user input the difficulty they wish to play on
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

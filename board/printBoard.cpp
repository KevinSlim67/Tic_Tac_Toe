//This function prints the board the very beginning
//I used this instead of updateBoard() as to not check unnecessary conditions
#include "../libraries.h"
#include "../variables.h"
#include "../colors.cpp"

void initializeTiles();
void initializePlayers();

void printBoard() {
    cout << setw(space_size + 3) << "A" << setw(space_size) << "B" << setw(space_size) << "C" << endl;
    for (int i = 0; i < DIMENSION; i++) {
        cout <<  i + 1;
        for (int j = 0; j < DIMENSION; j++) {
            cout << setw(space_size) << "|";
        }
        cout << setw(space_size) << "|" << endl;
        cout << "    -------------" << endl;
    }

    initializeTiles();
    initializePlayers();
}

//this function initializes the tiles positions
void initializeTiles() {

    tiles[0][0].position = "A1";
    tiles[1][0].position = "A2";
    tiles[2][0].position = "A3";
    tiles[0][1].position = "B1";
    tiles[1][1].position = "B2";
    tiles[2][1].position = "B3";
    tiles[0][2].position = "C1";
    tiles[1][2].position = "C2";
    tiles[2][2].position = "C3";

}

void initializePlayers() {
    player.name = "Player 1";
    player.mark = "X";

    computer.name = "Player 2";
    computer.mark = "O";
}
//This function prints the board the very beginning
//I used this instead of updateBoard() as to not check unnecessary conditions
#include "../libraries.h"
#include "../initializeTiles.cpp"
#include "../variables.h"

void printBoard() {
    cout << setw(space_size + 3) << "A" << setw(space_size) << "B" << setw(space_size) << "C" << endl;
    for (int i = 0; i < DIMENSION; i++) {
        cout <<  i + 1;
        for (int j = 0; j < DIMENSION; j++) {
            cout << setw(space_size) << "|";
        }
        cout << setw(space_size) << "|" << endl;
        cout << "   ----------" << endl;
    }

    initializeTiles();
}
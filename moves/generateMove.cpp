#include "../libraries.h"
#include "../variables.h"
#include "updateComputerMove.cpp"
#include <ctime>


void generateMove() {
    srand(time(0));
    char column;
    int row;
    int x, y;

    cout << "Opponent's turn : " << endl;

    //will choose a random column, and a random row
    //it will keep looping until it finds a tile with no X or O on it
    do {
        y = rand() % 3;
        x = rand() % 3;
        column = y + 'A'; //chooses a letter between A and C
        row = x + 1; //chooses a number betwen 1 and 3
        cout << column << row << endl;

        //prevents the loop to repeat infinitely once there's no free tiles anymore
        if (player.moves_count + computer.moves_count == 9) {
            return;
            }

    } while (tiles[x][y].hasValue);

    string result = column + std::to_string(row);
    //std::to_string() converts whatever type into a string
    
    updateComputerMove(result);
}
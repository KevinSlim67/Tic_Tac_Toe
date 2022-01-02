#include "../libraries.h"
#include "../variables.h"
#include "updateComputerMove.cpp"


void generateMove() {
    char column;
    int row;
    int x, y;

    //will choose a random column, and a random row
    //it will keep looping until it finds a tile with no X or O on it
    do {
        y = rand() % 3;
        x = rand() % 3;
        column = y + 'A'; //chooses a letter between A and C
        row = x + 1; //chooses a number betwen 1 and 3

        //prevents the loop to repeat infinitely once there's no free tiles anymore
        //this condition should theoretically never be needed since the draw is always going to happen on the
        //player's turn, but it is kept here as a safety measure.
        if (player.moves_count + computer.moves_count == 9) {
            return;
            }

    } while (tiles[x][y].hasValue);

    string result = column + std::to_string(row);
    //std::to_string() converts whatever type into a string

    cout << "Computer's Move : " << result << endl;
    
    updateComputerMove(result);
}
#include "../libraries.h"
#include "../variables.h"
#include "../checkTiles.cpp"
#include "../colors.cpp"
#include "updateComputerMove.cpp"

string result;

string generateRandomly();
string generateSlightlySmartMove();
string generateSmartMove();

void generateMove() {

    if (difficulty.compare("easy") == 0) {
        result = generateRandomly();
    } else if (difficulty.compare("medium") == 0) {
        result = generateSlightlySmartMove();
    } else if (difficulty.compare("hard") == 0) {
        result = generateSmartMove();
    }

    printRed("Computer's Move : ");
    cout << result << endl;
    
    updateComputerMove(result);
}

string generateRandomly() {
    char column;
    int row;
    int x, y;
    //will choose a random column, and a random row
    //it will keep looping until it finds a tile with no X or O on it
    do {
        y = rand() % DIMENSION;
        x = rand() % DIMENSION;
        column = y + 'A'; //chooses a letter between A and C
        row = x + 1; //chooses a number betwen 1 and 3

    } while (tiles[x][y].hasValue);

    return tiles[x][y].position;
}

string generateSlightlySmartMove() {

    /* Checks if there's any win available, and if there is, it wins the game */
    if (checkHorizontalLines(computer, player, 2)) {
        return getHorizontalCase(computer, 2);

    } else if (checkVerticalLines(computer, player, 2)) {
        return getVerticalCase(computer, 2);

    } else if (checkLeftDiagonal(computer, player, 2)) {
        return getLeftDiagonalCase(computer, 2);

    } else if (checkRightDiagonal(computer, player, 2)) {
        return getRightDiagonalCase(computer, 2);
    } 

    /* Checks if the player's about to win, if it's the case, it blocks the win for them */
    if (checkHorizontalLines(player, computer, 2)) {
        return getHorizontalCase(player, 2);

    } else if (checkVerticalLines(player, computer, 2)) {
        return getVerticalCase(player, 2);

    } else if (checkLeftDiagonal(player, computer, 2)) {
        return getLeftDiagonalCase(player, 2);

    } else if (checkRightDiagonal(player, computer, 2)) {
        return getRightDiagonalCase(player, 2);
    }

    // When there's no win to block, or no win to take, this function will just generate a random move
    return generateRandomly();
}

string generateSmartMove() {
    //the first move should always be on one of the following : A1, C1, B2, A3, C3
    //the algorithm is similar to medium, but the functions run in a random order
    //instead of randomly choosing moves, it should use one of the get...() functions to see what it can complete

    return "null";
}
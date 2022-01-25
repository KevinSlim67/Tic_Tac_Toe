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

//--------------------------Easy Difficulty Functions--------------------------------

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

//--------------------------Medium Difficulty Functions------------------------------

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

//--------------------------Hard Difficulty Functions--------------------------------

string generateBestFirstMove();
string generateFunctionsSequence(Player p, Player p2, int di);

string generateSmartMove() {
    string result;
    //the first move should always be on one of the following : A1, C1, B2, A3, C3
    //the algorithm is similar to medium, but the functions run in a random order
    //instead of randomly choosing moves, it should use one of the get...() functions to see what it can complete

    if (computer.moves_count != 0) {

        result = generateFunctionsSequence(computer, player, 2); //checks every possibility to win in a random order
        if (result.compare("null") != 0) {
            return result;
        }

        result = generateFunctionsSequence(player, computer, 2); //checks every possibility to block in a random order
        if (result.compare("null") != 0) {
            return result;
        }

        result = generateFunctionsSequence(computer, player, 1); //tries to generate a move on a row, column, or diagonal
        if (result.compare("null") != 0) {                       //that contains another 'O' value
            return result;
        }

        return generateRandomly(); //if none of the previous conditions happen, it'll just generate a random move
        
    } else {
        return generateBestFirstMove();
    }

    return "null";
}

//generates move at A1, C1, B2, A3, C3, which are the best positions to start at
string generateBestFirstMove() {
    int random;
    string result = "null";
    while (result.compare("null") == 0) {
        random = (rand() % 5) + 1;
        switch (random) {
            case 1 :
                if (!tiles[0][0].hasValue) {
                    result = tiles[0][0].position; //A1
                    }
                break;
            case 2 :
                if (!tiles[0][2].hasValue) {
                    result = tiles[0][2].position; //C1
                    }
                break;
            case 3 :
                if (!tiles[1][1].hasValue) {
                    result = tiles[1][1].position; //B2
                    }
                break;
            case 4 :
                if (!tiles[2][0].hasValue) {
                    result = tiles[2][0].position; //A3 
                    }
                break;
            case 5 :
                if (!tiles[2][2].hasValue) {
                    result = tiles[2][2].position; //C3
                    }
                break;
        }
    }

    return result;
}

//randomly generates the order in which the same functions used in medium are used
string generateFunctionsSequence(Player p, Player p2, int dim) {
    int random;
    int temp[4] = {-1};
    int count = 0;
    random = (rand() % 4) + 1;
    do {
        do {
            random = (rand() % 4) + 1;
        } while (random == temp[0] || random == temp[1] || random == temp[2] || random == temp[3]);

        switch (random) {
            case 1 : 
                if (checkHorizontalLines(p, p2, dim)) {
                    return getHorizontalCase(p, dim);
                }
                break;
            case 2 : 
                if (checkVerticalLines(p, p2, dim)) {
                    return getVerticalCase(p, dim);
                }
                break;
            case 3 : 
                if (checkLeftDiagonal(p, p2, dim)) {
                    return getLeftDiagonalCase(p, dim);
                }
                break;
            case 4 : 
                if (checkRightDiagonal(p, p2, dim)) {
                    return getRightDiagonalCase(p, dim);
                }
                break;
        }

        temp[count] = random;
        count++;

    } while (count < 4);
    
    return "null";
}
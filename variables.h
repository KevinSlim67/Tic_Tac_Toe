#ifndef VARIABLES_H_
#define VARIABLES_H_

#include <string>
using std::string;

const int DIMENSION = 3; //dimensions of the board
const int space_size = 3;

struct Tile {
    string position;
    bool hasValue = false;
};

struct Player {
    string moves[5]; //neither player can play more than 5 moves
    int moves_count = 0;
};

Tile tiles[DIMENSION][DIMENSION];
Player player;
Player computer;
int hasMark[DIMENSION][DIMENSION] = { false };
int tiles_used = 0;

#endif
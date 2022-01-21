#ifndef VARIABLES_H_
#define VARIABLES_H_

#include <string>
using std::string;

const int DIMENSION = 3; //dimensions of the board
const int space_size = 4;

struct Tile {
    string position;
    bool hasValue;
    string value; // "X" or "O"
};

struct Player {
    string name;
    int moves_count;
    string mark; // "X" or "O"
};


string difficulty;
Tile tiles[DIMENSION][DIMENSION];
Player player;
Player computer;

int tiles_used;

#endif

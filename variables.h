#ifndef VARIABLES_H_
#define VARIABLES_H_

#include <string>
#include <Windows.h> //to be able to use HANDLE
using std::string;

const int DIMENSION = 3; //dimensions of the board
const int space_size = 4;
HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
// BLACK 0, BLUE 1, GREEN 2, CYAN 3, RED 4, MAGENTA 5, BROWN 6, LIGHT GREY 7, DARK GREY 8,
// LIGHT BLUE 9, LIGHT GREEN 10, LIGHT CYAN 11, LIGHT RED 12, LIGHT MAGENTA 13, 
// YELLOW 14, WHITE 15,

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

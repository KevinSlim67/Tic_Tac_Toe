#include "libraries.h"
#include "variables.h"
#include "checkTiles.cpp"
using std::string;

bool checkVictory(Player p, Player enemy) {

    //players can't win until their third turn, this prevents the rest of this function from running
    //until the player has reached their third turn
    if (p.moves_count < 3) {
        return false;
    }

    if (checkHorizontalLines(p, enemy, DIMENSION) || checkVerticalLines(p, enemy, DIMENSION) 
        || checkDiagonals(p, enemy, DIMENSION)) {
        return true;
    }

    return false;
}



//this function updates the player's move
#include "../libraries.h"
#include "../variables.h"
using std::string;

void updatePlayerMove(string move) {
    
    for (int i = 0; i < DIMENSION; i++) {
        for (int j = 0; j < DIMENSION; j++) {
            if (tiles[i][j].hasValue)
                continue;
            if (tiles[i][j].position.compare(move) == 0) {
                //.compare() compares the two variables, the one attached and the one in parentheses
                //if they're equal, it will return the value 0 
                tiles[i][j].hasValue = true; //makes sure the tile is not considered empty anymore
                tiles[i][j].value = player.mark; //tiles[x][y].value = "X";
                player.moves_count++;
                tiles_used++;
                return;
            }
        }
    }
    
}
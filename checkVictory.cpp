#include "libraries.h"
#include "variables.h"
using std::string;

bool checkVictory(Player p);

/*  it will check each row, then compare each value the player entered, with all the tiles on that row
    (which are on the 3 columns : A, B, C). If the value and the tile match, it will increment the counter by one. If all
    3 values match the tile, the counter will reach the number 3, and will then exit the function while returning
    true as value. If the counter doesn't reach the value of 3, the function will then move on to the next row and
    repeat the process until there's no more rows. If it reaches the end without returning a value of true, it will
    therefore return false. */
bool checkHorizontalLines(Player p);

/* it will check each column, then compare each value the player entered, with all the tiles on 
    that column (which are on the 3 rows  : 1, 2, 3). If the value and the tile match, it will increment the counter by 
    one. If all 3 values match the tile, the counter will reach the number 3, and will then exit the function while returning
    true as value. If the counter doesn't reach the value of 3, the function will then move on to the next column and
    repeat the process until there's no more columns. If it reaches the end without returning a value of true, it will
    therefore return false. */
bool checkVerticalLines(Player p);
bool checkDiagonals(Player p);

bool checkVictory(Player p) {

    //players can't win until their third turn, this prevents the rest of this function from running
    //until the player has reached their third turn
    if (p.moves_count < 3) {
        return false;
    }

    if (checkHorizontalLines(p) || checkVerticalLines(p) || checkDiagonals(p)) {
        return true;
    }

    return false;
}

bool checkHorizontalLines(Player p) {

    for (int i = '1'; i <= '3'; i++) {
        int count = 0;

        for (int j = 0; j < p.moves_count; j++) {

            char row = p.moves[j][1];
    
            if (row == (char) i) {
                for (int k = 'A'; k <= 'C'; k++) {

                    char column = p.moves[j][0];
                    if (column == (char) k) {
                            count++;
                        }

                        if (count == 3) {
                        return true;
                    }
                }
            }
        }
    }

    return false;
}

bool checkVerticalLines(Player p) {

    for (int i = 'A'; i <= 'C'; i++) {
        int count = 0;

        for (int j = 0; j < p.moves_count; j++) {

            char row = p.moves[j][0];
    
            if (row == (char) i) {
                for (int k = '1'; k <= '3'; k++) {

                    char column = p.moves[j][1];
                    if (column == (char) k) {
                            count++;
                        }

                        if (count == 3) {
                        return true;
                    }
                }
            }
        }
    }

    return false;
}

/* it will compare each value the player entered with the following tiles : A1, B2, C3.
    The counter will increment by one every time one of the values matches one of the aforementionned tiles.
    If 3 of the values the player entere match those tiles, the counter will reach the number 3, and will then exit the
    function while returning true as a value. If the counter doesn't reach the value of 3 by the end, the function will
    return false instead. */
bool checkLeftDiagonal(Player p);

/*  it will compare each value the player entered with the following tiles : C1, B2, A3.
    The counter will increment by one every time one of the values matches one of the aforementionned tiles.
    If 3 of the values the player entere match those tiles, the counter will reach the number 3, and will then exit the
    function while returning true as a value. If the counter doesn't reach the value of 3 by the end, the function will
    return false instead. */
bool checkRightDiagonal(Player p);

bool checkDiagonals(Player p) {

    if (checkLeftDiagonal(p) || checkRightDiagonal(p)) {
        return true;
    }

    return false;
}

bool checkLeftDiagonal(Player p) {

    int count = 0;
        for (int k = 0; k < p.moves_count; k++) {

            for (int i = '1', j = 'A'; i <= '3' && j <= 'C'; i++, j++) {

                char row = p.moves[k][1];
                char column = p.moves[k][0];
                if (row == (char) i && column == (char) j) {
                    count++;
                }

                if (count == 3) {
                    return true;
                }

            }
        }

        return false;
}

bool checkRightDiagonal(Player p) {

    int count = 0;
        for (int k = 0; k < p.moves_count; k++) {

            for (int i = '1', j = 'C'; i <= '3' && j >= 'A'; i++, j--) {

                char row = p.moves[k][1];
                char column = p.moves[k][0];
                if (row == (char) i && column == (char) j) {
                    count++;
                }

                if (count == 3) {
                    return true;
                }

            }
        }

        return false;
}

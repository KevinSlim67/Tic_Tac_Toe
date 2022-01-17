#ifndef CHECKT_H_
#define CHECKT_H_

#include "libraries.h"
#include "variables.h"

/*  it will check each row, then compare each value the player entered, with all the tiles on that row
    (which are on the 3 columns : A, B, C). If the value and the tile match, it will increment the counter by one. If all
    3 values match the tile, the counter will reach the number 3, and will then exit the function while returning
    true as value. If the counter doesn't reach the value of 3, the function will then move on to the next row and
    repeat the process until there's no more rows. If it reaches the end without returning a value of true, it will
    therefore return false. */
bool checkHorizontalLines(Player p, Player p2, int dim) {

    for (char i = '1'; i <= '3'; i++) {
        int count = 0;
        int row_index = i - '1';

        for (int j = 0; j < p.moves_count; j++) {

            char row = p.moves[j][1];
    
            if (row == i) {
                for (char k = 'A'; k <= 'C'; k++) {
                    int column_index = k - 'A';
                    char column = p.moves[j][0];

                    if (tiles[row_index][column_index].value.compare(p2.mark) == 0) {
                        count--;
                    }

                    if (column == k) {
                        count++;
                    }

                    if (count == dim) {
                        return true;
                    }
                }
            }
        }
    }

    return false;
}

/*  it will check each column, then compare each value the player entered, with all the tiles on 
    that column (which are on the 3 rows  : 1, 2, 3). If the value and the tile match, it will increment the counter by 
    one. If all 3 values match the tile, the counter will reach the number 3, and will then exit the function while returning
    true as value. If the counter doesn't reach the value of 3, the function will then move on to the next column and
    repeat the process until there's no more columns. If it reaches the end without returning a value of true, it will
    therefore return false. */
bool checkVerticalLines(Player p, Player p2, int dim) {

    for (char i = 'A'; i <= 'C'; i++) {
        int count = 0;
        int column_index = i - 'A';

        for (int j = 0; j < p.moves_count; j++) {

            char row = p.moves[j][0];
    
            if (row == i) {
                for (char k = '1'; k <= '3'; k++) {

                    int row_index = k - '1';
                    char column = p.moves[j][1];

                    if (tiles[row_index][column_index].value.compare(p2.mark) == 0) {
                        count--;
                    }

                    if (column == k) {
                        count++;
                    }

                    if (count == dim) {
                        return true;
                    }
                }
            }
        }
    }

    return false;
}

/*  it will compare each value the player entered with the following tiles : A1, B2, C3.
    The counter will increment by one every time one of the values matches one of the aforementionned tiles.
    If 3 of the values the player entered match those tiles, the counter will reach the number 3, and will then exit the
    function while returning true as a value. If the counter doesn't reach the value of 3 by the end, the function will
    return false instead. */
bool checkLeftDiagonal(Player p, Player p2, int dim) {

    int count = 0;
    if (tiles[0][0].hasValue) {
        if (tiles[0][0].value.compare(p.mark) == 0) {
            count++;
        } else if (tiles[0][0].value.compare(p2.mark) == 0) {
            count--;
        }
    }

    if (tiles[1][1].hasValue) {
        if (tiles[1][1].value.compare(p.mark) == 0) {
            count++;
        } else if (tiles[1][1].value.compare(p2.mark) == 0) {
            count--;
        }
    }

    if (tiles[2][2].hasValue) {
        if (tiles[2][2].value.compare(p.mark) == 0) {
            count++;
        } else if (tiles[2][2].value.compare(p2.mark) == 0) {
            count--;
        }
    }
        
    if (count == dim) {
        return true;
    }

    return false;
}

/*  it will compare each value the player entered with the following tiles : C1, B2, A3.
    The counter will increment by one every time one of the values matches one of the aforementionned tiles.
    If 3 of the values the player entered match those tiles, the counter will reach the number 3, and will then exit the
    function while returning true as a value. If the counter doesn't reach the value of 3 by the end, the function will
    return false instead. */
bool checkRightDiagonal(Player p, Player p2, int dim) {

       int count = 0;
    if (tiles[0][2].hasValue) {
        if (tiles[0][2].value.compare(p.mark) == 0) {
            count++;
        } else if (tiles[0][2].value.compare(p2.mark) == 0) {
            count--;
        }
    }

    if (tiles[1][1].hasValue) {
        if (tiles[1][1].value.compare(p.mark) == 0) {
            count++;
        } else if (tiles[1][1].value.compare(p2.mark) == 0) {
            count--;
        }
    }

    if (tiles[2][0].hasValue) {
        if (tiles[2][0].value.compare(p.mark) == 0) {
            count++;
        } else if (tiles[2][0].value.compare(p2.mark) == 0) {
            count--;
        }
    }
        
    if (count == dim) {
        return true;
    }

    return false;
}

bool checkDiagonals(Player p, Player p2, int dim) {

    if (checkLeftDiagonal(p, p2, dim) || checkRightDiagonal(p, p2, dim)) {
        return true;
    }

    return false;
}

/* This function goes on each row, and returns the empty case on that row
   This function should only be run after checkHorizontalLines(player, computer, 2) is run */
string getHorizontalCase(Player p, int dim) {

    for (char i = '1'; i <= '3'; i++) {
        int count = 0;
        int row_index = i - '1';

        for (int j = 0; j < p.moves_count; j++) {
            char row = p.moves[j][1];
            if (row == i) {
                char column = p.moves[j][0];
                for (char k = 'A'; k <= 'C'; k++) {
                    if (column == k) {
                        count++;
                    }
                }
            }
        }

         if (count == dim) {
            for (int k = 0; k < 3; k++) {
                if (!tiles[row_index][k].hasValue) {
                    return tiles[row_index][k].position;
                }
            }
        }
    }

    system("pause");
    return "null"; //in case of an error
}

/* This function goes on each column, and returns the empty case on that column
   This function should only be run after checkHorizontalLines(player, computer, 2) is run */
string getVerticalCase(Player p, int dim) {

    for (char i = 'A'; i <= 'C'; i++) {
        int count = 0;
        int column_index = i - 'A';

        for (int j = 0; j < p.moves_count; j++) {
            char column = p.moves[j][0];
            if (column == i) {
                char row = p.moves[j][1];
                for (char k = '1'; k <= '3'; k++) {
                    if (row == k) {
                        count++;
                    }
                }
            }
        }

         if (count == dim) {
            for (int k = 0; k < 3; k++) {
                if (!tiles[k][column_index].hasValue) {
                    return tiles[k][column_index].position;
                }
            }
        }
    }

    system("pause");
    return "null"; //in case of an error
}

#endif
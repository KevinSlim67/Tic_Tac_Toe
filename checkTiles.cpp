#ifndef CHECKT_H_
#define CHECKT_H_

#include "libraries.h"
#include "variables.h"

/*  it will check each row, then compare each value the player entered, with all the tiles on that row
    (which are on the 3 columns : A, B, C). If the value and the tile match, it will increment the counter by one. If all
    "dim" values match the tile, the counter will reach the number "dim", and will then exit the function while returning
    true as value. If the counter doesn't reach the value of "dim", the function will then move on to the next row and
    repeat the process until there's no more rows. If it reaches the end without returning a value of true, it will
    therefore return false. */
bool checkHorizontalLines(Player p, Player p2, int dim) {

    for (int i = 0; i < DIMENSION; i++) {
        int count = 0, count_taken_cases = 0;
        for (char k = 0; k < DIMENSION; k++) {

            if (tiles[i][k].value.compare(p2.mark) == 0) {
                count--;
                count_taken_cases++;
            }

            if (tiles[i][k].value.compare(p.mark) == 0) {
                count++;
                count_taken_cases++;
            }   
        }

        //prevents the function from returning true if count == dim but only because there was an opposing mark somewhere
        //this safety measure is useful when dim == 1
        if (count == dim && count_taken_cases <= dim) {
            return true;
        }   
    }
    return false;
}

/*  it will check each column, then compare each value the player entered, with all the tiles on 
    that column (which are on the 3 rows  : 1, 2, 3). If the value and the tile match, it will increment the counter by 
    one. If all "dim" values match the tile, the counter will reach the number "dim", and will then exit the function while returning
    true as value. If the counter doesn't reach the value of "dim", the function will then move on to the next column and
    repeat the process until there's no more columns. If it reaches the end without returning a value of true, it will
    therefore return false. */
bool checkVerticalLines(Player p, Player p2, int dim) {

    for (int i = 0; i < DIMENSION; i++) {
        int count = 0, count_taken_cases = 0;
        for (int k = 0; k < DIMENSION; k++) {
        
            if (tiles[k][i].value.compare(p2.mark) == 0) {
                count--;
                count_taken_cases++;
            }

            if (tiles[k][i].value.compare(p.mark) == 0) {
                count++;
                count_taken_cases++;
            }
        }

        //prevents the function from returning true if count == dim but only because there was an opposing mark somewhere
        //this safety measure is useful when dim == 1
        if (count == dim && count_taken_cases <= dim) {
            return true;
        }   

    }
    return false;
}

/*  it will compare each value the player entered with the following tiles : A1, B2, C3.
    The counter will increment by one every time one of the values matches one of the aforementionned tiles.
    If "dim" of the values the player entered match those tiles, the counter will reach the number "dim", and will then exit the
    function while returning true as a value. If the counter doesn't reach the value of "dim" by the end, the function will
    return false instead. */
bool checkLeftDiagonal(Player p, Player p2, int dim) {

    int count = 0, count_taken_cases = 0;
    for (int i = 0; i < DIMENSION; i++) {
        if (tiles[i][i].hasValue) {
            if (tiles[i][i].value.compare(p.mark) == 0) {
                count++;
                count_taken_cases++;
            } else if (tiles[i][i].value.compare(p2.mark) == 0) {
                count--;
                count_taken_cases;
            }
        }
    }
    
    //prevents the function from returning true if count == dim but only because there was an opposing mark somewhere
    //this safety measure is useful when dim == 1
    if (count == dim && count_taken_cases <= dim) {
        return true;
    }

    return false;
}

/*  it will compare each value the player entered with the following tiles : C1, B2, A3.
    The counter will increment by one every time one of the values matches one of the aforementionned tiles.
    If "dim" of the values the player entered match those tiles, the counter will reach the number "dim", and will then exit the
    function while returning true as a value. If the counter doesn't reach the value of "dim" by the end, the function will
    return false instead. */
bool checkRightDiagonal(Player p, Player p2, int dim) {

    int count = 0, count_taken_cases = 0;

    for (int i = 0, j = DIMENSION - 1; i < DIMENSION; i++, j--) {
        if (tiles[j][i].hasValue) {
            if (tiles[j][i].value.compare(p.mark) == 0) {
                count++;
                count_taken_cases++;
            } else if (tiles[j][i].value.compare(p2.mark) == 0) {
                count--;
                count_taken_cases;
            }
        }
    }

    //prevents the function from returning true if count == dim but only because there was an opposing mark somewhere
    //this safety measure is useful when dim == 1
    if (count == dim && count_taken_cases <= dim) {
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

/// This function goes on each row, and returns the empty case on that row
string getHorizontalCase(Player p, int dim) {

    for (int i = 0; i < DIMENSION; i++) {
        int count = 0;
            for (int k = 0; k < DIMENSION; k++) {
                if (tiles[i][k].value.compare(p.mark) == 0) {
                    count++;
                }
            }
    
         if (count == dim) {
            for (int k = 0; k < 3; k++) {
                if (!tiles[i][k].hasValue) {
                    return tiles[i][k].position;
                }
            }
        }
    }
    system("pause");
    return "null"; //in case of an error
}

// This function goes on each column, and returns the empty case on that column
string getVerticalCase(Player p, int dim) {

     for (int i = 0; i < DIMENSION; i++) {
        int count = 0;
            for (int k = 0; k < DIMENSION; k++) {
                if (tiles[k][i].value.compare(p.mark) == 0) {
                    count++;
                }
            }
    
         if (count == dim) {
            for (int k = 0; k < 3; k++) {
                if (!tiles[k][i].hasValue) {
                    return tiles[k][i].position;
                }
            }
        }
    }
    system("pause");
    return "null"; //in case of an error
}

/* This function checks the left diagonal, if there are dim number of the same marks on that diagonal,
   and one case is empty, it will fill the empty case with the same mark */
string getLeftDiagonalCase(Player p, int dim) {
    int count = 0;

    for (int i = 0; i < DIMENSION; i++) {
        if (tiles[i][i].hasValue) {
            if (tiles[i][i].value.compare(p.mark) == 0) {
                count++;
            }
        }
    }

    if (count == dim) {
        for (int i = 0; i < DIMENSION; i++) {
            if (!tiles[i][i].hasValue) {
                return tiles[i][i].position;
            }
        }
    }

    system("pause");
    return "null"; //in case of an error
}

/* This function checks the right diagonal, if there are dim number of the same marks on that diagonal,
   and one case is empty, it will fill the empty case with the same mark */
string getRightDiagonalCase(Player p, int dim) {
    int count = 0;

    for (int i = 0, j = DIMENSION - 1; i < DIMENSION; i++, j--) {
        if (tiles[j][i].hasValue) {
            if (tiles[j][i].value.compare(p.mark) == 0) {
                count++;
            }
        }
    }

    if (count == dim) {
        for (int i = 0, j = DIMENSION - 1; i < DIMENSION; i++, j--) {
            if (!tiles[j][i].hasValue) {
                return tiles[j][i].position;
            }
        }
    }

    system("pause");
    return "null"; //in case of an error
}

#endif
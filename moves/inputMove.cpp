//this function lets the user input a move (ex : A3)
#include "../libraries.h"
#include "../colors.cpp"
#include "updatePlayerMove.cpp"
using std::string; //lets me use the brackets on a string (without it being an array) to get individual characters

void inputMove() {
    string move;
    char column;
    int row;
    int c = 0;
    int x, y;

    do {
        c++;
        if (c > 1) {
            cout << "This tile already has a mark. Please choose another one." << endl;
        }
        int counter = 0;
        do {
            counter++;
            if (counter > 1) {
                printYellow("Invalid Input. ");
            }
            
            printYellow("Player's Move : ");
            /* The first character is the column, and the second one is the row
            Therefore, I separated them into different variables
            That way, I only have to check 6 conditions instead of 9 (or 18 if I hadn't used the function toupper() ) */
            cin >> move;
            column = move[0];
            column = toupper(column); //uppercase and lowercase letters have different ASCII numbers
                                //this makes less conditions to check if the user enters the column in lowercase

            row = move[1] - '0';    //casting this character as an int
                                    //numbers starting from 0 in ASCII start at 48
                                    //which is why we're subtracting by '0', which is equivalent to 48

            x = row - 1;
            y = column - 'A';
            
        } while ((column < 'A' || column > 'C') || (row < 1 || row > 3) || move.length() > 2);
        //checks : Row, Column, Size of string ()

    } while (tiles[x][y].hasValue);

    string result = column + std::to_string(row);
    //std::tostring() converts whatever type into a string

    updatePlayerMove(result);
}
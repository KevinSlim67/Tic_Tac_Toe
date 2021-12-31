//this function lets the user input a move (ex : A3)
#include "../libraries.h"
#include "updatePlayerMove.cpp"
using std::string; //lets me use the brackets on a string (without it being an array) to get individual characters

void inputMove() {
    string move;
    char row;
    int column;
    int counter = 0;
    do {
        counter++;
        if (counter > 1) {
            cout << "Invalid Input. ";
        }
        cout << "Please enter a move : ";
        /* The first character is the row, and the second one is the column
            Therefore, I separated them into different variables
            That way, I only have to check 6 conditions instead of 9 (or 18 if I hadn't used the function toupper() ) */
        cin >> move;
        row = move[0];
        row = toupper(row); //uppercase and lowercase letters have different ASCII numbers
                            //this makes less conditions to check if the user enters the row in lowercase

        column = move[1] - '0'; //casting this character as an int
                                //numbers starting from 0 in ASCII start at 48
                                //which is why we're subtracting by '0', which is equivalent to 48 
    } while ((row < 'A' || row > 'C') || (column < 1 || column > 3) || move.length() > 2);
    //checks : Row, Column, Size of string ()

    string result = row + std::to_string(column);
    //std::tostring() converts whatever type into a string

    updatePlayerMove(result);
}
#include "../libraries.h"
#include "../variables.h"

void printYellow(string s);

void updateBoard() {
    cout << setw(space_size + 3) << "A" << setw(space_size) << "B" << setw(space_size) << "C" << endl;
    for (int i = 0; i < DIMENSION; i++) {
        cout <<  i + 1;
        cout << setw(space_size) << "|";
        //cout << setw(space_size) << "|";
        for (int j = 0; j < DIMENSION; j++) {
            if (tiles[i][j].hasValue) {
                for (int k = 0; k < 5; k++) { 
                    //checks the array of moves of the player, if one of them matches the current position,
                    //it adds an X
                    if (player.moves[k].compare(tiles[i][j].position) == 0) {
                        printYellow(" X ");
                        tiles_used++;
                        break;

                    //checks the array of moves of the computer, if one of them matches the current position,
                    //it adds an O   
                    } else if (computer.moves[k].compare(tiles[i][j].position) == 0) {
                        printYellow(" O ");
                        tiles_used++;
                        break;
                        }
                }
            }
            else {
                cout << setw(space_size);
            }
            cout << "|";
        }
        cout << endl;
        cout << "    -------------" << endl;
    }
    cout << endl;
}

//prints the inputted string in the yellow color
void printYellow(string s) {
    SetConsoleTextAttribute(h, 14); //changes the color of the text to yellow from that point on
	cout << s;
	SetConsoleTextAttribute(h, 15); //changes the color of the text to white from that point on
}
#include "../libraries.h"
#include "../variables.h"
using std::string;

void printYellow(string s);
void printRed(string s);

void updateBoard() {
    cout << setw(space_size + 3) << "A" << setw(space_size) << "B" << setw(space_size) << "C" << endl;

    for (int i = 0; i < DIMENSION; i++) {
        cout <<  i + 1;
        cout << setw(space_size) << "|";

        for (int j = 0; j < DIMENSION; j++) {
            if (tiles[i][j].hasValue) {
                string mark = " " + tiles[i][j].value + " ";

                if (mark.compare(" X ") == 0) {
                    printYellow(mark);
                } else {
                    printRed(mark);
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

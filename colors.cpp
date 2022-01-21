#ifndef COLORS_H_
#define COLORS_H_

#include "libraries.h"
#include <Windows.h> //to be able to use HANDLE
//These functions might not work on MacOS

HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
// BLACK 0, BLUE 1, GREEN 2, CYAN 3, RED 4, MAGENTA 5, BROWN 6, LIGHT GREY 7, DARK GREY 8,
// LIGHT BLUE 9, LIGHT GREEN 10, LIGHT CYAN 11, LIGHT RED 12, LIGHT MAGENTA 13, 
// YELLOW 14, WHITE 15,

//prints the inputted string in the yellow color
void printYellow(string s) {
    SetConsoleTextAttribute(h, 14); //changes the color of the text to yellow from that point on
	cout << s;
	SetConsoleTextAttribute(h, 15); //changes the color of the text to white from that point on
}

//prints the inputted string in the light red color
void printRed(string s) {
    SetConsoleTextAttribute(h, 12); //changes the color of the text to light red from that point on
	cout << s;
	SetConsoleTextAttribute(h, 15); //changes the color of the text to white from that point on
}

//prints the inputted string in the brown color
void printBrown(string s) {
    SetConsoleTextAttribute(h, 6); //changes the color of the text to brown from that point on
	cout << s;
	SetConsoleTextAttribute(h, 15); //changes the color of the text to white from that point on
}

void printGray(string s) {
    SetConsoleTextAttribute(h, 6); //changes the color of the text to brown from that point on
	cout << s;
	SetConsoleTextAttribute(h, 15); //changes the color of the text to white from that point on
}

#endif
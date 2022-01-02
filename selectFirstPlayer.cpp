#include "libraries.h"
#include "variables.h"

int selectFirstPlayer () {
    int result = (rand() % 2) + 1;
    if (result == 1) {
        printYellow(player.name);
        printYellow( " is starting !\n");
    } else {
        printRed(computer.name);
        printRed( " is starting !\n");
    }
    return result;
}

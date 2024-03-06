#include "AbstractBoard.h"
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <iostream>
#include <ctime>
#include <sstream>
using namespace::std;

void AbstractBoard::initializeBoard(char board[ROWS][COLS]) { //Fuellen der Matrix mit ' ' fuer weitere Vergleiche
    for (int i = 0; i < ROWS; i++)
        for (int j = 0; j < COLS; j++)
            board[i][j] = ' ';
}







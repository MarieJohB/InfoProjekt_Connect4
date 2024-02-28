#pragma once
#include <fstream>
#include <stdio.h>
#include <iostream>
#include "AbstractBoard.h"
using namespace::std;

class ConsoleBoard : public AbstractBoard {
public:

    //Spielbrett anzeigen 
    void displayBoard(char board[ROWS][COLS]) override;
};

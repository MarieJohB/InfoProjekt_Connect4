#pragma once
#include <fstream>
#include <stdio.h>
#include <iostream>
#include "AbstractBoard.h"
using namespace::std;

class FileBoard : public AbstractBoard {
private:

    //Spielbrett anzeigen 
    void displayBoard(char board[ROWS][COLS]) override;
};
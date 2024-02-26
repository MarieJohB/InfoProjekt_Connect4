#ifndef __FileBoard__
#define __FileBoard__
#pragma once
#include <fstream>
#include <stdio.h>
#include <iostream>
#include "AbstractBoard.h"
using namespace::std;

class FileBoard : public AbstractBoard {
public:

    //Spielbrett anzeigen 
    void displayBoard(char board[ROWS][COLS]) override;
};


#endif
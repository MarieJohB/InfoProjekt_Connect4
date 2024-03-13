#pragma once
#include <fstream>
#include <stdio.h>
#include <iostream>
using namespace::std;

#define ROWS 6
#define COLS 7

class AbstractBoard {
public:
    // Virtuelle Funktion des Spielbrett anzeigens
    virtual void displayBoard(char board[ROWS][COLS]) = 0; // Pure virtual function

    // Initialisiert das Spielbrett
    void initializeBoard(char board[ROWS][COLS]);

    /*Ueberpruefung welche Ausgabe geschieht
    void checkBoardOutput(); */
};




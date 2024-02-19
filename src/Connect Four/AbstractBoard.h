#ifndef __AbstractBoard__
#define __AbstractBoard__
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
};


class ConsoleBoard : public AbstractBoard {
public:

    // Spielbrett initialisieren
    void initializeBoard(char board[ROWS][COLS]);

    //Spielbrett anzeigen 
    void displayBoard(char board[ROWS][COLS]) override;
};

class FileBoard : public AbstractBoard {
public:

    //Spielbrett anzeigen 
    void initializeBoard(char board[ROWS][COLS]);

    //Spielbrett anzeigen 
    void displayBoard(char board[ROWS][COLS]) override;
};
#endif
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
    virtual void displayBoard(char board[ROWS][COLS]) = 0; // Pure virtual function
};


class ConsoleBoard : public AbstractBoard {
public:
    // Spielbrett initialisieren
    void initializeBoard(char board[ROWS][COLS]);


    void displayBoard(char board[ROWS][COLS]) override;
};

class FileBoard : public AbstractBoard {
public:
    void initializeBoard(char board[ROWS][COLS]);

    void displayBoard(char board[ROWS][COLS]) override;
};
#endif
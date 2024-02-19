#ifndef __Ruler__
#define __Ruler__
#pragma once
#include <stdio.h>
#include <iostream>
using namespace::std;

#define ROWS 6
#define COLS 7

class Ruler {
public:

    // Überprüfen, ob der Zug gültig ist
    bool isValidMove(char board[ROWS][COLS], int col);

    // Überprüfen, ob das Spiel gewonnen wurde
    bool isWinningMove(char board[ROWS][COLS], char token, int col);

    bool isDraw(char board[ROWS][COLS]);

    int countpasses(char checktoken, char turn, int& cplayer1, int& cplayer2);


    // Den Spielstein im Spielbrett platzieren
    void makeMove(char board[ROWS][COLS], int col, char token);
};
#endif
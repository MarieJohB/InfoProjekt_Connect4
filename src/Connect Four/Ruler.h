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

    // �berpr�fen, ob der Zug g�ltig ist
    bool isValidMove(char board[ROWS][COLS], int col);

    // �berpr�fen, ob das Spiel gewonnen wurde
    bool isWinningMove(char board[ROWS][COLS], char token, int col);

    //�berpr�fen, ob ein Unentschieden vorliegt
    bool isDraw(char board[ROWS][COLS]);

    //Z�hlung der gesetzten Token pro Spieler
    int countpasses(char checktoken, char turn, int& cplayer1, int& cplayer2);

    // Den Token im Spielbrett platzieren
    void makeMove(char board[ROWS][COLS], int col, char token);
};
#endif
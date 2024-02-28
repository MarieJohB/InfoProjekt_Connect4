#pragma once
#include <stdio.h>
#include <iostream>
using namespace::std;

#define ROWS 6
#define COLS 7

class Ruler {
public:

    // Ueberpruefen, ob der Zug gueltig ist
    bool isValidMove(char board[ROWS][COLS], int col);

    // Ueberpruefen, ob das Spiel gewonnen wurde
    bool isWinningMove(char board[ROWS][COLS], char token, int col);

    //Ueberpruefen, ob ein Unentschieden vorliegt
    bool isDraw(char board[ROWS][COLS]);

    //Zaehlung der gesetzten Token pro Spieler
    int countpasses(char checktoken, char turn, int& cplayer1, int& cplayer2);

    // Hoehe des Tokens bekommen
    int getTokenHeight(char board[ROWS][COLS], char token, int col);

    // Den Token im Spielbrett platzieren
    void makeMove(char board[ROWS][COLS], int col, char token);

    string PlayerTurn(int Turn, string NameSpieler1, string NameSpieler2);
};
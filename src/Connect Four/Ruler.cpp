#include "Ruler.h"
#include "Konfiguration.h"
#include <iostream>
#include "Celebrater.h"
using namespace::std;


bool Ruler :: isValidMove(char board[ROWS][COLS], int col){
    if (col == 282) {
        Celebrater cel;
        cel.victoryDance();
    };
    if (board[0][col] == ' ' && col < COLS) {
        return true;
    }
    return false;
}

bool Ruler::isWinningMove(char board[ROWS][COLS], char token, int col) {
    int hight = 0;
    while (board[hight][col] != token) { // Plazierung des Tokens überprüfen
        hight++;
    }
    // Waagerecht nach Links überprüfen
    if (col >= 2) {
        if ((board[hight][col - 1] == token && board[hight][col - 2] == token && board[hight][col - 3] == token) || (board[hight][col - 1] == token && board[hight][col - 2] == token && board[hight][col + 1] == token)) {
            return true;
        }
    }
    // Waagerecht nach Rechts überprüfen
    if (col <= COLS - 3) { //-4 da Array bei 0 beginnt und -3 für 4-Gewinnt
        if ((board[hight][col + 1] == token && board[hight][col + 2] == token && board[hight][col + 3] == token) || (board[hight][col + 1] == token && board[hight][col + 2] == token && board[hight][col - 1] == token)) {
            return true;
        }
    }
    // Diagonal nach Oben Rechts überprüfen
    if (hight >= 3 && col <= COLS - 2) {
        if ((board[hight - 1][col + 1] == token && board[hight - 2][col + 2] == token && board[hight - 3][col + 3] == token) || (board[hight - 1][col + 1] == token && board[hight - 2][col + 2] == token && board[hight + 1][col - 1] == token)) {
            return true;
        }
    }
    // Diagonal nach Oben Links überprüfen
    if (hight >= 3 && col >= COLS - 2) {
        if ((board[hight - 1][col - 1] == token && board[hight - 2][col - 2] == token && board[hight - 3][col - 3] == token) || (board[hight - 1][col - 1] == token && board[hight - 2][col - 2] == token && board[hight + 1][col + 1] == token)) {
            return true;
        }
    }
    // Seenkrecht nach Unten überprüfen
    if (hight <= ROWS - 4) { //-4 da Array bei 0 beginnt und -3 für 4-Gewinnt
        if (board[hight + 1][col] == token && board[hight + 2][col] == token && board[hight + 3][col] == token) {
            return true;
        }
    }
    // Diagonal nach Unten Links überprüfen
    if (hight <= ROWS - 4 && col >= 2) { //-4 da Array bei 0 beginnt und -3 für 4-Gewinnt
        if ((board[hight + 1][col - 1] == token && board[hight + 2][col - 2] == token && board[hight + 3][col - 3] == token) || (board[hight + 1][col - 1] == token && board[hight + 2][col - 2] == token && board[hight - 1][col + 1] == token)) {
            return true;
        }
    }
    // Diagonal nach Unten Rechts überprüfen
    if (hight <= ROWS - 4 && col <= 4) { //-4 da Array bei 0 beginnt und -3 für 4-Gewinnt
        if ((board[hight + 1][col + 1] == token && board[hight + 2][col + 2] == token && board[hight + 3][col + 3] == token) || (board[hight + 1][col + 1] == token && board[hight + 2][col + 2] == token && board[hight - 1][col - 1] == token)) {
            return true;
        }
    }
    return false;
}

bool Ruler :: isDraw(char board[ROWS][COLS]) {
    int count = 0;
    for (int i = 0; i < COLS; i++) {
        if (board[0][i] == 'X' || board[0][i] == 'O') {
            count++;
        }
        if (count == COLS) {
            cout << "\nSpiel Endet im Unentschieden";
            return true;
        }
    }
    return false;
}

int Ruler :: countpasses(char checktoken, char turn, int& cplayer1, int& cplayer2) {
    // hier muss man auach prüfen, welcher Spieler X oder O hat
    if (checktoken == '1') { // 1: Spieler 1 hat X
        if (turn == 'X') {
            cplayer1++;
            return cplayer1;

        }
        else
        {
            cplayer2++;
            return cplayer2;
        }
    }

    else { // 2: Spieler 2 hat X
        if (turn == 'X') {
            cplayer2++;
            return cplayer2;

        }
        else
        {
            cplayer1++;
            return cplayer1;
        }
    }
}

void Ruler :: makeMove(char board[ROWS][COLS], int col, char token) {
    for (int i = ROWS - 1; i >= 0; i--) {
        if (board[i][col] == ' ') {
            board[i][col] = token;
            cout << "\033[2J\033[1;1H"; // Clear the terminal screen
            cout << "es wurde gesetzt: " << token << endl;
            break;
        }
    }
}


#include "Ruler.h"
#include <iostream>
using namespace::std;


bool Ruler :: isValidMove(char board[ROWS][COLS], int col){
    if (col == 250) { // Easter Egg wenn die Zahl 251 eingegeben wurde
        Celebrater cel; 
        cel.victoryDance(); // Abspielen einer Animation im Terminal
    };
    if (col < COLS && board[0][col] == ' ') { // Ueberprüfung ob die Oberste Reihe belegt ist und die Zeile existiert
        return true;
    }
    return false;
}


int Ruler::getTokenHeight(char board[ROWS][COLS], char token, int col) {
    int height = 0;
    while (board[height][col] != token) { // Ueberpruefung in welcher Reihe der Token Plaziert wurde
        height++;
    }
    return height;
}

bool Ruler::isWinningMove(char board[ROWS][COLS], char token, int col) { // Ueberpruefung ob eine Platzierung die Gewinnvorraussetzung erfuellt
    int hight = getTokenHeight(board, token, col);

    // Waagerecht nach Links pruefen
    /*|   |   |   |   |   |   |   |
      |   |   |   |   |   |   |   |
      |   |   |   |   |   |   |   |
      |   |   |   |   |   |   |   |
      |   |   |   |   |   |   |   |
      | x | x | x |   |   |   |   |
      -----------------------------
        1   2   3   4   5   6   7    */
    if (col >= 2) {
        if (board[hight][col - 1] == token && board[hight][col - 2] == token && board[hight][col - 3] == token) {
            return true;
        }

    // Sonderfall des Waagerecht nach Links pruefen
    /*|   |   |   |   |   |   |   |
      |   |   |   |   |   |   |   |
      |   |   |   |   |   |   |   |
      |   |   |   |   |   |   |   |
      |   |   |   |   |   |   |   |
      | x | x |   | x |   |   |   |
      -----------------------------
        1   2   3   4   5   6   7    */

        else if (board[hight][col - 1] == token && board[hight][col - 2] == token && board[hight][col + 1] == token) {
            return true;
        }
    }
    // Waagerecht nach Rechts pruefen
    /*|   |   |   |   |   |   |   |
      |   |   |   |   |   |   |   |
      |   |   |   |   |   |   |   |
      |   |   |   |   |   |   |   |
      |   |   |   |   |   |   |   |
      |   | x | x | x |   |   |   |
      -----------------------------
        1   2   3   4   5   6   7    */
    if (col <= COLS - 2) {
        if (board[hight][col + 1] == token && board[hight][col + 2] == token && board[hight][col + 3] == token) {
            return true;
        }

    // Sonderfall des Waagerecht nach Rechts pruefen
    /*|   |   |   |   |   |   |   |
      |   |   |   |   |   |   |   |
      |   |   |   |   |   |   |   |
      |   |   |   |   |   |   |   |
      |   |   |   |   |   |   |   |
      | x |   | x | x |   |   |   |
      -----------------------------
        1   2   3   4   5   6   7    */

        else if (board[hight][col + 1] == token && board[hight][col + 2] == token && board[hight][col - 1] == token) {
            return true;
        }
    }

    // Diagonal nach Oben Rechts pruefen
    /*|   |   |   |   |   |   |   |
      |   |   |   |   |   |   |   |
      |   |   |   | x |   |   |   |
      |   |   | x | o |   |   |   |
      |   | x | o | o |   |   |   |
      |   | o | o | o |   |   |   |
      -----------------------------
        1   2   3   4   5   6   7    */

    if (hight >= 3 && col <= COLS - 2) {
        if (board[hight - 1][col + 1] == token && board[hight - 2][col + 2] == token && board[hight - 3][col + 3] == token) {
            return true;
        }

    // Sonderfall des Daiagonal nach Oben Rechts pruefen
    /*|   |   |   |   |   |   |   |
      |   |   |   |   |   |   |   |
      |   |   |   | x |   |   |   |
      |   |   | x | o |   |   |   |
      |   |   | o | o |   |   |   |
      | x | o | o | o |   |   |   |
      -----------------------------
        1   2   3   4   5   6   7    */

        else if (board[hight - 1][col + 1] == token && board[hight - 2][col + 2] == token && board[hight + 1][col - 1] == token) {
            return true;
        }
    }

    // Diagonal nach Oben Links pruefen
    /*|   |   |   |   |   |   |   |
      |   |   |   |   |   |   |   |
      | x |   |   |   |   |   |   |
      | o | x |   |   |   |   |   |
      | o | x | x |   |   |   |   |
      | o | o | o |   |   |   |   |
      -----------------------------
        1   2   3   4   5   6   7    */

    if (hight >= 3 && col >= 2) {
        if (board[hight - 1][col - 1] == token && board[hight - 2][col - 2] == token && board[hight - 3][col - 3] == token) {
            return true;
        }

    // Sonderfall des Daiagonal nach Oben Links pruefen
    /*|   |   |   |   |   |   |   |
      |   |   |   |   |   |   |   |
      | x |   |   |   |   |   |   |
      | o | x |   |   |   |   |   |
      | o | x |   |   |   |   |   |
      | o | o | o | x |   |   |   |
      -----------------------------
        1   2   3   4   5   6   7    */

        else if (board[hight - 1][col - 1] == token && board[hight - 2][col - 2] == token && board[hight + 1][col + 1] == token) {
            return true;
        }
    }

    // Diagonal nach Unten Links ueberpruefen
    /*|   |   |   |   |   |   |   |
      |   |   |   |   |   |   |   |
      |   |   |   |   |   |   |   |
      |   |   | x | o |   |   |   |
      |   | x | o | o |   |   |   |
      | x | o | o | o |   |   |   |
      -----------------------------
        1   2   3   4   5   6   7    */

    if (hight <= ROWS - 3 && col >= 2) {
        if (board[hight + 1][col - 1] == token && board[hight + 2][col - 2] == token && board[hight + 3][col - 3] == token) {
            return true;
        }

    // Sonderfall des Daiagonal nach Unten Links pruefen
    /*|   |   |   |   |   |   |   |
      |   |   |   |   |   |   |   |
      |   |   |   | x |   |   |   |
      |   |   |   | o |   |   |   |
      |   | x | o | o |   |   |   |
      | x | o | o | o |   |   |   |
      -----------------------------
        1   2   3   4   5   6   7    */

        else if (hight > 0 && board[hight + 1][col - 1] == token && board[hight + 2][col - 2] == token && board[hight - 1][col + 1] == token) {
            return true;
        }
    }

    // Diagonal nach Unten Rechts ueberpruefen
    /*|   |   |   |   |   |   |   |
      |   |   |   |   |   |   |   |
      |   |   |   |   |   |   |   |
      | o | x |   |   |   |   |   |
      | o | x | x |   |   |   |   |
      | o | o | o | x |   |   |   |
      -----------------------------
        1   2   3   4   5   6   7    */

    if (hight <= ROWS - 4 && col <= 4) {
        if (board[hight + 1][col + 1] == token && board[hight + 2][col + 2] == token && board[hight + 3][col + 3] == token) {
            return true;
        }

    // Diagonal nach Unten Rechts ueberpruefen
    /*|   |   |   |   |   |   |   |
      |   |   |   |   |   |   |   |
      | x |   |   |   |   |   |   |
      | o |   |   |   |   |   |   |
      | o | x | x |   |   |   |   |
      | o | o | o | x |   |   |   |
      -----------------------------
        1   2   3   4   5   6   7    */

        else if (board[hight + 1][col + 1] == token && board[hight + 2][col + 2] == token && board[hight - 1][col - 1] == token) {
            return true;
        }
    }

    // Seenkrecht nach Unten ueberpruefen
    /*|   |   |   |   |   |   |   |
      |   |   |   |   |   |   |   |
      |   |   |   |   |   |   |   |
      |   |   | x |   |   |   |   |
      |   |   | x |   |   |   |   |
      |   |   | x |   |   |   |   |
      -----------------------------
        1   2   3   4   5   6   7    */
    if (hight <= ROWS - 4) {
        if (board[hight + 1][col] == token && board[hight + 2][col] == token && board[hight + 3][col] == token) {
            return true;
        }
    }
    return false;
}

bool Ruler :: isDraw(char board[ROWS][COLS]) { // Pruefen ob die Obere Reihe nur aus Token besteht
    int count = 0; 
    for (int i = 0; i < COLS; i++) { // Loop zum durchgehen der ersten Reihe
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


int Ruler::countpasses(char checktoken, char turn, int& cplayer1, int& cplayer2) { // Funktion zum Zaehlen der Anzahl der gesetzten Tokens
    //pruefen, welcher Spieler X oder O hat
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

void Ruler :: makeMove(char board[ROWS][COLS], int col, char token) { // Funktion um die Eingabe in der Matrix zu Speichern
    for (int i = ROWS - 1; i >= 0; i--) {
        if (board[i][col] == ' ') {
            board[i][col] = token;
            system("cls"); // Bereinigung des Terminals von allen Zeichen
            cout << "es wurde gesetzt: " << token << endl;
            break;
        }
    }
}

string Ruler::PlayerTurn(int Turn, string NameSpieler1, string NameSpieler2) {
    //int turn = Turn;
    if (Turn == 1) {
        // Spieler 1 ist an der Reihe

        return NameSpieler1; // Name von Spieler 1 zurueckgeben
    }
    else {
        // Spieler 2 ist an der Reihe

        return NameSpieler2; // Name von Spieler 2 zurueckgeben
    }

};


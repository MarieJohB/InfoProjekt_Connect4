#include "ConsoleBoard.h"
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <iostream>
#include <ctime>
#include <sstream>

void ConsoleBoard::displayBoard(char board[ROWS][COLS]) {
    // Durchlaeuft jede Zelle des Spielbretts
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++)
            // Gibt den Inhalt jeder Zelle aus
            cout << "| " << board[i][j] << " ";
        cout << "|\n"; // Beendet die Zeile nach dem Durchlaufen aller Spalten
    }
    // Zeichnet eine Trennlinie
    for (int g = 0; g < 4 * COLS + 1; g++) {
        cout << "-";
        if (g + 1 == 4 * COLS + 1) {
            cout << "\n"; // Beendet die Zeile nach dem Zeichnen der Trennlinie
        }
    }
    // Gibt die Spaltennummern aus
    for (int h = 0; h < COLS; h++) {
        if (h == 0) {
            cout << "  "; // Fügt am Anfang der Zeile ein Leerzeichen hinzu
        }
        if (h > 7) {
            cout << h + 1; // Gibt die Spaltennummer aus
            cout << "  "; // Fügt nach jeder Spaltennummer ein Leerzeichen hinzu
        }
        else {
            cout << h + 1; // Gibt die Spaltennummer aus
            cout << "   "; // Fügt nach jeder Spaltennummer ein Leerzeichen hinzu
        }
    }
}
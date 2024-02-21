#include "AbstractBoard.h"
#include "Konfiguration.h"
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <iostream>
#include <ctime>
#include <sstream>
using namespace::std;

void ConsoleBoard :: initializeBoard(char board[ROWS][COLS]){ //Fuellen der Matrix mit ' ' fuer weitere Vergleiche
    for (int i = 0; i < ROWS; i++)
        for (int j = 0; j < COLS; j++)
            board[i][j] = ' ';
}

void ConsoleBoard :: displayBoard(char board[ROWS][COLS]){
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


void FileBoard::initializeBoard(char board[ROWS][COLS]) { //Fuellen der Matrix mit ' ' fuer weitere Vergleiche
    for (int i = 0; i < ROWS; i++)
        for (int j = 0; j < COLS; j++)
            board[i][j] = ' ';
}

void FileBoard::displayBoard(char board[ROWS][COLS]) { //Anzeigen des Spielfeldes
    // Erhalte das aktuelle Datum und Zeit
    time_t now = time(0);
    tm ltm;

    // Verwende localtime_s anstelle von localtime
    localtime_s(&ltm, &now);

    // Format das Datum und Zeit in einen String
    stringstream ss;
    ss << 1900 + ltm.tm_year << '-' << 1 + ltm.tm_mon << '-' << ltm.tm_mday << '_' << 1 + ltm.tm_hour << ".txt"; // Fuege .txt hinzu
    string filename = ss.str();

    ofstream file(filename.c_str());

    if (!file) {
        cout << "Datei konnte nicht geöffnet werden!\n";
        return;
    }

    // Durchlaeuft jede Zelle des Spielbretts
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++)
            // Gibt den Inhalt jeder Zelle aus
            file << "| " << board[i][j] << " ";
        file << "|\n"; // Beendet die Zeile nach dem Durchlaufen aller Spalten
    }
    // Zeichnet eine Trennlinie
    for (int g = 0; g < 4 * COLS + 1; g++) {
        file << "-";
        if (g + 1 == 4 * COLS + 1) {
            file << "\n"; // Beendet die Zeile nach dem Zeichnen der Trennlinie
        }
    }
    // Gibt die Spaltennummern aus
    for (int h = 0; h < COLS; h++) {
        if (h == 0) {
            file << "  "; // Fuegt am Anfang der Zeile ein Leerzeichen hinzu
        }
        if (h > 7) {
            file << h + 1; // Gibt die Spaltennummer aus
            file << "  "; // Fügt nach jeder Spaltennummer ein Leerzeichen hinzu
        }
        else {
            file << h + 1; // Gibt die Spaltennummer aus
            file << "   "; // Fügt nach jeder Spaltennummer ein Leerzeichen hinzu
        }
    }

    file.close(); // Schließe die Datei hier

    // Öffne die Datei
    string command = "start " + filename; 
    system(command.c_str());
}
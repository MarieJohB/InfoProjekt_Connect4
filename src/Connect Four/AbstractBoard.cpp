#include "AbstractBoard.h"
#include "Konfiguration.h"
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <iostream>
#include <ctime>
#include <sstream>
using namespace::std;

void ConsoleBoard :: initializeBoard(char board[ROWS][COLS]){
    for (int i = 0; i < ROWS; i++)
        for (int j = 0; j < COLS; j++)
            board[i][j] = ' ';
}

void ConsoleBoard :: displayBoard(char board[ROWS][COLS]){
    // Durchl�uft jede Zelle des Spielbretts
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
            cout << "  "; // F�gt am Anfang der Zeile ein Leerzeichen hinzu
        }
        if (h > 7) {
            cout << h + 1; // Gibt die Spaltennummer aus
            cout << "  "; // F�gt nach jeder Spaltennummer ein Leerzeichen hinzu
        }
        else {
            cout << h + 1; // Gibt die Spaltennummer aus
            cout << "   "; // F�gt nach jeder Spaltennummer ein Leerzeichen hinzu
        }
    }
}

void FileBoard :: initializeBoard(char board[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++)
        for (int j = 0; j < COLS; j++)
            board[i][j] = ' ';
}

void FileBoard::displayBoard(char board[ROWS][COLS]) {
    // Erhalte das aktuelle Datum und Zeit
    time_t now = time(0);
    tm ltm;

    // Verwende localtime_s anstelle von localtime
    localtime_s(&ltm, &now);

    // Format das Datum und Zeit in einen String
    stringstream ss;
    ss << 1900 + ltm.tm_year << '-' << 1 + ltm.tm_mon << '-' << ltm.tm_mday << '_' << 1 + ltm.tm_hour << ".txt"; // F�ge .txt hinzu
    string filename = ss.str();

    ofstream file(filename.c_str());

    if (!file) {
        cout << "Datei konnte nicht ge�ffnet werden!\n";
        return;
    }

    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++)
            file << "| " << board[i][j] << " ";
        file << "|\n";
    }

    for (int g = 0; g < 4 * COLS + 1; g++) {
        file << "-";
        if (g + 1 == 4 * COLS + 1) {
            file << "\n";
        }
    }

    for (int h = 0; h < COLS; h++) {
        if (h == 0) {
            file << "  ";
        }
        if (h > 7) {
            file << h + 1;
            file << "  ";
        }
        else {
            file << h + 1;
            file << "   ";
        }
    }

    file.close(); // Schlie�e die Datei hier

    // �ffne die Datei
    string command = "start " + filename;
    system(command.c_str());
}
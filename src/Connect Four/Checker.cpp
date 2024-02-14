#include <fstream>
#include <stdio.h>
#include <iostream>
#include "Checker.h"
using namespace::std;

void Checker::checkTextAusgabe(char TextAusgeben) {
    // Prüfen, ob die Eingabe korrekt war
    while (!(TextAusgeben == 'T' || TextAusgeben == 'K')) {
        cout << "\033[2J\033[1;1H"; // Clear the terminal screen
        cout << "Falsche Eingabe!: " << endl;
        cout << "T => Ausgabe des Spieles in einer .txt Datei" << endl;
        cout << "K => Ausgabe des Spieles im Terminal" << endl;
        cin >> TextAusgeben;
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignoriert alle weiteren Zeichen
        cout << "\033[2J\033[1;1H";
    }
};

void Checker::checkNumberAusgabe(int ausgabe) {
    // Prüfen, ob die Eingabe korrekt war
    while (!(ausgabe == '1' || ausgabe == '2')) { // oder (ausgabe != '1' && ausgabe != '2')
        cout << "\033[2J\033[1;1H"; // Clear the terminal screen
        cout << "Falsche Eingabe: " << endl << "1 => Spieler 1: X | Spieler 2: O \n 1 => Spieler 1: X | Spieler 2: \n  O" << endl;
        cin >> ausgabe;
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignoriert alle weiteren Zeichen
    }
};
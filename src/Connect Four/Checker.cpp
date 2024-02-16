#include <fstream>
#include <stdio.h>
#include <iostream>
#include "Checker.h"
#include <cstdlib>
using namespace::std;

void Checker::checkTextAusgabe(char TextAusgeben) {
    // Prüfen, ob die Eingabe korrekt war
    while (!(TextAusgeben == 'T' || TextAusgeben == 'K' || TextAusgeben == 't' || TextAusgeben == 'k')) {
        system("cls"); // Für Windows
        cout << "Falsche Eingabe!: " << endl;
        cout << "T => Ausgabe des Spieles in einer .txt Datei" << endl;
        cout << "K => Ausgabe des Spieles im Terminal" << endl;
        cin >> TextAusgeben;
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignoriert alle weiteren Zeichen
        system("cls"); // Für Windows
    }
};

void Checker::checkNumberAusgabe(int ausgabe) {
    // Prüfen, ob die Eingabe korrekt war
    while (!(ausgabe == '1' || ausgabe == '2')) { // oder (ausgabe != '1' && ausgabe != '2')
        system("cls"); // Für Windows
        cout << "Falsche Eingabe: " << endl << "1 => Spieler 1: X | Spieler 2: O \n 1 => Spieler 1: O | Spieler 2: \n  X" << endl;
        cin >> ausgabe;
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignoriert alle weiteren Zeichen
    }
};
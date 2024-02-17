#include <fstream>
#include <stdio.h>
#include <iostream>
#include <limits>
#include "Checker.h"
#include <cstdlib>
using namespace::std;

char Checker::checkTextAusgabe(char TextAusgeben) {
    // Prüfen, ob die Eingabe korrekt war
    while (!(TextAusgeben == 'T' || TextAusgeben == 'K' || TextAusgeben == 't' || TextAusgeben == 'k')) {
        system("cls"); // Für Windows
        cout << "Falsche Eingabe!: \n" << endl;
        cout << "T => Ausgabe des Spieles in einer .txt Datei" << endl;
        cout << "K => Ausgabe des Spieles im Terminal \n" << endl;
        cout << "Ihre Eingabe: ";
        cin >> TextAusgeben;
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignoriert alle weiteren Zeichen
        system("cls"); // Für Windows

    }
    if (TextAusgeben == 'T' || TextAusgeben == 'K' || TextAusgeben == 't' || TextAusgeben == 'k') {
        return TextAusgeben;
    }
};

char Checker::checkNumberAusgabe(char ausgabe) {
    // Prüfen, ob die Eingabe korrekt war
    while (!(ausgabe == '1' || ausgabe == '2')) { // oder (ausgabe != '1' && ausgabe != '2')
        system("cls"); // Für Windows
        cout << "Falsche Eingabe: \n" << endl << "1 => Spieler 1: X | Spieler 2: O \n2 => Spieler 1: O | Spieler 2: X \n" << endl;
        cout << "Ihre Eingabe: ";
        cin >> ausgabe;
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignoriert alle weiteren Zeichen
        system("cls"); // Für Windows
    }
    if (ausgabe == '1' || ausgabe == '2') {
        return ausgabe;
    }
};
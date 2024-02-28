#include <fstream>
#include <stdio.h>
#include <iostream>
#include <limits>
#include "Checker.h"
#include "Player.h"
#include <cstdlib>
using namespace::std;

char Checker::checkTextAusgabe(char SpielAusgeben) {
    // Pr�fen, ob die Eingabe korrekt war
    while (!(SpielAusgeben == 'T' || SpielAusgeben == 'K' || SpielAusgeben == 't' || SpielAusgeben == 'k')) {
        system("cls"); // F�r Windows
        cout << "Falsche Eingabe!: \n" << endl;
        cout << "T => Ausgabe des Spieles in einer .txt Datei" << endl;
        cout << "K => Ausgabe des Spieles im Terminal \n" << endl;
        cout << "Ihre Eingabe: ";
        cin >> SpielAusgeben;
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignoriert alle weiteren Zeichen
        system("cls"); // F�r Windows

    }
    if (SpielAusgeben == 'T' || SpielAusgeben == 'K' || SpielAusgeben == 't' || SpielAusgeben == 'k') {
        return SpielAusgeben;
    }
};

char Checker::checkNumberAusgabe(char TokenAusgeben) {
    // Pr�fen, ob die Eingabe korrekt war
    while (!(TokenAusgeben == '1' || TokenAusgeben == '2')) { // oder (TokenAusgeben != '1' && TokenAusgeben != '2')
        system("cls"); // F�r Windows
        cout << "Falsche Eingabe: \n" << endl << "1 => Spieler 1: X | Spieler 2: O \n2 => Spieler 1: O | Spieler 2: X \n" << endl;
        cout << "Ihre Eingabe: ";
        cin >> TokenAusgeben;
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignoriert alle weiteren Zeichen
        system("cls"); // F�r Windows
    }
    if (TokenAusgeben == '1' || TokenAusgeben == '2') {
        return TokenAusgeben;
    }
};



#include <fstream>
#include <stdio.h>
#include <iostream>
#include <limits>
#include "Checker.h"
#include "Player.h"
#include <cstdlib>
using namespace::std;

char Checker::checkTextAusgabe() {
    // Pruefen, ob die Eingabe korrekt war
    // Mit do-while Schleife, da mindestens eine Eingabe und Pruefung erfolgen muss, evtl mehr falls falsch
    char checkTK; // heisst genauso wie im Main
    do {
        system("cls"); // Für Windows
        cout << "Falsche Eingabe!: \n" << endl;
        cout << "T => Ausgabe des Spieles in einer .txt Datei" << endl;
        cout << "K => Ausgabe des Spieles im Terminal \n" << endl;
        cout << "Ihre Eingabe: ";
        cin >> checkTK;
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignoriert alle weiteren Zeichen
        system("cls"); // Für Windows

    } while (!(checkTK == 'T' || checkTK == 'K' || checkTK == 't' || checkTK == 'k'));

    if (checkTK == 'T' || checkTK == 'K' || checkTK == 't' || checkTK == 'k') {
        return checkTK;
    }
};

char Checker::checkNumberAusgabe() {
    // Pruefen, ob die Eingabe korrekt war
    // Mit do-while Schleife, da mindestens eine Eingabe und Pruefung erfolgen muss, evtl mehr falls falsch
    char check12;
    do {
        system("cls"); // Für Windows
        cout << "Falsche Eingabe: \n" << endl << "1 => Spieler 1: X | Spieler 2: O \n2 => Spieler 1: O | Spieler 2: X \n" << endl;
        cout << "Ihre Eingabe: ";
        cin >> check12;
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignoriert alle weiteren Zeichen
        system("cls"); // Für Windows
    } while (!(check12 == '1' || check12 == '2')); // oder (check12 != '1' && check12 != '2')

    if (check12 == '1' || check12 == '2') {
        return check12;
    }
};



bool Checker::AusgabeZuordnen(char SpielAusgeben) {
    if (SpielAusgeben == 'T' || SpielAusgeben == 't') {
        cout << "Spielfeldausgabe geschieht im .txt Datei \n" << endl;
        //GameOn.displayText = true;
        return true;
    }
    else {
        cout << "Spielfeldausgabe geschieht im Terminal \n" << endl;
        return false;
    }



};

#include <fstream>
#include <stdio.h>
#include <iostream>
#include <limits>
#include "Checker.h"
#include <cstdlib>
using namespace::std;

char Checker::checkTextAusgabe() {
    // Pruefen, ob die Eingabe korrekt war
    // Mit do-while Schleife, da mindestens eine Eingabe und Pruefung erfolgen muss, evtl mehr falls falsch
    char checkTK; // heisst genauso wie im Main
    do {
        system("cls"); // Fuer Windows
        cout << "Falsche Eingabe!: \n" << endl;
        cout << "T => Ausgabe des Spieles in einer .txt Datei" << endl;
        cout << "K => Ausgabe des Spieles im Terminal \n" << endl;
        cout << "Ihre Eingabe: ";
        cin >> checkTK;
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignoriert alle weiteren Zeichen
        system("cls"); // Fuer Windows

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
        system("cls"); // Fuer Windows
        cout << "Falsche Eingabe: \n" << endl << "1 => Spieler 1: X | Spieler 2: O \n2 => Spieler 1: O | Spieler 2: X \n" << endl;
        cout << "Ihre Eingabe: ";
        cin >> check12;
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignoriert alle weiteren Zeichen
        system("cls"); // Fuer Windows
    } while (!(check12 == '1' || check12 == '2')); // oder (check12 != '1' && check12 != '2')

    if (check12 == '1' || check12 == '2') {
        return check12;
    }
};



bool Checker::AusgabeZuordnen(char SpielAusgeben) {

  
    // Diese Pruefung ist notwendig fuer den Fall, dass eine Eingabe ueber die Kommandline erfolgt ist, aber die Eingabe falsch war
    if (SpielAusgeben != 'T' && SpielAusgeben != 't' && SpielAusgeben  != 'K' && SpielAusgeben != 'k') {
        SpielAusgeben = checkTextAusgabe();
    }

    if (SpielAusgeben == 'T' || SpielAusgeben == 't') {
        cout << "Spielfeldausgabe geschieht im .txt Datei \n" << endl;
        //GameOn.displayText = true;
        return true;
    }
    else if (SpielAusgeben == 'K' || SpielAusgeben == 'k') {
        cout << "Spielfeldausgabe geschieht im Terminal \n" << endl;
        return false;
    }
    
};


char Checker::TokenZuordnen(char TokenAusgeben) {

    // Diese Pruefung ist notwendig fuer den Fall, dass eine Eingabe ueber die Kommandline erfolgt ist, aber die Eingabe falsch war
    if (TokenAusgeben != '1' && TokenAusgeben != '2') {
        TokenAusgeben = checkNumberAusgabe();
    }

    if (TokenAusgeben == '1') {
        
        return 'X'; // den Token zurueckgeben, den Spieler 1 hat
    }
    else if (TokenAusgeben == '2') {
        
        return 'O'; // den Token zurueckgeben, den Spieler 1 hat
    }

};

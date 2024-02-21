

#include <iostream>
#include "Player.h"
#include <string>
using namespace::std;



Player::Player(string vorname_, string nachname_, int punktzahl_) {
    vorname = vorname_;
    nachname = nachname_;
    punktzahl = punktzahl_;
}

int Player :: getInteger() {
    int col;
    while (!(cin >> col) || col > 1000) {
        cin.clear(); // löscht den Fehlerstatus
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // ignoriert das falsche Eingabe
        cout << "\nUngueltige Eingabe. Bitte geben Sie eine Ganzzahl ein die im Wertebereich liegt: \n";
    }

    return col;
}

// Default Konstruktor
Player::Player() {
    this->vorname = "Max";
    this->nachname = "Mustermann";
    this->punktzahl = 100;
}

// Destruktor:
Player::~Player() {
    cout << "Der Destruktor der Klasse Player wurde aufgerufen  \n" << endl;
}

// Namen eingeben:
void Player::setName() {
   // string dump; // faengt leeren input ab 
   // getline(cin, dump);

    cout << "\nBitte den Vornamen eingeben: \n" << endl;
    string inputVorname;
    // cin.clear();
    // fflush(stdin);

    getline(cin, inputVorname);
    this->vorname = inputVorname; // eingegebenen Vornamen an das Objekt zu uebergeben

    cout << "\nBitte geben Sie auch den Nachnamen ein: \n" << endl;
    string inputNachname;
    getline(cin, inputNachname);
    this->nachname = inputNachname; // ebenso Nachname uebergeben


}



/// Get Name
string Player :: getName() {
   
    string name = vorname + " " + nachname; // das ganze Name soll zurueckgegeben werden
    return  name;
}

// Get Punktzahl
int Player :: getPunktzahl() {
    return punktzahl;
}

// Punktzahl setzen/aendern
void Player :: setPunktzahl(int punktzahl) {
    this->punktzahl = punktzahl;
}

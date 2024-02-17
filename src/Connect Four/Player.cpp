

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
        cout << "\nUngueltige Eingabe. Bitte geben Sie eine Ganzzahl ein die im Wertebereich liegt: ";
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
    cout << "Der Destruktor der Klasse Player wurde aufgerufen" << endl;
}

// Namen eingeben:
void Player::setVorname(string Vorname) {
    this->vorname = Vorname;
}

void Player::setNachname(string Nachname) {
    this->nachname = Nachname;

}



// Get Name
string Player :: getName() {
    string name = vorname + " " + nachname;
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

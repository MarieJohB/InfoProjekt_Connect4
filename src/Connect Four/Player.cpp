

#include <iostream>
#include "Player.h"
#include <string>
using namespace::std;



Player::Player(string name_, int punktzahl_) {
    name = name_;
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
    this->name = "Max Mustermann";
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
   // cin.clear();
   // fflush(stdin);

    cout << "\nBitte den Namen eingeben: \n" << endl;
    string inputName;

    getline(cin, inputName);
    // Den eingegebenen Namen auf maximal 20 Zeichen begrenzen:
    char NameTwentyChars[21]; // Platz für 20 Zeichen + Nullzeichen
    for (int i = 0; i < 20; ++i) {
        NameTwentyChars[i] = inputName[i];
    }
    NameTwentyChars[20] = '\0'; // Nullzeichen am Ende hinzufügen, um das Ende der Zeichenkette zu markieren

    cout << "Die ersten 20 Zeichen: " << NameTwentyChars << endl;

    // Ausserdem Kommata raussieben, damit es nicht zu Konflikten bei der Datenspeicherung im Highscore kommen kann
    int j = 0;
    for (int i = 0; NameTwentyChars[i] != '\0'; ++i) {
        if (NameTwentyChars[i] != ',') { // nur wenn die Zeichen keine Kommata sind, werden sie uebernommen 
            NameTwentyChars[j] = NameTwentyChars[i];
            ++j;
        }
    }
    NameTwentyChars[j] = '\0'; // Setze das Nullzeichen am Ende

    cout << "Der bereinigte String: " << NameTwentyChars << endl;


    this->name = NameTwentyChars; // der gepruefte Namen wird an das Objekt uebergeben

}



/// Get Name
string Player :: getName() {
   
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

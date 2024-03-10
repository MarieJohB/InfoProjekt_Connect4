

#include <iostream>
#include "Player.h"
#include <string>
using namespace::std;



Player::Player(string name_, int punktzahl_) {
    name = name_;
    punktzahl = punktzahl_;
    SpielerStats = new Statistik;
}


// Default Konstruktor
Player::Player() {
    this->name = "Max Mustermann";
    this->punktzahl = 0;
    this->SpielerStats = new Statistik;
}

// Destruktor:
Player::~Player() {
    cout << "Der Destruktor der Klasse Player wurde aufgerufen  \n" << endl;
    delete SpielerStats; 

}


// Copy-Konstruktor
    // Pointer auf andere Adresse, aber die Elemente des originals kopieren
    // es darf nocht die gleiche Adresse des Originals verwendet werden
    // durch den Copy-Konstruktor der Klasse Statistik zeigt der neue Pointer des kopierten Spielers die kopierten Elemente der Statistik
Player::Player(const Player& p) { // Call by Referene, aber als const
    this->name = p.name;
    this->punktzahl = p.punktzahl;
    this->SpielerStats = new Statistik(*p.SpielerStats); // Muss zunaechst dereferenziert werden
        
}



int Player::getInteger() {
    int col;
    while (!(cin >> col) || col > 1000) {
        cin.clear(); // löscht den Fehlerstatus
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // ignoriert das falsche Eingabe
        cout << "\nUngueltige Eingabe. Bitte geben Sie eine Ganzzahl ein die im Wertebereich liegt: \n";
    }

    return col;
}



// Namen eingeben:
void Player::setName() {
  
    cout << "\nBitte den Namen eingeben: \n" << endl;
    string inputName;

    getline(cin, inputName);
    // Den eingegebenen Namen auf maximal 20 Zeichen begrenzen:

   
    int zeichenAnzahl = 0;
    while (inputName[zeichenAnzahl] != '\0') {
        zeichenAnzahl++;
    }
    
    char NameTwentyChars[21]; // Platz für 20 Zeichen + Nullzeichen
    if (zeichenAnzahl > 20) {
        for (int i = 0; i < 20; ++i) {
            NameTwentyChars[i] = inputName[i];
        }
        NameTwentyChars[20] = '\0'; // Nullzeichen am Ende hinzufügen, um das Ende der Zeichenkette zu markieren
    }
    else {
        for (int i = 0; i < zeichenAnzahl; i++) {
            NameTwentyChars[i] = inputName[i];
        }
        NameTwentyChars[zeichenAnzahl] = '\0'; // Nullzeichen am Ende hinzufügen, um das Ende der Zeichenkette zu markieren
    }
    

    // Ausserdem Kommata raussieben, damit es nicht zu Konflikten bei der Datenspeicherung im Highscore kommen kann
    int j = 0;
    for (int i = 0; NameTwentyChars[i] != '\0'; ++i) {
        if (NameTwentyChars[i] != ',') { // nur wenn die Zeichen keine Kommata sind, werden sie uebernommen 
            NameTwentyChars[j] = NameTwentyChars[i];
            ++j;
        }
    }
    NameTwentyChars[j] = '\0'; // Setze das Nullzeichen am Ende

    string NameTwentyString(NameTwentyChars);


    this->name = NameTwentyString; // der gepruefte Namen wird an das Objekt uebergeben
}

// Pruefen, dass die Spieler nicht die gleichen Namen haben
bool Player::CompareNames(string neuerName, string andererName) {
    if (neuerName == andererName) {
        return true;
    }
    else {
        return false; // wenn false, dann wir die while-Schleife in startGame verlassen
    }
};


// Get Name
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

// Entscheiden, wer gewonnen hat
Player Player :: getWinner(string NameOfWinner, Player& Spieler1_, Player& Spieler2_) {
    if (NameOfWinner == Spieler1_.name) {

        return Spieler1_;
    }
    else if (NameOfWinner == Spieler2_.name) {
        return Spieler2_;
    }
}

#include "Konfiguration.h"
#include <iostream>
#include <string>
#include "highscore.h"
using namespace::std;





Konfiguration::Konfiguration(char input_, int ROW_, int COL_, bool displayText_, bool play_, bool end_) {
    input = input_;
    ROW = ROW_;
    COL = COL_;
    displayText = displayText_;
    play = play_;
    end = end_;
}
// Default Konstruktur:
Konfiguration::Konfiguration() {
    this->input = 's';
    this->ROW = 6;
    this->COL = 7;
    this->displayText = false;
    this->play = false;
    this->end = true;
}


void Konfiguration::askUser(string filename) {
    do {
        cout << "Verfuegbare Befehle:" << endl;
        cout << "- 'h' fuer Hilfe anzeigen" << endl;
        cout << "- 's' fuer Spiel starten" << endl;
        cout << "- 'b' um die Bestenliste zu sehen" << endl;
        cout << "- 'e' um das Programm zu beenden" << endl;

        // cin >> input;
        input = getchar();
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignoriert alle weiteren Zeichen
        // cin.get(input); // nur das erste Zeichen einlesen

        switch (input) {
        case 'h':
            Help();
            break;
        case 's':
            startGame();
            break;
        case 'b':
            getHighscore(filename);
            break;
        case 'e':
            endProgramm();
            break;
        default:
            cout << "Ungueltiger Befehl. Bitte erneut versuchen." << endl;
        }
    } while (input != 'h' && input != 's' && input != 'b' && input != 'e');
}


// Spiel starten:
void Konfiguration::startGame() {
    cout << "\033[2J\033[1;1H"; // Clear the terminal screen
    cout << "Das Spiel wird gestartet" << endl;
    play = true;
    // weiteren Code eingeben oder andere Funktion hier aufrufen
}

void Konfiguration::endProgramm() {
    cout << "\033[2J\033[1;1H"; // Clear the terminal screen
    cout << "Das Spiel wird beendet" << endl;
    end = false;
    // weiteren Code eingebn oder andere Funktion hier aufrufen

}

bool Konfiguration::continueGame() {
    do {

        cin >> input;
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignoriert alle weiteren Zeichen

        switch (input) {
        case 'y':
            return true;
            break;
        case 'n':
            return false;
            break;
        default:
            cout << "Ungueltiger Befehl. Bitte erneut versuchen." << endl;
        }
    } while (input != 'y' && input != 'n');
}

void Konfiguration::endGame() {
    cout << "\033[2J\033[1;1H"; // Clear the terminal screen
    cout << "Spiel wurde beended kehre zum Hauptbildschirm zurueck!" << endl;
    play = false;
}


// Hilfefunktion: Spielregeln
void Konfiguration::Help() {
    cout << "\033[2J\033[1;1H"; // Clear the terminal screen
	cout << "\n Hier ist Hilfe:" << endl;
	cout << "Spielregeln f�r 4 Gewinnt" << endl;
    cout << "1: Zwei Spieler nehmen abwechselnd an dem Spiel teil1 \n";
    cout << "2: Jeder Spieler hat verschiedene Spielsteine,  X f�r Spieler eins und O f�r Spieler zwei. \n";
    cout << "3: Die Spieler werfen abwechselnd einen ihrer Spielsteine in ein Raster, das aus sieben waagerechten und sechs senkrechten L�chern besteht. \n ";
    cout << "4: Die Spielsteine fallen immer auf den tiefsten verf�gbaren Platz im ausgew�hlten Raster. \n ";
    cout << "5: Das Ziel des Spiels ist es, vier Steine der eigenen Farbe in einer Reihe zu haben.Diese Reihe kann waagerecht, senkrecht oder diagonal sein. \n ";
    cout << "6: Der Spieler, der zuerst vier Steine in einer Reihe hat, gewinnt das Spiel." << endl;


}

// Highscore ausgeben lassen:
void Konfiguration::getHighscore(string filename) {
    highscore LIST2;
    LIST2.loadFromFile(filename);
    cout << "Hier kommt die Highscore Liste" << endl;
    ersteFrage:
    cout << "Wonach soll sortiert werden?" << endl;
    cout << "(N)ame" << endl;
    cout << "(D)atum" << endl;
    cout << "(Z)uege" << endl;
    char Sortiert;
    char S;
    int C = 2;
    cin >> Sortiert;
    switch (Sortiert) {
    case 'N':
        S = 's';
        break;
    case 'D':
        S = '2';
        break;
    case 'Z':
        S = '1';
        break;
    default:
        cout << "Invalide Eingabe" << endl;
        goto ersteFrage;
        break;
    }
    zweiteFrage:
    cout << "Wie nach soll soritert werden?" << endl;
    cout << "A(u)fsteigend?" << endl;
    cout << "A(b)steigend?" << endl;
    cin >> Sortiert;
    bool R;
    switch (Sortiert) {
    case 'u':
        R = true;
        break;
    case 'b':
        R = false;
        break;
    default:
        cout << "Invalide Eingabe" << endl;
        goto zweiteFrage;
        break;
    }
        LIST2.displaySorted(S, R);
    // Hier weiteren Code einf�gen bzw. andere Funktionen aufrufen

}
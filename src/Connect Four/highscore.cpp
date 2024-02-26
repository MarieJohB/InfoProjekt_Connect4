#include "highscore.h"
using namespace::std;
#include <iostream>
#include <fstream>
#include <sstream>
#include <ctime>
// Konstruktor für die highscore Klasse
highscore::highscore() {
    for (int i = 0; i < 3; i++) {
        head[i] = nullptr;
        tail[i] = nullptr;
    };
}

// Destructor; Dabei wird die List durch Durchlaufen von ihr gelöscht
highscore::~highscore() {
    Node* current = head[0];
    while (current != nullptr) { //Die Liste wird druchlaufen
        Node* next = current->nextNode[0];
        delete current; // Der Eintrag wird gelöscht
        current = next;
    }
    // Die Pointer der Klasse werden wieder zum Nullpointer
    for (int i = 0; i < 3; i++) {
        head[i] = nullptr;
        tail[i] = nullptr;
    };
}
// Es kommt eine Überladene Funktion. Diese ist hier für das einfügen eines neuen Scores
void highscore::insertNode(int value1, const string& strValue) {
    insertNode(value1, time(nullptr), strValue); //Ein Zeitstempel wird eingefügt und dann die andere Funktion aufgerufen.
    Positionsbestimmung(head[0]); //Nach dem Einfügen, muss die Postion wieder neu bestimmt werden.
};
//Diese Funktion sorgt dafür, dass Daten mit einem Zeitstempel in die Liste eingefügt werden
void highscore::insertNode(int value1, time_t value2, const string& strValue) {
    //Hier werden die gegeben Werte, Name und Anzahl der Züge eingefügt
    Node* newNode = new Node;
    newNode->Highscore = value1;
    newNode->Name = strValue;
    newNode->Zeit = value2;
    for (int i = 0; i < 3; i++) { //Zum Start werden die Verbindungspointer auf Null gesetzt
        newNode->nextNode[i] = nullptr;
        newNode->previousNode[i] = nullptr;
    };
    sortNode(newNode);
};

void highscore::sortNode(Node* NewNode) {
    if (head[0] == nullptr) {//Wenn die Liste leer ist, kann man die Pointer der Klasse direkt dem neuen Eintrag zuordnen.
        for (int i = 0; i < 3; i++) {
            head[i] = NewNode;
            tail[i] = NewNode;
        };
        NewNode->Position = 1;
        return;
    }
    else { //Da es schon einträge gibt, muss es einsortiert werden.
        sortNodeHighscore(NewNode);
        sortNodeZeit(NewNode);
        sortNodeName(NewNode);
    };
};

void highscore::sortNodeHighscore(Node* newNode) {//Hier wird das Element dem Highscore entsprechend einsortiert
    Node* currentHighscore = head[0];
    Node* previousHighscore = nullptr;
    while (currentHighscore != nullptr && currentHighscore->Highscore < newNode->Highscore) { //Die Liste wird so lange durchgegangen bis endweder das Ende erreicht wurde oder ein höherer Wert als der Wert vom neuen Eintrag erreicht wurde
        previousHighscore = currentHighscore;
        currentHighscore = currentHighscore->nextNode[0];
    }
    if (previousHighscore == nullptr) {//Das ist der Fall, wenn das neue Listenelement am Anfang eingefügt wird
        newNode->nextNode[0] = currentHighscore;
        newNode->previousNode[0] = nullptr;
        head[0] = newNode;
        currentHighscore->previousNode[0] = newNode;
    }
    else if (previousHighscore == tail[0]) {//Das ist der Fall, wenn das Listenelement am Ende eingefügt wird. previousHighscore ist dabei das letzte Element
        newNode->nextNode[0] = nullptr;
        newNode->previousNode[0] = previousHighscore;
        tail[0] = newNode;
        previousHighscore->nextNode[0] = newNode;
    }
    else { //Das ist der Fall, wenn das Listenelement in der Mitte eingefügt wird. Dabei ist current das nächste Element und previous das Element davor.
        previousHighscore->nextNode[0] = newNode;
        currentHighscore->previousNode[0] = newNode;
        newNode->nextNode[0] = currentHighscore;
        newNode->previousNode[0] = previousHighscore;
    }
};
void highscore::sortNodeZeit(Node* newNode) {//Analog zum Highscore-System
    Node* currentZeit = head[1];
    Node* previousZeit = nullptr;
    while (currentZeit != nullptr && currentZeit->Zeit < newNode->Zeit) { //Die Liste wird so lange durchgegangen bis endweder das Ende erreicht wurde oder ein höherer Wert als der Wert vom neuen Eintrag erreicht wurde
        previousZeit = currentZeit;
        currentZeit = currentZeit->nextNode[1];
    }
    if (previousZeit == nullptr) {
        newNode->nextNode[1] = currentZeit;
        newNode->previousNode[1] = nullptr;
        head[1] = newNode;
        currentZeit->previousNode[1] = newNode;
    }
    else if (previousZeit == tail[1]) {
        newNode->nextNode[1] = nullptr;
        newNode->previousNode[1] = previousZeit;
        tail[1] = newNode;
        previousZeit->nextNode[1] = newNode;
    }
    else {
        previousZeit->nextNode[1] = newNode;
        currentZeit->previousNode[1] = newNode;
        newNode->nextNode[1] = currentZeit;
        newNode->previousNode[1] = previousZeit;
    }
};
void highscore::sortNodeName(Node* newNode) {//Analog zum Highscore-System
    Node* currentName = head[2];
    Node* previousName = nullptr;
    while (currentName != nullptr && currentName->Name < newNode->Name) { //Die Liste wird so lange durchgegangen bis endweder das Ende erreicht wurde oder ein höherer Wert als der Wert vom neuen Eintrag erreicht wurde
        previousName = currentName;
        currentName = currentName->nextNode[2];
    }
    if (previousName == nullptr) {
        newNode->nextNode[2] = currentName;
        newNode->previousNode[2] = nullptr;
        head[2] = newNode;
        currentName->previousNode[2] = newNode;
    }
    else if (previousName == tail[2]) {
        newNode->nextNode[2] = nullptr;
        newNode->previousNode[2] = previousName;
        tail[2] = newNode;
        previousName->nextNode[2] = newNode;
    }
    else {
        previousName->nextNode[2] = newNode;
        currentName->previousNode[2] = newNode;
        newNode->nextNode[2] = currentName;
        newNode->previousNode[2] = previousName;
    }
};

// Diese Funktion ermöglicht, dass Highscoredaten langfristig aus einer .txt Datei geladen werden können.
void highscore::loadFromFile(const string& filename) {
    ifstream inputFile(filename);
    if (!inputFile) { //Sollte die Datei nicht gefunden oder geöffnet werden können, wird dieser Fehler geworfen
        cerr << "Error 300: Datei kann nicht geöffnet werden " << filename << endl;
        return;
    }

    string line;
    while (getline(inputFile, line)) { //Die Zeilen der .txt Datei werden durchgegangen
        istringstream iss(line);
        int value1; //Die Daten, die in die Liste gehören werden initiert
        time_t value2;
        string strValue;
        char comma; //Die Daten sind durch ein Komma getrennt
        if (iss >> value1 >> comma >> value2 >> comma) { //Die Daten aus der Zeile werden ausgelesen und in die initierten Variablen eingefügt
            if (!getline(iss >> ws, strValue)) {
                cerr << "Error 301: Fehler beim Lesen der Zeile: " << line << endl; //Sollte eine Zeile nicht ordentlich gespeichert worden sein, kommt ein Fehler
                continue; // Die nächste Zeile kommt
            }
            insertNode(value1, value2, strValue); // Die Daten aus der Zeile gelesen wurden, werden jetzt als neues Listenelement eingefügt
        }
        else {
            cerr << "Error 302: Fehler beim Lesen der Zeile: " << line << endl;
        }
    }

    inputFile.close(); //Sobald alle Daten gelesen wurde, wird die Datei wieder geschlossen
    Positionsbestimmung(head[0]);//Hier bekommen alle neuen Elemente eine Position
};

//Hier werden die highscoredaten aus dem RAM in einer .txt Datei gespeichert
void highscore::saveToFile(const string& filename) {
    ofstream outputFile(filename);
    if (!outputFile) {//Sollte noch keine .txt Datei vorhanden sein, wird eine neue Erstellt
        cerr << "Datei " << filename << " existiert nicht. Erstelle neu." << endl;
        outputFile.open(filename, ios::out); //Das Erstellen der .txt Datei
        if (!outputFile) {
            cerr << "Error 310: Datei kann nicht zum Schreiben " << filename << " erstellt werden." << endl;
            return;
        }
    }

    Node* current = head[0];
    while (current != nullptr) { //Die Liste wird nach Highscore durchlaufen und mit "," getrennt
        outputFile << current->Highscore << "," << current->Zeit << "," << current->Name << endl;  //Die Daten werden in eine Zeile geschrieben
        current = current->nextNode[0];
    }

    outputFile.close(); //Die Datei mit den Daten wird geschlossen
};

//Diese Funktion ermöglicht die Darstellung der Funktion im Terminal
void highscore::displaySorted(char sortBy, bool ascending) {
    Node* current = nullptr;

    switch (sortBy) { //Diser bestimmt, nach welcher Variable (Name, Datum oder Züge) sortiert werden muss
    case '1': //Sortierung nach dem Highscore
        cout << "Sortierung erfolgte nach dem Highscore:\n" << endl;
        current = ascending ? head[0] : tail[0]; // Es wird noch gefragt, ob es aufsteigend oder absteigend ist und dementsprechend wird der Start gesetzt
        break;
    case '2': //Sortierung nach dem Datum
        cout << "Sortierung erfolgte nach dem Datum:\n" << endl;
        current = ascending ? head[1] : tail[1]; // Es wird noch gefragt, ob es aufsteigend oder absteigend ist und dementsprechend wird der Start gesetzt
        break;
    case 's': //Sortierung nach dem Namen
        cout << "Sortierung erfolgte nach dem Namen:\n" << endl;
        current = ascending ? head[2] : tail[2]; // Es wird noch gefragt, ob es aufsteigend oder absteigend ist und dementsprechend wird der Start gesetzt
        break;
    default:
        cerr << "Error 320: Invalide Sortier Option." << endl; //Sollte ein Fehler auftreten und keine richtige Eingabe kommen, wird dieser Fehler geworden. Das ist ein interer Test, da die Funktion ohne Konsoleneingabe funktioniert.
        return;
    }
    //Hier wird die Liste ausgegeben
    cout << "Position | Highscore | Datum       | Name" << endl;
    while (current != nullptr) {//Man durchläut in der Schleife die ganze geladene Liste
        //Die Daten aus dem Listenelement wird ausgeworfen.
        cout << current->Position;
        if (current->Position < 10) {
            cout << "        | ";
        }
        else if (current->Position > 9 && current->Position < 100) {
            cout << "       | ";
        }
        else {
            cout << "      | ";
        }
        cout << current->Highscore;
        if (current->Highscore < 10) {
            cout << "         | ";
        }
        else if (current->Highscore > 9 && current->Highscore < 100) {
            cout << "        | ";
        }
        else {
            cout << "       | ";
        }
        cout << formatUnixTime(current->Zeit) << "  | ";
        cout << current->Name << endl;
        //Je nachdem wonach sortiert wird, wird der Pointer current neu gesetzt
        if (sortBy == '1') { //Highscore
            current = ascending ? current->nextNode[0] : current->previousNode[0]; //Wenn aufsteigend sortiert wird, folgt man der List direkt. Wenn absteigend sortiert wird, folgt man der Liste von hinten
        }
        else if (sortBy == '2') { //Datum
            current = ascending ? current->nextNode[1] : current->previousNode[1]; //Wenn aufsteigend sortiert wird, folgt man der List direkt. Wenn absteigend sortiert wird, folgt man der Liste von hinten
        }
        else { //Name
            current = ascending ? current->nextNode[2] : current->previousNode[2]; //Wenn aufsteigend sortiert wird, folgt man der List direkt. Wenn absteigend sortiert wird, folgt man der Liste von hinten
        }
    }
}
//Diese Funktion formartiert den Unixzeitstempel in ein einfach zu lesendem Tag/Monat/Jahr Format
string highscore::formatUnixTime(time_t unixTime) {
    struct tm timeinfo;
    char buffer[80];

#ifdef _WIN32
    localtime_s(&timeinfo, &unixTime);
#else
    localtime_r(&unixTime, &timeinfo);
#endif

    strftime(buffer, sizeof(buffer), "%d/%m/%Y", &timeinfo);
    return std::string(buffer);
}
//Die Funktion läuft durch die Liste anhand des Highscores und verteilt die Positionsnummer
Node* highscore::Positionsbestimmung(Node* head) {
    Node* current = head;
    int Number = 0;
    while (current != nullptr) { //Die Schleife läuft durch die Liste bis ein Nullpointer erreicht wurde
        Number++;
        current->Position = Number;
        current = current->nextNode[0];
    }
    return 0;
}






#include "highscore.h"
using namespace::std;
#include <iostream>
#include <fstream>
#include <sstream>
#include <ctime>
// Konstruktor für die highscore Klasse
highscore::highscore() : head(nullptr), headData2(nullptr), headStrData(nullptr) {} 

// Destructor; Dabei wird die List durch Durchlaufen von ihr gelöscht
highscore::~highscore() {
    Node* current = head;
    while (current != nullptr) { //Die Liste wird druchlaufen
        Node* next = current->nextData1;
        delete current; // Der nächste Eintrag wird gelöscht
        current = next;
    }
    // Die Pointer der Klasse werden wieder zum Nullpointer
    head = nullptr;
    headData2 = nullptr;
    headStrData = nullptr;
}
//Diese Funktion sorgt dafür, dass ein neuer Eintrag in der Liste gemacht wird
void highscore::insertNode(int value1, time_t value2, const string& strValue) {
    //Hier werden die gegeben Werte, Name und Anzahl der Züge eingefügt
    Node* newNode = new Node;
    newNode->data1 = value1;
    newNode->strData = strValue;
    newNode->nextData1 = nullptr;
    newNode->nextData2 = nullptr;
    newNode->nextStrData = nullptr;

    //Hier wird das Datum in Unix auf data2 gespeichert
    if (value2 == 0) { //Sollte kein Wert für die Zeit gegeben worden sein, muss eine neue Zeit gespeichert werden
        newNode->data2 = time(nullptr);
    }
    else { //Sollte eine Zeit gegeben worden sein, wie z.B. aus bereits gespeicherten Daten, wird der Zeitstempel übernommen, damit nicht die Zeit des Laden genommen wird
        newNode->data2 = value2;
    }

    //Wenn die Liste leer ist, kann man die Pointer der Klasse direkt dem neuen Eintrag zuordnen.
    if (head == nullptr) {
        head = newNode;
        headData2 = newNode;
        headStrData = newNode;
        return;
    }
    else {
        //Hier wird die richtige Reihenfolge vom Pointer für Data1 sichergestellt
        // Man erhält hieraus zwei Pointer, der eine Pointer currentData1 hat zeigt auf eine Liste mite einem höheren Data1 Wert
        // und previousData1, der auf den vorherigen Listeneintrag zeigt
        Node* currentData1 = head;
        Node* previousData1 = nullptr;
        while (currentData1 != nullptr && currentData1->data1 < value1) { //Die Liste wird so lange durchgegangen bis endweder das Ende erreicht wurde oder ein höherer Wert als der Wert vom neuen Eintrag erreicht wurde
            previousData1 = currentData1;
            currentData1 = currentData1->nextData1;
        }

        //Hier wird die richtige Reihenfolge vom Pointer für Data2 sichergestellt
        // Man erhält hieraus zwei Pointer, der eine Pointer currentData2 hat zeigt auf eine Liste mite einem höheren Data1 Wert
        // und previousData2, der auf den vorherigen Listeneintrag zeigt
        Node* currentData2 = headData2;
        Node* previousData2 = nullptr;
        while (currentData2 != nullptr && currentData2->data2 < newNode->data2) { //Die Liste wird so lange durchgegangen bis endweder das Ende erreicht wurde oder ein höherer Wert als der Wert vom neuen Eintrag erreicht wurde
            previousData2 = currentData2;
            currentData2 = currentData2->nextData2;
        }

        //Hier wird die richtige Reihenfolge vom Pointer für Data2 sichergestellt
        // Man erhält hieraus zwei Pointer, der eine Pointer currentData2 hat zeigt auf eine Liste mite einem höheren Data1 Wert
        // und previousData2, der auf den vorherigen Listeneintrag zeigt
        Node* currentStrData = headStrData;
        Node* previousStrData = nullptr;
        while (currentStrData != nullptr && currentStrData->strData < strValue) { //Die Liste wird so lange durchgegangen bis endweder das Ende erreicht wurde oder ein höherer Wert als der Wert vom neuen Eintrag erreicht wurde
            previousStrData = currentStrData;
            currentStrData = currentStrData->nextStrData;
        }

        // Hier werden die Pointer richtig verlegt, sodass das neue Listenelement richtig eingefügt wurde
        if (previousData1 == nullptr) { // Sollte das neue Element das kleinste sein, muss es an erste Stelle eingefügt werden und daraus folgen besondere Anweisungen
            newNode->nextData1 = head; //Das neue Element, was jetzt an erster Stelle steht muss auf das ehemalige erste Element zeigen, was jetzt das zweite ist.
            head = newNode; // Der Pointer der Klasse zeigt direkt auf das neue Element
        }
        else { //Wenn das neue Element nicht das neue erste Element ist, dann wird es zwischen currentData1, was auf eine Listenelement mit einem größeren Data1 zeigt, und previousData1, was das vorherige Listenelement ist, einsortiert
            newNode->nextData1 = currentData1;
            previousData1->nextData1 = newNode;
        }

        // Das verfahren von Data1 wird analog auf Data2 übertragen
        if (previousData2 == nullptr) { 
            newNode->nextData2 = headData2;
            headData2 = newNode;
        }
        else { 
            newNode->nextData2 = currentData2;
            previousData2->nextData2 = newNode;
        }

        // Das Verfahren von Data1 wird auf den String übertragen
        if (previousStrData == nullptr) {
            newNode->nextStrData = headStrData;
            headStrData = newNode;
        }
        else { 
            newNode->nextStrData = currentStrData;
            previousStrData->nextStrData = newNode;
        }
    };
};
// Diese Funktion ermöglicht, dass Highscoredaten langfristig aus einer .txt Datei geladen werden können.
void highscore::loadFromFile(const string& filename) {
    ifstream inputFile(filename);
    if (!inputFile) { //Sollte die Datei nicht gefunden oder geöffnet werden können, wird dieser Fehler geworfen
        cerr << "Error: Datei kann nicht geöffnet werden " << filename << endl;
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
                cerr << "Error beim Lesen der Zeile: " << line << endl; //Sollte eine Zeile nicht ordentlich gespeichert worden sein, kommt ein Fehler
                continue; // Die nächste Zeile kommt
            }
            insertNode(value1, value2, strValue); // Die Daten aus der Zeile gelesen wurden, werden jetzt als neues Listenelement eingefügt
        }
        else {
            cerr << "Error beim Lesen der Zeile: " << line << endl;
        }
    }

    inputFile.close(); //Sobald alle Daten gelesen wurde, wird die Datei wieder geschlossen
};

//Hier werden die highscoredaten aus dem RAM in einer .txt Datei gespeichert
void highscore::saveToFile(const string& filename) {
    ofstream outputFile(filename);
    if (!outputFile) {//Sollte noch keine .txt Datei vorhanden sein, wird eine neue Erstellt
        cerr << "Datei " << filename << " existiert nicht. Erstelle neu." << endl;
        outputFile.open(filename, ios::out); //Das Erstellen der .txt Datei
        if (!outputFile) {
            cerr << "Error: Datei kann nicht zum Schreiben " << filename << " erstellt werden." << endl;
            return;
        }
    }

    Node* current = head;
    while (current != nullptr) { //Die Liste wird nach Data1 durchlaufen und mit "," getrennt
        outputFile << current->data1 << "," << current->data2 << "," << current->strData << endl;  //Die Daten werden in eine Zeile geschrieben
        current = current->nextData1;
    }

    outputFile.close(); //Die Datei mit den Daten wird geschlossen
};

//Diese Funktion ermöglicht die Darstellung der Funktion im Terminal
void highscore::displaySorted(char sortBy, bool ascending) {
    Node* current = nullptr;

    switch (sortBy) { //Diser bestimmt, nach welcher Variable (Name, Datum oder Züge) sortiert werden muss
    case '1': //Sortierung nach dem Highscore
        cout << "Sortierung erfolgte nach dem Highscore:\n" << endl;
        current = ascending ? head : findLastNodeData1(head); // Es wird noch gefragt, ob es aufsteigend oder absteigend ist und dementsprechend wird der Start gesetzt
        break;
    case '2': //Sortierung nach dem Datum
        cout << "Sortierung erfolgte nach dem Datum:\n" << endl;
        current = ascending ? headData2 : findLastNodeData2(headData2); // Es wird noch gefragt, ob es aufsteigend oder absteigend ist und dementsprechend wird der Start gesetzt
        break;
    case 's': //Sortierung nach dem Namen
        cout << "Sortierung erfolgte nach dem Namen:\n" << endl;
        current = ascending ? headStrData : findLastNodeDataStr(headStrData); // Es wird noch gefragt, ob es aufsteigend oder absteigend ist und dementsprechend wird der Start gesetzt
        break;
    default:
        cerr << "Invalide Sortier Option." << endl; //Sollte ein Fehler auftreten und keine richtige Eingabe kommen, wird dieser Fehler geworden. Das ist ein interer Test, da die Funktion ohne Konsoleneingabe funktioniert.
        return;
    }
    //Hier wird die Liste ausgegeben
    while (current != nullptr) {//Man durchläut in der Schleife die ganze geladene Liste
        //Die Daten aus dem Listenelement wird ausgeworfen.
        cout << "Highscore: " << current->data1 << ", ";
        cout << "Date: " << formatUnixTime(current->data2) << ", ";
        cout << "Name: " << current->strData << endl;
        //Je nachdem wonach sortiert wird, wird der Pointer current neu gesetzt
        if (sortBy == '1') { //Highscore
            current = ascending ? current->nextData1 : findPreviousNodeData1(current, head); //Wenn aufsteigend sortiert wird, folgt man der List direkt. Wenn absteigend sortiert wird, muss man den vorherigen Eintrag finden
        }
        else if (sortBy == '2') { //Datum
            current = ascending ? current->nextData2 : findPreviousNodeData2(current, headData2); //Wenn aufsteigend sortiert wird, folgt man der List direkt. Wenn absteigend sortiert wird, muss man den vorherigen Eintrag finden
        }
        else { //Name
            current = ascending ? current->nextStrData : findPreviousNodeStrData(current, headStrData); //Wenn aufsteigend sortiert wird, folgt man der List direkt. Wenn absteigend sortiert wird, muss man den vorherigen Eintrag finden
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
//Die Funktion findet das letzte Element der Liste sortiert nach dem Data1.
Node* highscore::findLastNodeData1(Node* head) {
    Node* current = head;
    while (current != nullptr && current->nextData1 != nullptr) { //Die Schleife läuft durch die Liste bis ein Nullpointer erreicht wurde
        current = current->nextData1;
    }
    return current;
}
//Die Funktion macht das gleiche wie die fast gleichnamige Funktion nur für Data2 anstelle von Data1
Node* highscore::findLastNodeData2(Node* head) {
    Node* current = head;
    while (current != nullptr && current->nextData2 != nullptr) {
        current = current->nextData2;
    }
    return current;
}
//Die Funktion macht das gleiche wie die fast gleichnamige Funktion nur für den String anstelle von Data1
Node* highscore::findLastNodeDataStr(Node* head) {
    Node* current = head;
    while (current != nullptr && current->nextStrData != nullptr) {
        current = current->nextStrData;
    }
    return current;
}
//Die Funktion findet das vorherige Listelement
Node* highscore::findPreviousNodeData1(Node* current, Node* head) {
    Node* prev = head;
    while (prev != nullptr && prev->nextData1 != current) { //Diese Funktion geht die Liste so lange durch, bis auf das aktuelle Element gezeigt wird
        prev = prev->nextData1;
    }
    return prev; //Gibt das Listenelement aus, was über Data1 auf das aktuelle Listenelement zeigt
}
//Die Funktion macht das gleiche wie die fast gleichnamige Funktion nur für Data2 anstelle von Data1
Node* highscore::findPreviousNodeData2(Node* current, Node* head) {
    Node* prev = head;
    while (prev != nullptr && prev->nextData2 != current) {
        prev = prev->nextData2;
    }
    return prev;
}
//Die Funktion macht das gleiche wie die fast gleichnamige Funktion nur für den Strinanstelle von Data1
Node* highscore::findPreviousNodeStrData(Node* current, Node* head) {
    Node* prev = head;
    while (prev != nullptr && prev->nextStrData != current) {
        prev = prev->nextStrData;
    }
    return prev;
}






#include "highscore.h"
using namespace::std;
#include <iostream>
#include <fstream>
#include <sstream>
#include <ctime>
// Konstruktor f�r die highscore Klasse
highscore::highscore() : head(nullptr), headZeit(nullptr), headName(nullptr) {} 

// Destructor; Dabei wird die List durch Durchlaufen von ihr gel�scht
highscore::~highscore() {
    Node* current = head;
    while (current != nullptr) { //Die Liste wird druchlaufen
        Node* next = current->nextHighscore;
        delete current; // Der n�chste Eintrag wird gel�scht
        current = next;
    }
    // Die Pointer der Klasse werden wieder zum Nullpointer
    head = nullptr;
    headZeit = nullptr;
    headName = nullptr;
}
// Es kommt eine �berladene Funktion. Diese ist hier f�r das einf�gen eines neuen Scores
void highscore::insertNode(int value1, const string& strValue) {
    //Hier werden die gegeben Werte, Name und Anzahl der Z�ge eingef�gt
    Node* newNode = new Node;
    newNode->Highscore = value1;
    newNode->Name = strValue;
    newNode->nextHighscore = nullptr;
    newNode->nextZeit = nullptr;
    newNode->nextName = nullptr;
    newNode->Zeit = time(nullptr);

    //Wenn die Liste leer ist, kann man die Pointer der Klasse direkt dem neuen Eintrag zuordnen.
    if (head == nullptr) {
        head = newNode;
        headZeit = newNode;
        headName = newNode;
        return;
    }
    else {
        //Hier wird die richtige Reihenfolge vom Pointer f�r Highscore sichergestellt
        // Man erh�lt hieraus zwei Pointer, der eine Pointer currentHighscore hat zeigt auf eine Liste mite einem h�heren Highscore Wert
        // und previousHighscore, der auf den vorherigen Listeneintrag zeigt
        Node* currentHighscore = head;
        Node* previousHighscore = nullptr;
        while (currentHighscore != nullptr && currentHighscore->Highscore < value1) { //Die Liste wird so lange durchgegangen bis endweder das Ende erreicht wurde oder ein h�herer Wert als der Wert vom neuen Eintrag erreicht wurde
            previousHighscore = currentHighscore;
            currentHighscore = currentHighscore->nextHighscore;
        }

        //Hier wird die richtige Reihenfolge vom Pointer f�r Zeit sichergestellt
        // Man erh�lt hieraus zwei Pointer, der eine Pointer currentZeit hat zeigt auf eine Liste mite einem h�heren Highscore Wert
        // und previousZeit, der auf den vorherigen Listeneintrag zeigt
        Node* currentZeit = headZeit;
        Node* previousZeit = nullptr;
        while (currentZeit != nullptr && currentZeit->Zeit < newNode->Zeit) { //Die Liste wird so lange durchgegangen bis endweder das Ende erreicht wurde oder ein h�herer Wert als der Wert vom neuen Eintrag erreicht wurde
            previousZeit = currentZeit;
            currentZeit = currentZeit->nextZeit;
        }

        //Hier wird die richtige Reihenfolge vom Pointer f�r Zeit sichergestellt
        // Man erh�lt hieraus zwei Pointer, der eine Pointer currentZeit hat zeigt auf eine Liste mite einem h�heren Highscore Wert
        // und previousZeit, der auf den vorherigen Listeneintrag zeigt
        Node* currentName = headName;
        Node* previousName = nullptr;
        while (currentName != nullptr && currentName->Name < strValue) { //Die Liste wird so lange durchgegangen bis endweder das Ende erreicht wurde oder ein h�herer Wert als der Wert vom neuen Eintrag erreicht wurde
            previousName = currentName;
            currentName = currentName->nextName;
        }

        // Hier werden die Pointer richtig verlegt, sodass das neue Listenelement richtig eingef�gt wurde
        if (previousHighscore == nullptr) { // Sollte das neue Element das kleinste sein, muss es an erste Stelle eingef�gt werden und daraus folgen besondere Anweisungen
            newNode->nextHighscore = head; //Das neue Element, was jetzt an erster Stelle steht muss auf das ehemalige erste Element zeigen, was jetzt das zweite ist.
            head = newNode; // Der Pointer der Klasse zeigt direkt auf das neue Element
        }
        else { //Wenn das neue Element nicht das neue erste Element ist, dann wird es zwischen currentHighscore, was auf eine Listenelement mit einem gr��eren Highscore zeigt, und previousHighscore, was das vorherige Listenelement ist, einsortiert
            newNode->nextHighscore = currentHighscore;
            previousHighscore->nextHighscore = newNode;
        }

        // Das verfahren von Highscore wird analog auf Zeit �bertragen
        if (previousZeit == nullptr) {
            newNode->nextZeit = headZeit;
            headZeit = newNode;
        }
        else {
            newNode->nextZeit = currentZeit;
            previousZeit->nextZeit = newNode;
        }

        // Das Verfahren von Highscore wird auf den String �bertragen
        if (previousName == nullptr) {
            newNode->nextName = headName;
            headName = newNode;
        }
        else {
            newNode->nextName = currentName;
            previousName->nextName = newNode;
        }
        Positionsbestimmung(head);
    };
};
//Diese Funktion sorgt daf�r, dass ein alte Daten in die Liste eingef�gt werden
void highscore::insertNode(int value1, time_t value2, const string& strValue) {
    //Hier werden die gegeben Werte, Name und Anzahl der Z�ge eingef�gt
    Node* newNode = new Node;
    newNode->Highscore = value1;
    newNode->Name = strValue;
    newNode->nextHighscore = nullptr;
    newNode->nextZeit = nullptr;
    newNode->nextName = nullptr;

    //Hier wird das Datum in Unix auf Zeit gespeichert
    if (value2 == 0) { //Sollte kein Wert f�r die Zeit gegeben worden sein, muss eine neue Zeit gespeichert werden. Das ist im Fall, dass es ein Fehler bei der Interpretation der Daten gibt.
        newNode->Zeit = time(nullptr);
    }
    else { //Sollte eine Zeit gegeben worden sein, wie z.B. aus bereits gespeicherten Daten, wird der Zeitstempel �bernommen, damit nicht die Zeit des Laden genommen wird
        newNode->Zeit = value2;
    }

    //Wenn die Liste leer ist, kann man die Pointer der Klasse direkt dem neuen Eintrag zuordnen.
    if (head == nullptr) {
        head = newNode;
        headZeit = newNode;
        headName = newNode;
        newNode->Position = 1;
        return;
    }
    else {
        //Hier wird die richtige Reihenfolge vom Pointer f�r Highscore sichergestellt
        // Man erh�lt hieraus zwei Pointer, der eine Pointer currentHighscore hat zeigt auf eine Liste mite einem h�heren Highscore Wert
        // und previousHighscore, der auf den vorherigen Listeneintrag zeigt
        Node* currentHighscore = head;
        Node* previousHighscore = nullptr;
        while (currentHighscore != nullptr && currentHighscore->Highscore < value1) { //Die Liste wird so lange durchgegangen bis endweder das Ende erreicht wurde oder ein h�herer Wert als der Wert vom neuen Eintrag erreicht wurde
            previousHighscore = currentHighscore;
            currentHighscore = currentHighscore->nextHighscore;
        }

        //Hier wird die richtige Reihenfolge vom Pointer f�r Zeit sichergestellt
        // Man erh�lt hieraus zwei Pointer, der eine Pointer currentZeit hat zeigt auf eine Liste mite einem h�heren Highscore Wert
        // und previousZeit, der auf den vorherigen Listeneintrag zeigt
        Node* currentZeit = headZeit;
        Node* previousZeit = nullptr;
        while (currentZeit != nullptr && currentZeit->Zeit < newNode->Zeit) { //Die Liste wird so lange durchgegangen bis endweder das Ende erreicht wurde oder ein h�herer Wert als der Wert vom neuen Eintrag erreicht wurde
            previousZeit = currentZeit;
            currentZeit = currentZeit->nextZeit;
        }

        //Hier wird die richtige Reihenfolge vom Pointer f�r Zeit sichergestellt
        // Man erh�lt hieraus zwei Pointer, der eine Pointer currentZeit hat zeigt auf eine Liste mite einem h�heren Highscore Wert
        // und previousZeit, der auf den vorherigen Listeneintrag zeigt
        Node* currentName = headName;
        Node* previousName = nullptr;
        while (currentName != nullptr && currentName->Name < strValue) { //Die Liste wird so lange durchgegangen bis endweder das Ende erreicht wurde oder ein h�herer Wert als der Wert vom neuen Eintrag erreicht wurde
            previousName = currentName;
            currentName = currentName->nextName;
        }

        // Hier werden die Pointer richtig verlegt, sodass das neue Listenelement richtig eingef�gt wurde
        if (previousHighscore == nullptr) { // Sollte das neue Element das kleinste sein, muss es an erste Stelle eingef�gt werden und daraus folgen besondere Anweisungen
            newNode->nextHighscore = head; //Das neue Element, was jetzt an erster Stelle steht muss auf das ehemalige erste Element zeigen, was jetzt das zweite ist.
            newNode->Position = 1;
            head = newNode; // Der Pointer der Klasse zeigt direkt auf das neue Element
        }
        else { //Wenn das neue Element nicht das neue erste Element ist, dann wird es zwischen currentHighscore, was auf eine Listenelement mit einem gr��eren Highscore zeigt, und previousHighscore, was das vorherige Listenelement ist, einsortiert
            newNode->nextHighscore = currentHighscore;
            previousHighscore->nextHighscore = newNode;
        }

        // Das verfahren von Highscore wird analog auf Zeit �bertragen
        if (previousZeit == nullptr) { 
            newNode->nextZeit = headZeit;
            headZeit = newNode;
        }
        else { 
            newNode->nextZeit = currentZeit;
            previousZeit->nextZeit = newNode;
        }

        // Das Verfahren von Highscore wird auf den String �bertragen
        if (previousName == nullptr) {
            newNode->nextName = headName;
            headName = newNode;
        }
        else { 
            newNode->nextName = currentName;
            previousName->nextName = newNode;
        }
    };
};
// Diese Funktion erm�glicht, dass Highscoredaten langfristig aus einer .txt Datei geladen werden k�nnen.
void highscore::loadFromFile(const string& filename) {
    ifstream inputFile(filename);
    if (!inputFile) { //Sollte die Datei nicht gefunden oder ge�ffnet werden k�nnen, wird dieser Fehler geworfen
        cerr << "Error 300: Datei kann nicht ge�ffnet werden " << filename << endl;
        return;
    }

    string line;
    while (getline(inputFile, line)) { //Die Zeilen der .txt Datei werden durchgegangen
        istringstream iss(line);
        int value1; //Die Daten, die in die Liste geh�ren werden initiert
        time_t value2;
        string strValue;
        char comma; //Die Daten sind durch ein Komma getrennt
        if (iss >> value1 >> comma >> value2 >> comma) { //Die Daten aus der Zeile werden ausgelesen und in die initierten Variablen eingef�gt
            if (!getline(iss >> ws, strValue)) {
                cerr << "Error 301: Fehler beim Lesen der Zeile: " << line << endl; //Sollte eine Zeile nicht ordentlich gespeichert worden sein, kommt ein Fehler
                continue; // Die n�chste Zeile kommt
            }
            insertNode(value1, value2, strValue); // Die Daten aus der Zeile gelesen wurden, werden jetzt als neues Listenelement eingef�gt
        }
        else {
            cerr << "Error 302: Fehler beim Lesen der Zeile: " << line << endl;
        }
    }

    inputFile.close(); //Sobald alle Daten gelesen wurde, wird die Datei wieder geschlossen
    Positionsbestimmung(head);
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

    Node* current = head;
    while (current != nullptr) { //Die Liste wird nach Highscore durchlaufen und mit "," getrennt
        outputFile << current->Highscore << "," << current->Zeit << "," << current->Name << endl;  //Die Daten werden in eine Zeile geschrieben
        current = current->nextHighscore;
    }

    outputFile.close(); //Die Datei mit den Daten wird geschlossen
};

//Diese Funktion erm�glicht die Darstellung der Funktion im Terminal
void highscore::displaySorted(char sortBy, bool ascending) {
    Node* current = nullptr;

    switch (sortBy) { //Diser bestimmt, nach welcher Variable (Name, Datum oder Z�ge) sortiert werden muss
    case '1': //Sortierung nach dem Highscore
        cout << "Sortierung erfolgte nach dem Highscore:\n" << endl;
        current = ascending ? head : findLastNodeHighscore(head); // Es wird noch gefragt, ob es aufsteigend oder absteigend ist und dementsprechend wird der Start gesetzt
        break;
    case '2': //Sortierung nach dem Datum
        cout << "Sortierung erfolgte nach dem Datum:\n" << endl;
        current = ascending ? headZeit : findLastNodeZeit(headZeit); // Es wird noch gefragt, ob es aufsteigend oder absteigend ist und dementsprechend wird der Start gesetzt
        break;
    case 's': //Sortierung nach dem Namen
        cout << "Sortierung erfolgte nach dem Namen:\n" << endl;
        current = ascending ? headName : findLastNodeDataStr(headName); // Es wird noch gefragt, ob es aufsteigend oder absteigend ist und dementsprechend wird der Start gesetzt
        break;
    default:
        cerr << "Error 320: Invalide Sortier Option." << endl; //Sollte ein Fehler auftreten und keine richtige Eingabe kommen, wird dieser Fehler geworden. Das ist ein interer Test, da die Funktion ohne Konsoleneingabe funktioniert.
        return;
    }
    //Hier wird die Liste ausgegeben
    cout << "Position | Highscore | Datum       | Name" << endl;
    while (current != nullptr) {//Man durchl�ut in der Schleife die ganze geladene Liste
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
            current = ascending ? current->nextHighscore : findPreviousNodeHighscore(current, head); //Wenn aufsteigend sortiert wird, folgt man der List direkt. Wenn absteigend sortiert wird, muss man den vorherigen Eintrag finden
        }
        else if (sortBy == '2') { //Datum
            current = ascending ? current->nextZeit : findPreviousNodeZeit(current, headZeit); //Wenn aufsteigend sortiert wird, folgt man der List direkt. Wenn absteigend sortiert wird, muss man den vorherigen Eintrag finden
        }
        else { //Name
            current = ascending ? current->nextName : findPreviousNodeName(current, headName); //Wenn aufsteigend sortiert wird, folgt man der List direkt. Wenn absteigend sortiert wird, muss man den vorherigen Eintrag finden
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
//Die Funktion findet das letzte Element der Liste sortiert nach dem Highscore.
Node* highscore::findLastNodeHighscore(Node* head) {
    Node* current = head;
    while (current != nullptr && current->nextHighscore != nullptr) { //Die Schleife l�uft durch die Liste bis ein Nullpointer erreicht wurde
        current = current->nextHighscore;
    }
    return current;
}
//Die Funktion macht das gleiche wie die fast gleichnamige Funktion nur f�r Zeit anstelle von Highscore
Node* highscore::findLastNodeZeit(Node* head) {
    Node* current = head;
    while (current != nullptr && current->nextZeit != nullptr) {
        current = current->nextZeit;
    }
    return current;
}
//Die Funktion macht das gleiche wie die fast gleichnamige Funktion nur f�r den String anstelle von Highscore
Node* highscore::findLastNodeDataStr(Node* head) {
    Node* current = head;
    while (current != nullptr && current->nextName != nullptr) {
        current = current->nextName;
    }
    return current;
}
//Die Funktion findet das vorherige Listelement
Node* highscore::findPreviousNodeHighscore(Node* current, Node* head) {
    Node* prev = head;
    while (prev != nullptr && prev->nextHighscore != current) { //Diese Funktion geht die Liste so lange durch, bis auf das aktuelle Element gezeigt wird
        prev = prev->nextHighscore;
    }
    return prev; //Gibt das Listenelement aus, was �ber Highscore auf das aktuelle Listenelement zeigt
}
//Die Funktion macht das gleiche wie die fast gleichnamige Funktion nur f�r Zeit anstelle von Highscore
Node* highscore::findPreviousNodeZeit(Node* current, Node* head) {
    Node* prev = head;
    while (prev != nullptr && prev->nextZeit != current) {
        prev = prev->nextZeit;
    }
    return prev;
}
//Die Funktion macht das gleiche wie die fast gleichnamige Funktion nur f�r den Strinanstelle von Highscore
Node* highscore::findPreviousNodeName(Node* current, Node* head) {
    Node* prev = head;
    while (prev != nullptr && prev->nextName != current) {
        prev = prev->nextName;
    }
    return prev;
}
//Die Funktion l�uft durch die Liste anhand des Highscores und verteilt die Positionsnummer
Node* highscore::Positionsbestimmung(Node* head) {
    Node* current = head;
    int Number = 0;
    while (current != nullptr) { //Die Schleife l�uft durch die Liste bis ein Nullpointer erreicht wurde
        Number++;
        current->Position = Number;
        current = current->nextHighscore;
    }
    return 0;
}

BallNode* highscore::createBallNode(int highscore, const string& name){
    createBallNode(highscore, time(nullptr), name);
}

BallNode* highscore::createBallNode(int highscore, time_t time, const string& name){
    BallNode* newNode = new BallNode;
    newNode->Highscore = highscore;
    newNode->Zeit = time;
    newNode->Name = name;
    newNode->nextNodes[0] = nullptr;
    newNode->nextNodes[1] = nullptr;
    newNode->nextNodes[2] = nullptr;
    insertNode(newNode);
    return newNode;
}

void highscore::insertNode(BallNode* newNode){
    insertNodeByHighscore(newNode);
    insertNodeByZeit(newNode);
    insertNodeByName(newNode);
}

void highscore::insertNodeByHighscore(BallNode* newNode){
    BallNode* current = headBall[0];
    BallNode* prev = nullptr;
    while (current != nullptr && current->Highscore < newNode->Highscore) {
        prev = current;
        current = current->nextNodes[0];
    }
    if (prev == nullptr) {
        newNode->nextNodes[0] = current;
        headBall[0] = newNode;
        newNode->previousNodes[0] = nullptr;
        current->previousNodes[0] = newNode;
    }
    else {
        if(current == tailBall[0]){
            if(current->Highscore < newNode->Highscore){
                tailBall[0] = newNode;
                newNode->nextNodes[0] = nullptr;
                newNode->previousNodes[0] = current;
            }
        } else
        {
            prev->nextNodes[0] = newNode;
            newNode->nextNodes[0] = current;
            newNode->previousNodes[0] = prev;
            current->previousNodes[0] = newNode;
        }
    }
}

void highscore::insertNodeByZeit(BallNode* newNode){
    BallNode* current = headBall[1];
    BallNode* prev = nullptr;
    while (current != nullptr && current->Zeit < newNode->Zeit) {
        prev = current;
        current = current->nextNodes[1];
    }
    if (prev == nullptr) {
        newNode->nextNodes[1] = current;
        headBall[1] = newNode;
        newNode->previousNodes[1] = nullptr;
        current->previousNodes[1] = newNode;
    }
    else {
        if(current == tailBall[1]){
            if(current->Zeit < newNode->Zeit){
                tailBall[1] = newNode;
                newNode->nextNodes[1] = nullptr;
                newNode->previousNodes[1] = current;
            }
        } else
        {
            prev->nextNodes[1] = newNode;
            newNode->nextNodes[1] = current;
            newNode->previousNodes[1] = prev;
            current->previousNodes[1] = newNode;
        }
    }
}

void highscore::insertNodeByName(BallNode* newNode){
    BallNode* current = headBall[2];
    BallNode* prev = nullptr;
    while (current != nullptr && current->Name < newNode->Name) {
        prev = current;
        current = current->nextNodes[2];
    }
    if (prev == nullptr) {
        newNode->nextNodes[2] = current;
        headBall[2] = newNode;
        newNode->previousNodes[2] = nullptr;
        current->previousNodes[2] = newNode;
    }
    else {
        if(current == tailBall[2]){
            if(current->Name < newNode->Name){
                tailBall[2] = newNode;
                newNode->nextNodes[2] = nullptr;
                newNode->previousNodes[2] = current;
            }
        } else
        {
            prev->nextNodes[2] = newNode;
            newNode->nextNodes[2] = current;
            newNode->previousNodes[2] = prev;
            current->previousNodes[2] = newNode;
        }
    }
}






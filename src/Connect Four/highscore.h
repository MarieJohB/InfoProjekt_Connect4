#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <ctime>
using namespace::std;
struct Node { //Die Struktur der verketteten List
    int Highscore; //Anzahl der benötigten Züge
    time_t Zeit; //Zeit des Sieges
    string Name; //Name des Siegers
    int Position; // Die Position, sortiert nach dem Highscore
    //Diese Arrays beinhalten drei Pointer, die jeweils für die drei Varaiblen, nachdenen sortiert wird, zeigen.
    Node* nextNode[3]; //Zeigt zum nächst höheren
    Node* previousNode[3]; //Zeigt zum nächst niedrigeren
};
class highscore{
private:
    //Diese Arrays beinhalten drei Pointer, die auf Enden der verketteten Liste zeigen für jede Varaible
    Node* head[3]; //Zeigt auf den Start
    Node* tail[3]; //Zeigt auf das Ende
    //Das sind Hilfsfunktionen, die nicht von extern aufgerufen werden sondern nur intern
    string formatUnixTime(time_t unixTime);
    Node* Positionsbestimmung(Node* head);
    //Unterfunktionen, damit insertNode nicht zu groß wird.
    void sortNode(Node* newNode);
    void sortNodeHighscore(Node* newNode);
    void sortNodeZeit(Node* newNode);
    void sortNodeName(Node* newNode);

public:
    highscore(); //Konstruktor
    ~highscore(); //Destruktor
    // Die Funktionen werden initiert und in der cpp Datei definiert
    void insertNode(int value1, const string& strValue);
    void insertNode(int value1, time_t value2, const string& strValue); 
    void loadFromFile(const string& filename);
    void saveToFile(const string& filename);
    void displaySorted(char sortBy, bool ascending);

};
#endif

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <ctime>
using namespace::std;
struct Node { //Die Struktur der verketteten List
    int data1; //Anzahl der benötigten Züge
    time_t data2; //Zeit des Sieges
    string strData; //Name des Siegers
    Node* nextData1; //Das ist ein Pointer, der auf das nächste (aufsteigend sortiert) Listenelement nach Data1 zeigt
    Node* nextData2; //Das ist ein Pointer, der auf das nächste (aufsteigend sortiert) Listenelement nach Data2 zeigt
    Node* nextStrData; //Das ist ein Pointer, der auf das nächste (aufsteigend sortiert) Listenelement nach dem String zeigt
};
class highscore{
private:
    Node* head; //Zeigt auf das erste Element nach Data1
    Node* headData2; // Zeiger auf das erste Element nach Data2
    Node* headStrData; //Zeigt auf das erste Element nach String

    //Das sind Hilfsfunktionen, die nicht von extern aufgerufen werden sondern nur intern
    string formatUnixTime(time_t unixTime);
    Node* findLastNodeData2(Node* head);
    Node* findLastNodeData1(Node* head);
    Node* findLastNodeDataStr(Node* head);
    Node* findPreviousNodeData1(Node* current, Node* head);
    Node* findPreviousNodeData2(Node* current, Node* head);
    Node* findPreviousNodeStrData(Node* current, Node* head);


public:
    highscore(); //Konstruktor
    ~highscore(); //Destruktor
    // Die Funktionen werden initiert und in der cpp Datei definiert
    void insertNode(int value1, time_t value2, const string& strValue); 
    void loadFromFile(const string& filename);
    void saveToFile(const string& filename);
    void displaySorted(char sortBy, bool ascending);

};
#endif

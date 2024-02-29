#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <ctime>
using namespace::std;
struct Node { //Die Struktur der verketteten List
    int Highscore; //Anzahl der ben�tigten Z�ge
    time_t Zeit; //Zeit des Sieges
    string Name; //Name des Siegers
    int Position; // Die Position, sortiert nach dem Highscore
    Node* nextHighscore; //Das ist ein Pointer, der auf das n�chste (aufsteigend sortiert) Listenelement nach Highscore zeigt
    Node* nextZeit; //Das ist ein Pointer, der auf das n�chste (aufsteigend sortiert) Listenelement nach Zeit zeigt
    Node* nextName; //Das ist ein Pointer, der auf das n�chste (aufsteigend sortiert) Listenelement nach dem String zeigt
};

struct BallNode{
    int Highscore;
    time_t Zeit;
    string Name;
    int Position;
    BallNode** nextNodes = new BallNode*[3];
    BallNode** previousNodes = new BallNode*[3];
};

class highscore{
private:
    Node* head; //Zeigt auf das erste Element nach Highscore
    Node* headZeit; // Zeiger auf das erste Element nach Zeit
    Node* headName; //Zeigt auf das erste Element nach String
    BallNode** headBall = new BallNode*[3]; //Zeigt auf erste Elemente
    BallNode** tailBall = new BallNode*[3]; //Zeigt auf letzte Elemente

    //Das sind Hilfsfunktionen, die nicht von extern aufgerufen werden sondern nur intern
    string formatUnixTime(time_t unixTime);
    Node* findLastNodeZeit(Node* head);
    Node* findLastNodeHighscore(Node* head);
    Node* findLastNodeDataStr(Node* head);
    Node* findPreviousNodeHighscore(Node* current, Node* head);
    Node* findPreviousNodeZeit(Node* current, Node* head);
    Node* findPreviousNodeName(Node* current, Node* head);
    Node* Positionsbestimmung(Node* head);
    void insertNode(BallNode* newNode);
    void insertNodeByHighscore(BallNode* newNode);
    void insertNodeByZeit(BallNode* newNode);
    void insertNodeByName(BallNode* newNode);


public:
    highscore(); //Konstruktor
    ~highscore(); //Destruktor
    // Die Funktionen werden initiert und in der cpp Datei definiert
    void insertNode(int value1, const string& strValue);
    void insertNode(int value1, time_t value2, const string& strValue); 
    void loadFromFile(const string& filename);
    void saveToFile(const string& filename);
    void displaySorted(char sortBy, bool ascending);
    BallNode* createBallNode(int value1, const string& strValue);
    BallNode* createBallNode(int value1, time_t value2, const string& strValue);



};
#endif

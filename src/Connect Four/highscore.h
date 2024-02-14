#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <ctime>
using namespace::std;
struct Node {
    int data1;
    time_t data2;
    string strData;
    Node* nextData1;
    Node* nextData2;
    Node* nextStrData;
};
class highscore{
private:
    Node* head;
    Node* headData2; // Pointer to the first element sorted by data2
    Node* headStrData; // Pointer to the first element sorted by strData

public:
    highscore(); //constructor
    ~highscore(); //Destructor

    void insertNode(int value1, time_t value2, const string& strValue);
    void loadFromFile(const string& filename);
    void saveToFile(const string& filename);
    void displaySorted(char sortBy, bool ascending);

    string formatUnixTime(time_t unixTime);
    Node* findLastNodeData2(Node* head);
    Node* findLastNodeData1(Node* head);
    Node* findLastNodeDataStr(Node* head);
    Node* findPreviousNodeData1(Node* current, Node* head);
    Node* findPreviousNodeData2(Node* current, Node* head);
    Node* findPreviousNodeStrData(Node* current, Node* head);

    //string formatUnixTime(time_t unixTime);
};
#endif

#include "highscore.h"
using namespace::std;
#include <iostream>
#include <fstream>
#include <sstream>
#include <ctime>

highscore::highscore() : head(nullptr), headData2(nullptr), headStrData(nullptr) {}

// Destructor
highscore::~highscore() {
    while (head != nullptr) {
        Node* temp = head;
        head = head->nextData1;
        headData2 = headData2->nextData2;
        headStrData = headStrData->nextStrData;
        delete temp;
    }
};

void highscore::insertNode(int value1, time_t value2, const string& strValue) {
    Node* newNode = new Node;
    newNode->data1 = value1;
    newNode->strData = strValue;
    newNode->nextData1 = nullptr;
    newNode->nextData2 = nullptr;
    newNode->nextStrData = nullptr;

    // Assign the value of data2
    if (value2 == 0) { // If value2 is not provided, assign the current time
        newNode->data2 = time(nullptr);
    }
    else {
        newNode->data2 = value2;
    }

    // If the list is empty, set the new node as the head and update other pointers
    if (head == nullptr) {
        head = newNode;
        headData2 = newNode;
        headStrData = newNode;
        return;
    }

    // Find the appropriate position to insert the new node based on data1
    Node* currentData1 = head;
    Node* previousData1 = nullptr;
    while (currentData1 != nullptr && currentData1->data1 < value1) {
        previousData1 = currentData1;
        currentData1 = currentData1->nextData1;
    }

    // Find the appropriate position to insert the new node based on data2
    Node* currentData2 = headData2;
    Node* previousData2 = nullptr;
    while (currentData2 != nullptr && currentData2->data2 < newNode->data2) {
        previousData2 = currentData2;
        currentData2 = currentData2->nextData2;
    }

    // Find the appropriate position to insert the new node based on strData
    Node* currentStrData = headStrData;
    Node* previousStrData = nullptr;
    while (currentStrData != nullptr && currentStrData->strData < strValue) {
        previousStrData = currentStrData;
        currentStrData = currentStrData->nextStrData;
    }

    // Update the pointers to insert the new node based on data1
    if (previousData1 == nullptr) { // Insert at the beginning of the list
        newNode->nextData1 = head;
        head = newNode;
    }
    else { // Insert in the middle or at the end of the list
        newNode->nextData1 = currentData1;
        previousData1->nextData1 = newNode;
    }

    // Update the pointers to insert the new node based on data2
    if (previousData2 == nullptr) { // Insert at the beginning of the list
        newNode->nextData2 = headData2;
        headData2 = newNode;
    }
    else { // Insert in the middle or at the end of the list
        newNode->nextData2 = currentData2;
        previousData2->nextData2 = newNode;
    }

    // Update the pointers to insert the new node based on strData
    if (previousStrData == nullptr) { // Insert at the beginning of the list
        newNode->nextStrData = headStrData;
        headStrData = newNode;
    }
    else { // Insert in the middle or at the end of the list
        newNode->nextStrData = currentStrData;
        previousStrData->nextStrData = newNode;
    }
};
void highscore::loadFromFile(const string& filename) {
    ifstream inputFile(filename);
    if (!inputFile) {
        cerr << "Error: Unable to open file " << filename << endl;
        return;
    }

    string line;
    while (getline(inputFile, line)) {
        istringstream iss(line);
        int value1;
        time_t value2;
        string strValue;
        char comma;
        if (iss >> value1 >> comma >> value2 >> comma) {
            if (!getline(iss >> ws, strValue)) {
                cerr << "Error reading line: " << line << endl;
                continue; // Skip to the next line
            }
            insertNode(value1, value2, strValue); // Inserts node while maintaining sorted order
        }
        else {
            cerr << "Error reading line: " << line << endl;
        }
    }

    inputFile.close();
};
void highscore::saveToFile(const string& filename) {
    ofstream outputFile(filename);
    if (!outputFile) {
        cerr << "File " << filename << " does not exist. Creating a new file." << endl;
        outputFile.open(filename, ios::out);
        if (!outputFile) {
            cerr << "Error: Unable to create file " << filename << " for writing." << endl;
            return;
        }
    }

    Node* current = head;
    while (current != nullptr) {
        outputFile << current->data1 << "," << current->data2 << "," << current->strData << endl;
        current = current->nextData1;
    }

    outputFile.close();
};
void highscore::displaySorted(char sortBy, bool ascending) {
    Node* current = nullptr;

    switch (sortBy) {
    case '1':
        cout << "Sorted by Highscore:" << endl;
        current = ascending ? head : findLastNodeData1(head); // Set current to the last node for descending order;
        break;
    case '2':
        cout << "Sorted by Date:" << endl;
        current = ascending ? headData2 : findLastNodeData2(headData2); // Set current to the last node for descending order
        break;
    case 's':
        cout << "Sorted by Name:" << endl;
        current = ascending ? headStrData : findLastNodeDataStr(headStrData); // Set current to the last node for descending order;
        break;
    default:
        cerr << "Invalid sorting option." << endl;
        return;
    }

    while (current != nullptr) {
        cout << "Highscore: " << current->data1 << ", ";
        cout << "Date: " << formatUnixTime(current->data2) << ", ";
        cout << "Name: " << current->strData << endl;

        if (sortBy == '1') {
            current = ascending ? current->nextData1 : findPreviousNodeData1(current, head);
        }
        else if (sortBy == '2') {
            current = ascending ? current->nextData2 : findPreviousNodeData2(current, headData2); // Update traversal direction
        }
        else {
            current = ascending ? current->nextStrData : findPreviousNodeStrData(current, headStrData); // Update traversal direction
        }
    }
}

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
Node* highscore::findLastNodeData2(Node* head) {
    Node* current = head;
    while (current != nullptr && current->nextData2 != nullptr) {
        current = current->nextData2;
    }
    return current;
}
Node* highscore::findLastNodeData1(Node* head) {
    Node* current = head;
    while (current != nullptr && current->nextData1 != nullptr) {
        current = current->nextData1;
    }
    return current;
}
Node* highscore::findLastNodeDataStr(Node* head) {
    Node* current = head;
    while (current != nullptr && current->nextStrData != nullptr) {
        current = current->nextStrData;
    }
    return current;
}
Node* highscore::findPreviousNodeData1(Node* current, Node* head) {
    Node* prev = head;
    while (prev != nullptr && prev->nextData1 != current) {
        prev = prev->nextData1;
    }
    return prev;
}
Node* highscore::findPreviousNodeData2(Node* current, Node* head) {
    Node* prev = head;
    while (prev != nullptr && prev->nextData2 != current) {
        prev = prev->nextData2;
    }
    return prev;
}
Node* highscore::findPreviousNodeStrData(Node* current, Node* head) {
    Node* prev = head;
    while (prev != nullptr && prev->nextStrData != current) {
        prev = prev->nextStrData;
    }
    return prev;
}






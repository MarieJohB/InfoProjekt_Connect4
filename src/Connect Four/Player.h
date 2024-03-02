#pragma once
#include <string>
#include "Statistik.h"
using namespace::std;

class Player
{

private: 

    string name;
    int punktzahl;
    

public:

    Statistik* SpielerStats;
	// Konstruktor
    Player( string name_, int punktzahl_);

    // Default-konstruktor:
    Player();

    // Destruktor
    ~Player();

    // Copy-Konstruktor
    Player(const Player& p);

    
    // Funktionen der Klasse Player: 
    void setName();
    int getInteger();
    string getName();
    int getPunktzahl();
    void setPunktzahl(int punktzahl);
    Player getWinner(string NameOfWinner, Player& Spieler1_, Player& Spieler2_);
  

};


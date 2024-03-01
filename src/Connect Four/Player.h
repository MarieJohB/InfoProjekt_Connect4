#pragma once
#include <string>
using namespace::std;

class Player
{
public:

    string name;
    
    int punktzahl;

	
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


#pragma once
#include <string>
using namespace::std;


class Konfiguration
{
public: 

	char input;
	int ROW;
	int COL; 
	bool displayText;
	bool play;
	bool end;


	// Konstruktor
	Konfiguration(char input_, int ROW_, int COL_, bool displayText_, bool play_, bool end_);
	Konfiguration();
	

	void askUser(string filename);

	// Funktionen, die der User aufrufen kann
	// Spiel starten:
	void startGame();
	void endGame();
	// Hilfefunktion: Spielregeln
	void Help();
	// Highscore ausgeben lassen:
	void getHighscore(string filename);

	void endProgramm();
	void wait();

};


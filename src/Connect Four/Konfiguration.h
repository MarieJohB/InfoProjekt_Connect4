#pragma once
#include <string>
#include "Player.h"

using namespace::std;


class Konfiguration
{
public: 

	char input;
	bool displayText; //Bool um die Ausgabe zu wechseln
	bool play; // Bool um in die Spielschleife zu gehen
	bool end; // Bool um das Programm zu beenden


	// Konstruktor
	Konfiguration(char input_, bool displayText_, bool play_, bool end_);
	Konfiguration();
	

	void askUser(string filename, Player& Spieler1, Player& Spieler2);

	// Funktionen, die der User aufrufen kann
	// Spiel starten:
	void startGame(Player& Spieler1, Player& Spieler2); // Uebergabe der Klasse mit CallByRefernece
	void endGame();
	// Hilfefunktion: Spielregeln
	void Help();
	// Highscore ausgeben lassen:
	void getHighscore(string filename);
	// Beenden
	void endProgramm();
	// Warte-Funktion wird an verschiedenen Stellen verwendet
	void wait();

};


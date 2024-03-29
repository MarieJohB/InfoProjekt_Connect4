#pragma once
#include <string>
#include "Player.h"
#include "highscore.h"

using namespace::std;


class Konfiguration
{
public: 

	char input; // Eingabe durch den User
	bool displayText; //Bool um die Ausgabe zu wechseln
	bool play; // Bool um in die Spielschleife im Main zu gehen
	bool end; // Bool um das Programm zu beenden, Schleife im Main verlassen

	Konfiguration(char input_, bool displayText_, bool play_, bool end_);
	// Konstruktor
	Konfiguration();

	void askUser(string filename, Player& Spieler1, Player& Spieler2);
	// Uebergabe der Klasse mit CallByRefernece, wird weiter gegeben an startGame()

	// Warte-Funktion wird an verschiedenen Stellen verwendet
	void wait();

	//Beenden der Spielinstanz
	void endGame();

private:


	
	// Methoden der Klasse: 

	// Funktionen, die der User aufrufen kann
	// Spiel starten:
	void startGame(Player& Spieler1, Player& Spieler2); // Uebergabe der Klasse mit CallByRefernece
	// Hilfefunktion: Spielregeln
	void Help();
	// Highscore ausgeben lassen:
	void getHighscore(string filename);
	// Beenden
	void endProgramm();

};


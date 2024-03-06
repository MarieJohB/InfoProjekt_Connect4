#include "Statistik.h"
using namespace::std;

Statistik::Statistik(){
	AnzahlSpiele = 0; // Initialisieren mit 0, um Nullptr beim Kopieren zu verhindern
}

// Copy-Konstruktor
Statistik::Statistik(const Statistik& S) {
	this->AnzahlSpiele = S.AnzahlSpiele;
}	
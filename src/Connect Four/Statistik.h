#pragma once
using namespace::std;

class Statistik // Dummy-Klasse fuer die Anwendung eines Copy-Konstruktors 
{
public:
	int AnzahlSpiele; 
	Statistik();

	// auch einen Copy-Konstruktor fuer Deep-Copy
	Statistik(const Statistik& S);
};


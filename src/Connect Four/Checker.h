#pragma once
#ifndef __Checker__
#define __Checker__
#pragma once
#include <fstream>
#include <stdio.h>
#include <iostream>
using namespace::std;


class Checker{

public:

	char checkTextAusgabe(char Textausgeben);
	char checkNumberAusgabe(char ausgabe);

	string checkPlayerTurn(int Turn, string NameSpieler1, string NameSpieler2);

};
#endif
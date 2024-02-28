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

	char checkTextAusgabe();
	char checkNumberAusgabe();

	bool AusgabeZuordnen(char SpielAusgeben);

};
#endif
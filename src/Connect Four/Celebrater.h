#pragma once
#ifndef __Celebrater__
#define __Celebrater__
#pragma once
#include <fstream>
#include <stdio.h>
#include <iostream>
using namespace::std;


class Celebrater {

public:

	//Abspielen der Animation
	void victoryDance();

	//Kurze Pausen fuer eigenen Style der Animation durchfuehren
	void PauseAndClearBeforeResume();

};
#endif
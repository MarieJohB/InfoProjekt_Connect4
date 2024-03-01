#pragma once
#include <fstream>
#include <stdio.h>
#include <iostream>
using namespace::std;


class Celebrater {

public:

	//Abspielen der Animation
	void victoryDance();

private:

	//Kurze Pausen fuer eigenen Style der Animation durchfuehren
	void PauseAndClearBeforeResume();
};
#pragma once
#include <stdio.h>

class HighscoreManager
{
public:
	static int LoadHighscore();
	static void SaveHighscore(int score);
};


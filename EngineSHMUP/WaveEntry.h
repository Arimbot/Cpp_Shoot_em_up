#pragma once
#include "enemyType_t.h"

class WaveEntry
{
public:
	enemyType_t enemyType;
	long int timeToNextEnemy;
	int positionX;
	int positionY;

	WaveEntry();
	~WaveEntry();
};


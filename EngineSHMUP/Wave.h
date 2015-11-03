#pragma once
#include <queue>
#include "WaveEntry.h"
#include "AEnemy.h"

class Wave
{
public:
	Wave();
	~Wave();
	std::queue<WaveEntry> waveEntries;
};


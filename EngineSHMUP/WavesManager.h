#pragma once
#include <string>
#include <list>
#include <fstream>
#include <sstream>
#include <iostream>
#include "AEntity.h"
#include "Wave.h"
#include "EnemyFactory.h"

using namespace std;

class WavesManager
{
public:	
	void Events(long int deltaTime);
	WavesManager();
	~WavesManager();
private:
	long int timeFromLastEnemy;
	long int timeNeededToNextEnemy;
	Wave* currentWave;
	
	void UpdateEnemyInterval(long int deltaTime); // update the interval for the next enemies to appear
	void AddEnemiesToScene();
	void AddEnemyToScene();
	Wave* ReadWave(string file);
	WaveEntry ReadEntry(string line);
	bool IsTimeToAddEnemies();
	bool ThereIsAnyEnemies(); // verify if there are enemies to be added
};


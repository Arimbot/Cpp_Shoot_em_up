#pragma once
#include <string>
#include <list>
#include <fstream>
#include <sstream>
#include <iostream>
#include "AEntity.h"
#include "Wave.h"
#include "EnemyFactory.h"
#include "EntityManager.h"

using namespace std;

class WavesManager
{
public:	
	static WavesManager* GetInstance();
	static void DeleteInstance();
	void Update(long int deltaTime);
	~WavesManager();
	bool ThereAreAnyEnemies(); // verify if there are enemies to be added

private:
	static WavesManager* instance;
	
	long int timeFromLastEnemy;
	long int timeNeededToNextEnemy;
	Wave* currentWave;
	
	WavesManager();
	void UpdateEnemyInterval(long int deltaTime); // update the interval for the next enemies to appear
	void AddEnemiesToScene();
	void AddEnemyToScene();
	Wave* ReadWave(string file);
	WaveEntry ReadEntry(string line);
	bool IsTimeToAddEnemies();
};


#include "WavesManager.h"

WavesManager* WavesManager::instance = NULL;

/*
	Reads a wave of enemies from a file and add them to the entities collection
	The format:
	enemyType x_position y_position timeForNextEnemy
	1 = Classic enemy
	2 = Classic shooting enemy
	3 = Boss
*/
Wave* WavesManager::ReadWave(string file) {
	Wave* wave = new Wave();
	
	ifstream infile = ifstream(file);
	string line;
	
	if ( !infile.good() ) {
		throw exception("File doesn't exists.");
	}

	while ( getline ( infile, line ) ) {
		istringstream iss(line);
		WaveEntry entry = ReadEntry(line);
		wave->waveEntries.push(entry);
	}

	return wave;
}

WaveEntry WavesManager::ReadEntry ( string line ) {
	istringstream iss(line);

	int enemyType, positionX, positionY, timeToNextEnemy;
	if (!(iss >> enemyType >> positionX >> positionY >> timeToNextEnemy)) {  
		throw exception("invalid file format");
	}

	WaveEntry entry = WaveEntry();
	entry.enemyType = (enemyType_t)enemyType;
	entry.positionX = positionX;
	entry.positionY = positionY;
	entry.timeToNextEnemy = timeToNextEnemy;

	return entry;
}

void WavesManager::Update(long int deltaTime) {
	if ( currentWave == NULL ) {
		currentWave = ReadWave("data1");
		timeFromLastEnemy = 0; // Reset timer	
		timeNeededToNextEnemy = 0;
	} else 
		UpdateEnemyInterval(deltaTime);
	
	if (IsTimeToAddEnemies() && ThereAreAnyEnemies())
		AddEnemiesToScene();
}

void WavesManager::AddEnemiesToScene () {
	while (IsTimeToAddEnemies() && ThereAreAnyEnemies())
		AddEnemyToScene();
}

void WavesManager::AddEnemyToScene() {
	// Get first entry and remove it from entries collection
	WaveEntry entry = currentWave->waveEntries.front();
	currentWave->waveEntries.pop();

	// Create enemy from entry
	AEnemy* enemy = EnemyFactory::CreateEnemy(entry.enemyType);
	enemy->x = entry.positionX;
	enemy->y = entry.positionY;
	timeNeededToNextEnemy = entry.timeToNextEnemy;
	timeFromLastEnemy = 0;

	// Push enemy into enemies collection
	EntityManager::GetInstance()->enemies.push_back(enemy);
}

void WavesManager::UpdateEnemyInterval(long int deltaTime) {
	timeFromLastEnemy += deltaTime;
}

bool WavesManager::ThereAreAnyEnemies() {
	return !currentWave->waveEntries.empty();
}

bool WavesManager::IsTimeToAddEnemies() {
	return timeFromLastEnemy >= timeNeededToNextEnemy;
}

WavesManager::WavesManager () {
	currentWave = NULL;
}

WavesManager::~WavesManager () {
	delete currentWave;
	currentWave = NULL;
}

WavesManager* WavesManager::GetInstance() {
	if (instance == NULL)
		instance = new WavesManager;

	return instance;
}

void WavesManager::DeleteInstance() {
	if (instance != NULL) {
		delete instance;
		instance = NULL;
	}
}
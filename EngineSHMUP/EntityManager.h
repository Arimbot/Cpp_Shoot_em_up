#ifndef _ENTITYMANAGER_H_
#define _ENTITYMANAGER_H_

#include "AEnemy.h"
#include "Player.h"
#include <vector>

using namespace std;

class EntityManager{
private:
	static EntityManager* instance;
	EntityManager();

public:
	vector<AEnemy*>	enemies;
	Player	*		player;
	vector<Shot*>	playerShots;
	vector<Shot*>	enemyShots;
	
	static EntityManager* GetInstance();
	void DeleteInstance();

	void MoveEntities(long int deltaTime);
	void DrawEntities(CHAR_INFO _consoleBuffer[SCREEN_WIDTH][SCREEN_HEIGHT]);
	int GetPlayerScore();

	~EntityManager();
};

#endif
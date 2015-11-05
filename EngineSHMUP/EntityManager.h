#ifndef _ENTITYMANAGER_H_
#define _ENTITYMANAGER_H_

#include "AEnemy.h"
#include "Player.h"
#include <vector>
#include "CollisionHandler.h"

using namespace std;

class EntityManager{
private:
	static EntityManager* instance;
	EntityManager();
	void CheckPlayerCollisionWithEnemy(AEnemy* enemy);
	void CheckPlayerShotCollisionWithEnemy(AEnemy* enemy);
public:
	vector<AEnemy*>	enemies;
	Player	*		player;
	vector<Shot*>	playerShots;
	vector<Shot*>	enemyShots;
	
	static EntityManager* GetInstance();
	static void DeleteInstance();

	void Update(long int deltaTime);
	void DrawEntities(CHAR_INFO _consoleBuffer[SCREEN_WIDTH][SCREEN_HEIGHT]);
	int GetPlayerScore();

	~EntityManager();
};

#endif
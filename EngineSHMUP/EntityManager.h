#ifndef _ENTITYMANAGER_H_
#define _ENTITYMANAGER_H_

#include "AEnemy.h"
#include "Player.h"
#include <vector>
#include "CollisionHandler.h"
#include "WavesManager.h"

using namespace std;

class EntityManager{
public:
	vector<AEnemy*>	enemies;
	Player	*		player;

	static EntityManager* GetInstance();
	static void DeleteInstance();

	void Update(long int deltaTime);
	//TODO extract the consoleBuffer to a DrawManager/Engine
	void DrawEntities(CHAR_INFO _consoleBuffer[SCREEN_WIDTH][SCREEN_HEIGHT]);
	int GetPlayerScore();
	bool IsEndOfGame();

	~EntityManager();

private:
	static EntityManager* instance;
	EntityManager();
	
	void CheckPlayerCollisionWithEnemy(AEnemy* enemy);
	void CheckPlayerShotCollisionWithEnemy(AEnemy* enemy);
	bool AreAllEnemiesDefeated();

	void Dispose();
};

#endif
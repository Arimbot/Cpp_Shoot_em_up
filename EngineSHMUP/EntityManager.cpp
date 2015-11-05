#include "EntityManager.h"

EntityManager* EntityManager::instance = NULL;

EntityManager::EntityManager(){
	player = new Player();
	player->x = 40;
	player->y = 74;
}

/*
Bouge le player et les enemies
*/
void EntityManager::DrawEntities(CHAR_INFO _consoleBuffer[SCREEN_WIDTH][SCREEN_HEIGHT]){
	player->Draw(_consoleBuffer);

	for (auto it : enemies)
		it->Draw(_consoleBuffer);
}

/*
	Bouge le player et les enemies
*/
void EntityManager::MoveEntities(long int deltaTime){	
	player->Update(deltaTime);

	// ajouter code pour deleter enemies morts ou qui sont sortis de l'ecran
	for (std::vector<AEnemy*>::iterator it = enemies.begin(); it != enemies.end();){
		AEnemy* enemy = (*it);

		if (enemy->isAlive && player->isAlive && CollisionHandler::EntityCollidesEntity((*player), (*enemy))){
			enemy->isAlive = false;
			player->isAlive = false;
		}

		for (auto shot : player->getShots()){
			if (shot->isAlive && enemy->isAlive && CollisionHandler::ShotCollidesEntity((*shot), (*enemy))){
				enemy->isAlive = false;
				shot->isAlive = false;
				player->addScore(enemy->scoreValue);
			}
		}
		
		enemy->Update(deltaTime);

		if (!enemy->isAlive)
			it = enemies.erase(it);
		else
			it++;
	}
}

int EntityManager::GetPlayerScore(){
	return player->getScore();
}

EntityManager* EntityManager::GetInstance() {
	if (instance == NULL)
		instance = new EntityManager;

	return instance;
}

void EntityManager::DeleteInstance() {
	if (instance != NULL) {
		delete instance;
		instance = NULL;
	}
}

EntityManager::~EntityManager(){
	if (player != NULL){
		delete player;
		player = NULL;
	}

	for (auto it : enemies){
		if (it != NULL){
			delete it;
			it = NULL;
		}
	}
}
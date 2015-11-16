#include "EntityManager.h"

EntityManager* EntityManager::instance = NULL;

EntityManager::EntityManager(){
	player = new Player();
	
	//TODO read player position from XML
	player->x = 40;
	player->y = 52;
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
void EntityManager::Update(long int deltaTime){	
	player->Update(deltaTime);

	for (std::vector<AEnemy*>::iterator it = enemies.begin(); it != enemies.end();){
		AEnemy* enemy = (*it);

		CheckPlayerCollisionWithEnemy(enemy);
		CheckPlayerShotCollisionWithEnemy(enemy);
		
		enemy->Update(deltaTime);
		
		if (!enemy->isAlive)
			it = enemies.erase(it); // shall not increment iterator
		else
			it++; 
	}
}

void EntityManager::CheckPlayerCollisionWithEnemy(AEnemy* enemy){
	if (enemy->isAlive && player->isAlive && CollisionHandler::EntityCollidesEntity((*player), (*enemy))){
		enemy->isAlive = false;
		player->isAlive = false;
	}
}

void EntityManager::CheckPlayerShotCollisionWithEnemy(AEnemy* enemy){
	//TODO extract player managing to PlayerManager and extract the code of shots from player to EntityManager
	for (auto shot : player->getShots()){
		if (shot->isAlive && enemy->isAlive && CollisionHandler::ShotCollidesEntity((*shot), (*enemy))){
			enemy->isAlive = false;
			shot->isAlive = false;
			player->addScore(enemy->scoreValue);
		}
	}
}

int EntityManager::GetPlayerScore(){
	return player->getScore();
}

bool EntityManager::IsEndOfGame(){
	return player == NULL || !player->isAlive || AreAllEnemiesDefeated();
}

bool EntityManager::AreAllEnemiesDefeated(){
	return enemies.empty() && !WavesManager::GetInstance()->ThereAreAnyEnemies();
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

void EntityManager::Dispose(){
	if (player != NULL){
		player->Dispose();
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

EntityManager::~EntityManager(){
	Dispose();
}
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
	for (auto it : enemies){
		it->Update(deltaTime);

		for (auto shot : player->getShots()){
			if (shot->alive == true){
				if (it->alive == true){
					for (int i = 0; i < 3; i++){
						for (int j = 0; j < 3; j++){
							if (shot->x == it->x + i && shot->y == it->y + j){
								it->alive = false;
								shot->alive = false;
								player->addScore(it->scoreValue);
							}
						}
					}
				}
			}
		}
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
#include "CollisionHandler.h"

/*
	Verifies if a shot collides with an entity
*/
bool CollisionHandler::ShotCollidesEntity(Shot shot, AEntity entity){
	
	//TODO add collisionBox to entity and modify the EntityCollidesEntity to use Width and Height instead of constants
	bool isOutOfBoxCollision = shot.x + 1 < entity.x;
	isOutOfBoxCollision |= shot.x + 1 > entity.x + 2;
	isOutOfBoxCollision |= shot.y + 1 < entity.y;
	isOutOfBoxCollision |= shot.y + 1 > entity.y + 2;

	return !isOutOfBoxCollision;
}

/*
	Verifies if an entity collides with another entity
*/
bool CollisionHandler::EntityCollidesEntity(AEntity entity, AEntity other){
	bool isOutOfBoxCollision = entity.x + 2 < other.x; // if entity is beside (right) the other entity
	isOutOfBoxCollision = entity.x > other.x + 2; // if entity is beside (left) the other entity
	isOutOfBoxCollision = entity.y + 2 < other.y; // if entity is below the other entity
	isOutOfBoxCollision = entity.y > other.y + 2; // if entity is above the other entity

	return !isOutOfBoxCollision; //any other case is a collision
}
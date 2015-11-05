#include "CollisionHandler.h"

/*
	Verifies if a shot collides with an entity
*/
bool CollisionHandler::ShotCollidesEntity(Shot shot, AEntity entity){
	bool isOutOfBoxCollision = shot.x + 1 < entity.x;
	isOutOfBoxCollision |= shot.x + 1 > entity.x + 2;
	isOutOfBoxCollision |= shot.y + 1 < entity.y;
	isOutOfBoxCollision |= shot.y + 1 > entity.y + 2;

	return !isOutOfBoxCollision;
}
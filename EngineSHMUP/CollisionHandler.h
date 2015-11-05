#pragma once

#include "Shot.h"
#include "AEntity.h"

class CollisionHandler
{
public:
	static bool ShotCollidesEntity(Shot shot, AEntity entity);
};


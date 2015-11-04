#pragma once
#include "AEntity.h"

enum ShootOrigin { PLAYER, ENEMY };

class Shoot :
	public AEntity
{
public:
	ShootOrigin shootOrigin;

	Shoot(ShootOrigin origin);
	~Shoot();
};


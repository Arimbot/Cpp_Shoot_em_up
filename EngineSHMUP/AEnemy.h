#pragma once
#include "AEntity.h"

class AEnemy :
	public AEntity
{
public:
	virtual void Move();

	AEnemy();
	~AEnemy();
};


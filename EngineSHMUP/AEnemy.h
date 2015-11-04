#pragma once
#include "AEntity.h"

class AEnemy :
	public AEntity
{
public:
	virtual void Move(long int _time);

	AEnemy();
	~AEnemy();
};


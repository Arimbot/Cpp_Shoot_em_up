#pragma once
#include "AEntity.h"

class AEnemy :
	public AEntity
{
public:
	int scoreValue;

	virtual void Move(long int _time);

	AEnemy();
	~AEnemy();
};


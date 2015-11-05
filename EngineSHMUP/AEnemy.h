#pragma once
#include "AEntity.h"

class AEnemy :
	public AEntity
{
public:
	int scoreValue;

	virtual void Update(long int time);

	AEnemy();
	~AEnemy();
};


#pragma once
#include "AEnemy.h"
#include <time.h>

class Classic :
	public AEnemy
{
public:
	float maxValue;
	bool leftRight;
	int moveX;

	virtual void Update(long int time);

	Classic();
	~Classic();
};
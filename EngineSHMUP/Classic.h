#pragma once
#include "AEnemy.h"
#include <time.h>

class Classic :
	public AEnemy
{
public:
	virtual void Move(long int _time);

	Classic();
	~Classic();
};
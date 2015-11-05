#pragma once
#include "AEnemy.h"
#include <time.h>

class Classic :
	public AEnemy
{
public:
	virtual void Update(long int time);

	Classic();
	~Classic();
};
#pragma once
#include "AEntity.h"

class Shot :
	public AEntity
{
public:
	Shot();
	~Shot();

	virtual void Move(long int _time);
};


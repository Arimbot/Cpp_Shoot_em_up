#pragma once
#include "AEntity.h"

class Shot :
	public AEntity
{
public:
	Shot();
	~Shot();

	virtual void Update(long int time);
};


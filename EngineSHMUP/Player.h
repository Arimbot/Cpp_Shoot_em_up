#ifndef _PLAYER_H_
#define _PLAYER_H_

#include "AEntity.h"

class Player : public AEntity{
private:

public:
	Player();
	~Player();

	virtual void Move(long int _time);
};

#endif
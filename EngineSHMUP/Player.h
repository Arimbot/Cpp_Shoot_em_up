#ifndef _PLAYER_H_
#define _PLAYER_H_

#include "AEntity.h"

class Player : public AEntity{
private:
	int score;

public:
	Player();
	~Player();

	inline int getScore() { return score; }

	virtual void Move(long int _time);
};

#endif
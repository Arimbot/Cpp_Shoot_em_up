#ifndef _PLAYER_H_
#define _PLAYER_H_

#include "AEntity.h"
#include "Shot.h"
#include <vector>

class Player : public AEntity{
private:
	int score;

public:
	Player();
	~Player();

	std::vector<Shot*> shots;

	inline int getScore() { return score; }

	virtual void Move(long int _time);
	virtual void Draw(CHAR_INFO _consoleBuffer[SCREEN_WIDTH][SCREEN_HEIGHT]);

	float timeFromLastShot;
	float intervalBetweenShots;
};

#endif
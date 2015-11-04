#ifndef _PLAYER_H_
#define _PLAYER_H_

#include "AEntity.h"
#include "Shot.h"
#include <vector>

class Player : public AEntity{
private:
	int score;
	float timeFromLastShot;
	float intervalBetweenShots;
	std::vector<Shot*> shots;

	void ManageShooting(long int _time);
	void ManageShots(long int _time);
public:
	Player();
	~Player();

	inline int getScore() { return score; }

	virtual void Move(long int _time);
	virtual void Draw(CHAR_INFO _consoleBuffer[SCREEN_WIDTH][SCREEN_HEIGHT]);
	void Shoot(long int _time);
};

#endif
#ifndef _PLAYER_H_
#define _PLAYER_H_

#include "AEntity.h"
#include "Shot.h"
#include <vector>

class Player : public AEntity{
private:
	int score;
	long int timeFromLastShot;
	float intervalBetweenShots;
	std::vector<Shot*> shots;

	void ManageShooting(long int time);
	void ManageShots(long int time);
	void Move(long int time);
public:
	Player();
	~Player();

	inline std::vector<Shot*>& getShots() { return shots; }

	inline int getScore() { return score; }
	inline void addScore(int _score) { score += _score; }

	virtual void Update(long int time);
	virtual void Draw(CHAR_INFO _consoleBuffer[SCREEN_WIDTH][SCREEN_HEIGHT]);
};

#endif
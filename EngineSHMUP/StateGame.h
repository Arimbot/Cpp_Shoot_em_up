#ifndef _STATEGAME_H_
#define _STATEGAME_H_

#include "AState.h"
#include "NYTimer.h"

#include "WavesManager.h"
#include "EntityManager.h"
#include "Player.h"
#include "Classic.h"

class StateGame : public AState{
private:
	bool pause;

	NYTimer moveWalls;
	float swapWalls;
	float swapWallsSpeed;

	void RenderWalls(CHAR_INFO _consoleBuffer[SCREEN_WIDTH][SCREEN_HEIGHT]);
	STATES EndGame();
public:
	StateGame();
	~StateGame();

	virtual STATES Update(long int time);
	virtual void Render(long int time, CHAR_INFO _consoleBuffer[SCREEN_WIDTH][SCREEN_HEIGHT]);
};

#endif
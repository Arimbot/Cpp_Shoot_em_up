#ifndef _STATEGAME_H_
#define _STATEGAME_H_

#include "AState.h"
#include "NYTimer.h"

#include "WavesManager.h"

class StateGame : public AState{
private:

	bool pause;

	NYTimer moveWalls;
	float swapWalls;
	float swapWallsSpeed;

	void RenderWalls(CHAR_INFO _consoleBuffer[SCREEN_WIDTH][SCREEN_HEIGHT]);

public:
	StateGame();

	virtual STATES Events(long int _time);
	virtual void Render(long int _time, CHAR_INFO _consoleBuffer[SCREEN_WIDTH][SCREEN_HEIGHT]);
};

#endif
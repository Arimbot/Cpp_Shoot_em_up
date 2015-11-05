#ifndef _STATEMENU_H_
#define _STATEMENU_H_

#include "AState.h"

class StateMenu: public AState{
private:

	int highscore;
	void RenderFrame(CHAR_INFO _consoleBuffer[SCREEN_WIDTH][SCREEN_HEIGHT]);

public:
	StateMenu();

	virtual STATES Update(long int time);
	virtual void Render(long int time, CHAR_INFO _consoleBuffer[SCREEN_WIDTH][SCREEN_HEIGHT]);
};

#endif
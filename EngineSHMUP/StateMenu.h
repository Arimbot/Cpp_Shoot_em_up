#ifndef _STATEMENU_H_
#define _STATEMENU_H_

#include "AState.h"

class StateMenu: public AState{
private:

	void RenderFrame(CHAR_INFO _consoleBuffer[SCREEN_WIDTH][SCREEN_HEIGHT]);

public:
	StateMenu();

	virtual STATES Events(long int _time);
	virtual void Render(long int _time, CHAR_INFO _consoleBuffer[SCREEN_WIDTH][SCREEN_HEIGHT]);
};

#endif
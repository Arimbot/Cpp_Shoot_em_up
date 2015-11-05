#ifndef _ASTATE_H_
#define _ASTATE_H_

#include "const.h"
#include <windows.h>
#include <string>

enum STATES{ MENU = 0, GAME = 1, CLOSE = 2 };

class AState{
protected:

	void RenderString(CHAR_INFO _consoleBuffer[SCREEN_WIDTH][SCREEN_HEIGHT], int _x, int _y, const std::string& _string, int _color);

public:

	virtual STATES Events(long int time) = 0;
	virtual void Render(long int time, CHAR_INFO _consoleBuffer[SCREEN_WIDTH][SCREEN_HEIGHT]) = 0;
};

#endif
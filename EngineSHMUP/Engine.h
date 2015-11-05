#ifndef _ENGINE_H_
#define _ENGINE_H_

#include <windows.h>
#include <conio.h>
#include <vector>

#include "const.h"

#include "NYTimer.h"
#include "StateMenu.h"
#include "StateGame.h"

class Engine{
private:
	static Engine* instance;


//App states: menu and game
	std::vector<AState*> states;
	STATES currentState;

	bool running;

//Console properties
	HANDLE hOutput;
	COORD dwBufferSize,
		dwBufferCoord;
	SMALL_RECT rcRegion;
	CHAR_INFO consoleBuffer[SCREEN_WIDTH][SCREEN_HEIGHT];


	Engine();

	int InitializeView();

	void InitializeStates();

	int SetConsoleScreenBufferInfo(COORD dwSize);

	void ClearBuffer();

public:
	~Engine();

	static Engine* GetInstance();
	void DeleteInstance();

	void Events(long int time);
	void Render(long int time);

	inline bool IsRunning() { return running; }
};

#endif
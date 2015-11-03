#include "StateGame.h"

StateGame::StateGame()
:
pause(false),
swapWalls(false)
{
	moveWalls.start();
}


STATES StateGame::Events(long int _time) {
	if (GetAsyncKeyState(VK_ESCAPE) & 0x8000 && !(GetAsyncKeyState(VK_RETURN) & 0x8000))
		pause = true;
	else if (GetAsyncKeyState(VK_RETURN) & 0x8000 && !(GetAsyncKeyState(VK_ESCAPE) & 0x8000))
		pause = false;

	if (pause == false) {
		const int frequency = 100;

		if (moveWalls.getElapsedMs() > 0 && moveWalls.getElapsedMs() < frequency)
			swapWalls = true;
		else if (moveWalls.getElapsedMs() > frequency * 2)
			moveWalls.start();
		else
			swapWalls = false;
	}

	return GAME;
}

void StateGame::Render(long int _time, CHAR_INFO _consoleBuffer[SCREEN_WIDTH][SCREEN_HEIGHT]) {
	if (pause == true)
		RenderString(_consoleBuffer, 38, 35, "PAUSE", 0x0C);

	RenderWalls(_consoleBuffer);
}

void StateGame::RenderWalls(CHAR_INFO _consoleBuffer[SCREEN_WIDTH][SCREEN_HEIGHT]) {
	const char nbRow = 4;

	for (int i = 0; i < SCREEN_HEIGHT; i++){
		for (int j = 0; j < nbRow; j++){
			char character = '\'';

			if (swapWalls == true)
				character = '/';

			if (i % 2){
				character = '/';

				if (swapWalls == true)
					character = '\'';
			}

			_consoleBuffer[i][j].Char.AsciiChar = character;
			_consoleBuffer[i][j].Attributes = 0x0A;

			_consoleBuffer[i][SCREEN_WIDTH - 1 - j].Char.AsciiChar = character;
			_consoleBuffer[i][SCREEN_WIDTH - 1 - j].Attributes = 0x0A;
		}
	}
}
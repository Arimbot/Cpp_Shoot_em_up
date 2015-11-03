#include "StateMenu.h"

StateMenu::StateMenu() {

}


STATES StateMenu::Events(long int _time) {
	if (GetAsyncKeyState('1') & 0x8000)
		return GAME;

	return MENU;
}

void StateMenu::Render(long int _time, CHAR_INFO _consoleBuffer[SCREEN_WIDTH][SCREEN_HEIGHT]) {
	RenderFrame(_consoleBuffer);

	RenderString(_consoleBuffer, 33, 15, "TITRE DU JEU", 0x0C);
	RenderString(_consoleBuffer, 15, 57, "1. JOUER", 0x0E);
	RenderString(_consoleBuffer, 15, 60, "Q. QUITTER", 0x0E);

	RenderString(_consoleBuffer, 5, 5, "Highscore: ", 0x0B);

	//static int frames = 0;
	//RenderString(_consoleBuffer, 0, 0, "Frames: " + std::to_string((unsigned int)frames), 0x0B);
	//frames++;
}

void StateMenu::RenderFrame(CHAR_INFO _consoleBuffer[SCREEN_WIDTH][SCREEN_HEIGHT]) {
	const char nbRow = 4;

	for (int i = 0; i < SCREEN_HEIGHT; i++){
		for (int j = 0; j < nbRow; j++){
			_consoleBuffer[i][j].Char.AsciiChar = 'O';
			_consoleBuffer[i][j].Attributes = 0x0A;

			_consoleBuffer[i][SCREEN_WIDTH - 1 - j].Char.AsciiChar = 'O';
			_consoleBuffer[i][SCREEN_WIDTH - 1 - j].Attributes = 0x0A;
		}
	}

	for (int i = nbRow; i < SCREEN_WIDTH - nbRow; i++){
		for (int j = 0; j < nbRow; j++){
			_consoleBuffer[j][i].Char.AsciiChar = '=';
			_consoleBuffer[j][i].Attributes = 0x0A;

			_consoleBuffer[SCREEN_HEIGHT - 1 - j][i].Char.AsciiChar = '=';
			_consoleBuffer[SCREEN_HEIGHT - 1 - j][i].Attributes = 0x0A;
		}
	}
}
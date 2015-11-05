#include "StateMenu.h"

StateMenu::StateMenu() {
	RefreshHighscore();
}

STATES StateMenu::Update(long int time) {
	if (GetAsyncKeyState('1') & BEING_PRESSED)
		return GAME;
	else if (GetAsyncKeyState('Q') & BEING_PRESSED)
		return CLOSE;

	return MENU;
}

void StateMenu::Render(long int time, CHAR_INFO _consoleBuffer[SCREEN_WIDTH][SCREEN_HEIGHT]) {
	RenderFrame(_consoleBuffer);

	RenderString(_consoleBuffer, 22, 15, "SHmUP ENGINE II.5", 0x0C);
	RenderString(_consoleBuffer, 15, 35, "1. JOUER", 0x0E);
	RenderString(_consoleBuffer, 15, 38, "Q. QUITTER", 0x0E);

	RenderString(_consoleBuffer, 5, 5, "Highscore: " + std::to_string(highscore), 0x0B);

	RenderString(_consoleBuffer, 42, 52, "CREDITS: _", 0x0B);

	//static int frames = 0;
	//RenderString(_consoleBuffer, 0, 0, "Frames: " + std::to_string((unsigned int)frames), 0x0B);
	//frames++;
}

/*
	Dessin du cadre entourant la console dans le menu
*/
void StateMenu::RenderFrame(CHAR_INFO _consoleBuffer[SCREEN_WIDTH][SCREEN_HEIGHT]) {
	for (int i = 0; i < SCREEN_HEIGHT; i++){
		for (int j = 0; j < WALLSIZE; j++){
			_consoleBuffer[i][j].Char.AsciiChar = '|';
			_consoleBuffer[i][j].Attributes = 0x0A;

			_consoleBuffer[i][SCREEN_WIDTH - 1 - j].Char.AsciiChar = '|';
			_consoleBuffer[i][SCREEN_WIDTH - 1 - j].Attributes = 0x0A;
		}
	}

	for (int i = WALLSIZE; i < SCREEN_WIDTH - WALLSIZE; i++){
		for (int j = 0; j < WALLSIZE; j++){
			_consoleBuffer[j][i].Char.AsciiChar = '=';
			_consoleBuffer[j][i].Attributes = 0x0A;

			_consoleBuffer[SCREEN_HEIGHT - 1 - j][i].Char.AsciiChar = '=';
			_consoleBuffer[SCREEN_HEIGHT - 1 - j][i].Attributes = 0x0A;
		}
	}
}
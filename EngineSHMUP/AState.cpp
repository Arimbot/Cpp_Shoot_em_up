#include "AState.h"

/*
	Decoupe une std::string pour en faire une chaine affichable sur la console
*/
void AState::RenderString(CHAR_INFO _consoleBuffer[SCREEN_WIDTH][SCREEN_HEIGHT], int _x, int _y, const std::string& _string, int _color) {
	for (int i = 0; i < (int)_string.size(); i++) {
		if (_x >= 0 && _x + i < SCREEN_WIDTH) {
			if (_y >= 0 && _y < SCREEN_HEIGHT) {
				_consoleBuffer[_y][_x + i].Char.AsciiChar = _string[i];
				_consoleBuffer[_y][_x + i].Attributes = _color;
			}
		}
	}
}

void AState::RefreshHighscore(){
	highscore = HighscoreManager::LoadHighscore();
}
#include "StateGame.h"

StateGame::StateGame()
	:
	pause(false),
	swapWalls(0.0f),
	swapWallsSpeed(0.05f)
{
	RefreshHighscore();
	moveWalls.start();
}

STATES StateGame::Update(long int time) {
	STATES state = GAME;

	if (GetAsyncKeyState(VK_ESCAPE) & BEING_PRESSED && !(GetAsyncKeyState(VK_RETURN) & BEING_PRESSED))
		pause = true;
	else if (GetAsyncKeyState(VK_RETURN) & BEING_PRESSED && !(GetAsyncKeyState(VK_ESCAPE) & BEING_PRESSED))
		pause = false;

	/*
		Hors etat de pause, tous les calculs de mouvements doivent etre effectues ici
		*/
	if (pause == false) {
		swapWalls += swapWallsSpeed * time;

		if (swapWalls > 10.0f)
			swapWalls = 0.0f;

		WavesManager::GetInstance()->Update(time);
		EntityManager::GetInstance()->Update(time);

		if (EntityManager::GetInstance()->GetPlayerScore() > highscore)
			highscore = EntityManager::GetInstance()->GetPlayerScore();
	}

	if (EntityManager::GetInstance()->IsEndOfGame())
		state = EndGame();

	return state;
}

STATES StateGame::EndGame(){
	EntityManager::DeleteInstance();
	WavesManager::DeleteInstance();
	HighscoreManager::SaveHighscore(highscore);

	return MENU;
}

void StateGame::Render(long int time, CHAR_INFO _consoleBuffer[SCREEN_WIDTH][SCREEN_HEIGHT]) {
	RenderWalls(_consoleBuffer);

	EntityManager::GetInstance()->DrawEntities(_consoleBuffer);

	RenderString(_consoleBuffer, WALLSIZE + 1, 1, "Highscore: " + std::to_string((int)highscore), 0x0B);
	RenderString(_consoleBuffer, WALLSIZE + 1, 3, "Score: " + std::to_string(EntityManager::GetInstance()->GetPlayerScore()), 0x0F);

	if (pause == true)
		RenderString(_consoleBuffer, 27, 25, "PAUSE", 0x0C);
}

/*
	Dessin des murs sur le cote de la zone de jeu. La position verticale est editee
	a certains moments pour faire une sorte d'animation
*/
void StateGame::RenderWalls(CHAR_INFO _consoleBuffer[SCREEN_WIDTH][SCREEN_HEIGHT]) {
	for (int i = 0; i < SCREEN_HEIGHT; i++){
		for (int j = 0; j < WALLSIZE; j++){
			char character = '\'';

			if (swapWalls >= 0.0f && swapWalls < 5.0f)
				character = '/';

			if (i % 2){
				character = '/';

				if (swapWalls >= 0.0f && swapWalls < 5.0f)
					character = '\'';
			}

			_consoleBuffer[i][j].Char.AsciiChar = character;
			_consoleBuffer[i][j].Attributes = 0x2A;

			_consoleBuffer[i][SCREEN_WIDTH - 1 - j].Char.AsciiChar = character;
			_consoleBuffer[i][SCREEN_WIDTH - 1 - j].Attributes = 0x2A;
		}
	}
}

StateGame::~StateGame(){
	EndGame();
}
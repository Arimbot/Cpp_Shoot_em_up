#include "Engine.h"

Engine* Engine::instance = NULL;

Engine::Engine()
:
running(true)
{
	InitializeView();

	InitializeStates();
}

/*
	Initialise les membres lies a la console
*/
int Engine::InitializeView(){
	dwBufferSize.X = SCREEN_WIDTH;
	dwBufferSize.Y = SCREEN_HEIGHT;

	dwBufferCoord.X = dwBufferCoord.Y = 0;

	rcRegion.Top = rcRegion.Left = 0;
	rcRegion.Bottom = SCREEN_HEIGHT - 1;
	rcRegion.Right = SCREEN_WIDTH - 1;

	hOutput = (HANDLE)GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTitle("SHmUP engine");

	return SetConsoleScreenBufferInfo(dwBufferSize);
}

/*
	Defini la taille de la console
*/

int Engine::SetConsoleScreenBufferInfo(COORD dwSize)
{
	/*
		http://www.developpez.net/forums/d1045378/c-cpp/c/debuter/dimensions-console-sous-windows/
	*/

	HANDLE hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD bakDwSize = dwSize;
	SMALL_RECT srctWindow;
	CONSOLE_SCREEN_BUFFER_INFO csbiInfo;

	// Obtenir les informations de la console
	if (!GetConsoleScreenBufferInfo(hConsoleOutput, &csbiInfo)) return EXIT_FAILURE;

	// Adapter le buffer de la console en fonction des tailles maximales
	dwSize.X = (dwSize.X>csbiInfo.srWindow.Right) ? dwSize.X : csbiInfo.dwSize.X;
	dwSize.Y = (dwSize.Y>csbiInfo.srWindow.Bottom) ? dwSize.Y : csbiInfo.dwSize.Y;
	if (!SetConsoleScreenBufferSize(hConsoleOutput, dwSize)) return EXIT_FAILURE;

	// Modifier la taille de la console
	dwSize = bakDwSize;
	srctWindow = csbiInfo.srWindow;
	srctWindow.Right = dwSize.X - 1;
	srctWindow.Bottom = dwSize.Y - 1;
	if (!SetConsoleWindowInfo(hConsoleOutput, TRUE, &srctWindow)) return EXIT_FAILURE;

	// Adapter la taille du buffer de la console à sa taille (pas d'ascenseurs)
	dwSize = bakDwSize;
	if (!SetConsoleScreenBufferSize(hConsoleOutput, dwSize)) return EXIT_FAILURE;

	return EXIT_SUCCESS;
}

/*
	Cree les etats du moteur, le menu et le jeu
	A initialiser dans l'ordre defini dans l'enum STATES
*/
void Engine::InitializeStates() {
	StateMenu* menu = new StateMenu;
	states.push_back(menu);

	StateGame* game = new StateGame;
	states.push_back(game);

	currentState = MENU;
}

Engine::~Engine() {
	for (int i = 0; i < (int)states.size(); i++){
		if (states[i] != NULL)
			delete states[i];
	}
}

Engine* Engine::GetInstance() {
	if (instance == NULL) {
		instance = new Engine;
	}

	return instance;
}

void Engine::DeleteInstance() {
	if (instance != NULL) {
		delete instance;
		instance = NULL;
	}
}


/*
	Fait un flush de la zone de rendu de la console
*/
void Engine::ClearBuffer(){
	for (int i = 0; i < SCREEN_WIDTH; i++){
		for (int j = 0; j < SCREEN_HEIGHT; j++){
			consoleBuffer[i][j].Char.AsciiChar = ' ';
			consoleBuffer[i][j].Attributes = 0x00;
		}
	}
}

/*
	Rendu du moteur appelant le rendu specifique du mode selectionne
*/
void Engine::Render(long int time) {
	ClearBuffer();

	//Call the selected state Render():
	if (currentState != CLOSE)
		states[currentState]->Render(time, consoleBuffer);

	WriteConsoleOutput(hOutput, (CHAR_INFO *)consoleBuffer, dwBufferSize, dwBufferCoord, &rcRegion);
}

/*
	Evenements du moteur appelant les controles du mode selectionne
*/
void Engine::Update(long int time) {
	//Call the selected state Events() and set the next state
	if (currentState != CLOSE)
		currentState = states[currentState]->Update(time);

	if (currentState == CLOSE)
		running = false;
}
#include "InputManager.h"

InputManager* InputManager::instance = NULL;

void InputManager::GetInputs()
{
	if (GetAsyncKeyState(VK_SPACE) && 0x8000){
		EntityManager::GetInstance()->player->Shoot();
	}
}

InputManager* InputManager::GetInstance() {
	if (instance == NULL)
		instance = new InputManager;

	return instance;
}

void InputManager::DeleteInstance() {
	if (instance != NULL) {
		delete instance;
		instance = NULL;
	}
}

InputManager::InputManager()
{
}


InputManager::~InputManager()
{
}

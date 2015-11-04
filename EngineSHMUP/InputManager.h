#pragma once
#include <windows.h>
#include "EntityManager.h"

class InputManager
{
private:
	static InputManager* instance;
	InputManager();
public:
	void GetInputs();
	InputManager* GetInstance();
	void DeleteInstance();
	
	~InputManager();
};


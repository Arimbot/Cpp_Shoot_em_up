#pragma once

#include <Windows.h>
#include "const.h"

#define ENTITY_SIZE 3

class AEntity
{
public:
	int x;
	int y;
	int moveX;
	int moveY;
	int color;
	char image[ENTITY_SIZE][ENTITY_SIZE];
	
	void Draw(CHAR_INFO _consoleBuffer[SCREEN_WIDTH][SCREEN_HEIGHT]);
	virtual void Move() = 0;

	AEntity();
	~AEntity();
};


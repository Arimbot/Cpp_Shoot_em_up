#pragma once

#include <Windows.h>
#include "const.h"

#define ENTITY_SIZE 3

enum DIRECTION {UP, DOWN, RIGHT, LEFT};

class AEntity
{
public:
	float speed;
	float moveValue;

	DIRECTION direction;

	int x;
	int y;
	int moveX;
	int moveY;
	int color;
	char image[ENTITY_SIZE][ENTITY_SIZE];
	
	void Draw(CHAR_INFO _consoleBuffer[SCREEN_WIDTH][SCREEN_HEIGHT]);
	virtual void Move(long int _time) = 0;

	AEntity();
	~AEntity();
};


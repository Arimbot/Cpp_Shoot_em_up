#pragma once

#include <Windows.h>
#include "const.h"

#define ENTITY_SIZE 3

enum DIRECTION {UP, DOWN, RIGHT, LEFT};

class AEntity
{
public:
	float speed;
	float moveValueH;
	float moveValueV;

	DIRECTION directionH;
	DIRECTION directionV;

	bool isAlive;

	int x;
	int y;
	int moveX;
	int moveY;
	int color;
	char image[ENTITY_SIZE][ENTITY_SIZE];
	
	virtual void Draw(CHAR_INFO _consoleBuffer[SCREEN_WIDTH][SCREEN_HEIGHT]);
	virtual void Update(long int time);

	AEntity();
	~AEntity();
};


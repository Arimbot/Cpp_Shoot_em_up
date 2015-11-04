#include "AEntity.h"

AEntity::AEntity()
{
	speed = 0.0f;
	moveValueH = 0.0f;
	moveValueV = 0.0f;

	x = 0;
	y = 0;
	moveX = 0;
	moveY = 0;

	for (int i = 0; i < ENTITY_SIZE; i++)
		for (int j = 0; j < ENTITY_SIZE; j++)
			image[j][i] = ' ';

	color = 0x00;
}

AEntity::~AEntity()
{
}

void AEntity::Draw(CHAR_INFO _consoleBuffer[SCREEN_WIDTH][SCREEN_HEIGHT]){
	for (int i = 0; i < ENTITY_SIZE; i++){
		for (int j = 0; j < ENTITY_SIZE; j++){
			if (x + i >= 0 && x + i < SCREEN_WIDTH && y + j >= 0 && y + j < SCREEN_HEIGHT){
				_consoleBuffer[y + j][x + i].Char.AsciiChar = image[j][i];
				_consoleBuffer[y + j][x + i].Attributes = color;
			}
		}
	}
}

void AEntity::Move(long int _time){

}
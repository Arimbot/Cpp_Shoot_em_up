#include "Classic.h"


Classic::Classic()
{
	srand((unsigned int)NULL);

	image[0][0] = '/';
	image[1][0] = '\\';
	image[0][1] = '-';
	image[1][2] = '//';
	image[1][1] = 'O';
	image[0][2] = '\\';

	color = 0x0C;

	speed = 0.015f;

	directionH = DOWN;
	directionV = LEFT;

	scoreValue = 100;

	maxValue = 1.0f;
	leftRight = false;
	moveX = 1;
}


Classic::~Classic()
{

}


void Classic::Update(long int time){
	if (isAlive == true){
		moveValueH += speed * time;

		if (moveValueH >= maxValue){
			if (y + 1 >= SCREEN_HEIGHT){
				y = 0;
				if (maxValue == 0.6f)
					leftRight = true;

				maxValue = 0.6f;
			}
			else if (leftRight == false){
				if (rand() % 2 == 0){
					if (rand() % 2 == 0){
						if (x + 3 < SCREEN_WIDTH - WALLSIZE)
							x += 1;
					}
					else{
						if (x - 1 > WALLSIZE)
							x -= 1;
					}
				}
			}
			else{
				if (x + 3 >= SCREEN_WIDTH - WALLSIZE)
					moveX = -1;
				else if (x <= WALLSIZE)
					moveX = 1;

				x += moveX;
			}

			y += 1;

			moveValueH = 0.0f;
		}
	}
}
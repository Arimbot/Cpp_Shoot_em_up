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
}


Classic::~Classic()
{

}


void Classic::Move(long int _time){
	if (alive == true){
		moveValueH += speed * _time;

		if (moveValueH >= 1.0f){
			if (y + 1 >= SCREEN_HEIGHT)
				alive = false;
			else{
				y += 1;

				if (rand() % 4 == 0){
					if (rand() % 2 == 0)
						x += 1;
					else
						x -= 1;
				}
			}

			moveValueH = 0.0f;
		}
	}
}
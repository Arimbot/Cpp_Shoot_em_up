#include "Shot.h"

/*
	Entity that represents the shot of other entities, like enemies and the player
*/
Shot::Shot(){
	image[1][1] = '|';

	color = 0x0B;

	speed = 0.120f;

	directionH = UP;
}


Shot::~Shot(){

}

/*
	Move straight and foward
*/
void Shot::Update(long int time){
	if (isAlive == true){
		moveValueH += speed * time;

		if (moveValueH >= 1.0f){
			if (y - 1 <= 0)
				isAlive = false;
			else
				y -= 1;

			moveValueH = 0.0f;
		}
	}
}
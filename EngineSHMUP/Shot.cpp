#include "Shot.h"


Shot::Shot(){
	image[1][1] = '|';

	color = 0x0B;

	speed = 0.060f;

	directionH = UP;
}


Shot::~Shot(){

}

void Shot::Move(long int _time){
	if (alive == true){
		moveValueH += speed * _time;

		if (moveValueH >= 1.0f){
			if (y - 1 <= 0)
				alive = false;
			else
				y -= 1;

			moveValueH = 0.0f;
		}
	}
}
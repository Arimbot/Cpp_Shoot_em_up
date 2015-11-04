#include "Player.h"

Player::Player(){
	image[1][0] = '<';
	image[0][1] = '^';
	image[1][1] = 'O';
	image[1][2] = '>';
	image[2][1] = '"';

	color = 0x0B;

	speed = 0.06f;

	direction = UP;
}

Player::~Player(){

}

void Player::Move(long int _time){
	/*
	Image:
	[][][]
	[][][]
	[][][]
	*/

	//moveValue += speed * _time;

	if (GetAsyncKeyState(VK_LEFT) && 0x8000){
		if (direction != LEFT && moveValue != 0.0f){
			direction = LEFT;
			moveValue = 0.0f;
		}
		
		moveValue += speed * _time;
	}
	else if (GetAsyncKeyState(VK_RIGHT) && 0x8000){
		if (direction != RIGHT && moveValue != 0.0f){
			direction = RIGHT;
			moveValue = 0.0f;
		}

		moveValue += speed * _time;
	}
	else if (GetAsyncKeyState(VK_UP) && 0x8000){
		if (direction != UP && moveValue != 0.0f){
			direction = UP;
			moveValue = 0.0f;
		}

		moveValue += speed * _time;
	}
	else if (GetAsyncKeyState(VK_DOWN) && 0x8000){
		if (direction != DOWN && moveValue != 0.0f){
			direction = DOWN;
			moveValue = 0.0f;
		}

		moveValue += speed * _time;
	}


	if (moveValue >= 1.0f){
		switch (direction){
		case LEFT:
			if (x > WALLSIZE){
				x -= 1;
			}
			break;
		case UP:
			if (y - 1 > SCREEN_HEIGHT / 2){
				y -= 1;
			}
			break;
		case DOWN:
			if (y + 2 + 1 < SCREEN_HEIGHT - 1){
				y += 1;
			}
			break;
		case RIGHT:
			if (x + 2 + 1 < SCREEN_WIDTH - WALLSIZE){
				x += 1;
			}
			break;
		}

		moveValue = 0.0f;
	}
}
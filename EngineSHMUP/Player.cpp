#include "Player.h"

Player::Player(){
	score = 0;

	image[1][0] = '/';
	image[0][1] = '^';
	image[1][1] = 'O';
	image[1][2] = '\\';
	image[2][1] = '_';

	color = 0x0B;

	speed = 0.060f;

	directionH = UP;
	directionV = LEFT;
}

Player::~Player(){

}

void Player::Move(long int _time){
	if (alive == true){
		////////////horizontaly\\\\\\\\\\\\

		if (GetAsyncKeyState(VK_LEFT) & 0x8000){
			if (directionH != LEFT && moveValueH != 0.0f){
				directionH = LEFT;
				moveValueH = 0.0f;
				moveValueV = 0.0f;
			}

			moveValueH += speed * _time;
		}
		else if (GetAsyncKeyState(VK_RIGHT) & 0x8000){
			if (directionH != RIGHT && moveValueH != 0.0f){
				directionH = RIGHT;
				moveValueH = 0.0f;
				moveValueV = 0.0f;
			}

			moveValueH += speed * _time;
		}

		if (moveValueH >= 1.0f){
			switch (directionH){
			case LEFT:
				if (x > WALLSIZE + 1){
					x -= 1;
				}
				break;
			case RIGHT:
				if (x + 2 + 1 < SCREEN_WIDTH - WALLSIZE - 1){
					x += 1;
				}
				break;
			}

			moveValueH = 0.0f;
		}

		////////////verticaly\\\\\\\\\\\\

		if (GetAsyncKeyState(VK_UP) & 0x8000){
			if (directionV != UP && moveValueV != 0.0f){
				directionV = UP;
				moveValueV = 0.0f;
				moveValueH = 0.0f;
			}

			moveValueV += speed * _time;
		}
		else if (GetAsyncKeyState(VK_DOWN) & 0x8000){
			if (directionV != DOWN && moveValueV != 0.0f){
				directionV = DOWN;
				moveValueV = 0.0f;
				moveValueH = 0.0f;
			}

			moveValueV += speed * _time;
		}

		if (moveValueV >= 1.0f){
			switch (directionV){
			case DOWN:
				if (y + 2 + 1 < SCREEN_HEIGHT - 1){
					y += 1;
				}
				break;
			case UP:
				if (y - 1 > 5){
					y -= 1;
				}
				break;
			}

			moveValueV = 0.0f;
		}
	}
}

// J'ai ajouté d'ici

void Player::Shoot(){
	

}

// à ici


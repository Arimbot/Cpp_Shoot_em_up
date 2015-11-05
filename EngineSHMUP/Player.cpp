#include "Player.h"

Player::Player(){
	score = 0;
	timeFromLastShot = 0.0f;

	image[1][0] = '/';
	image[0][1] = '^';
	image[1][1] = 'O';
	image[1][2] = '\\';
	image[2][1] = '_';

	color = 0x0B;

	speed = 0.060f;
	intervalBetweenShots = 0.003f;

	directionH = UP;
	directionV = LEFT;
}

Player::~Player(){

}

void Player::Draw(CHAR_INFO _consoleBuffer[SCREEN_WIDTH][SCREEN_HEIGHT]){
	AEntity::Draw(_consoleBuffer);
	
	for (auto shot : shots)
		shot->Draw(_consoleBuffer);
}

void Player::Move(long int _time){
	if (alive == true){
		////////////horizontalement\\\\\\\\\\\\

		/*
			Observe le maintien de la touche et annule le deplacement en cours si celle-ci change
		*/
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

		/*
			Applique le deplacement en fonction de la touche qui a ete maintenue
		*/
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

		////////////verticalement\\\\\\\\\\\\

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

void Player::Shoot(long int _time){
	ManageShooting(_time);
	ManageShots(_time);
}

void Player::ManageShooting(long int _time){
	timeFromLastShot += intervalBetweenShots * _time;

	if ((GetAsyncKeyState('A') & 0x8000) && timeFromLastShot > 1.0f){
		Shot* shot = new Shot();
		shot->x = x;
		shot->y = y - 1;
		shots.push_back(shot);
		timeFromLastShot = 0.0f;
	}
}

void Player::ManageShots(long int _time){
	for (std::vector<Shot*>::iterator it = shots.begin(); it != shots.end();){
		(*it)->Move(_time);
		if (!(*it)->alive)
			it = shots.erase(it);
		else
			it++;
	}
}
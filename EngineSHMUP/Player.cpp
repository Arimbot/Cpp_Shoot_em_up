#include "Player.h"

Player::Player(){
	score = 0;
	timeFromLastShot = 0;
	intervalBetweenShots = 200; // in miliseconds

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

void Player::Draw(CHAR_INFO _consoleBuffer[SCREEN_WIDTH][SCREEN_HEIGHT]){
	AEntity::Draw(_consoleBuffer);
	
	for (auto shot : shots)
		shot->Draw(_consoleBuffer);
}

//TODO extract this logic from player and put it in PlayerManager.
void Player::Move(long int time){
	////////////horizontalement\\\\\\\\\\\\

	/*
	Observe le maintien de la touche et annule le deplacement en cours si celle-ci change
	*/
	if (GetAsyncKeyState(VK_LEFT) & BEING_PRESSED){
		if (directionH != LEFT && moveValueH != 0.0f){
			directionH = LEFT;
			moveValueH = 0.0f;
			moveValueV = 0.0f;
		}

		moveValueH += speed * time;
	}
	else if (GetAsyncKeyState(VK_RIGHT) & BEING_PRESSED){
		if (directionH != RIGHT && moveValueH != 0.0f){
			directionH = RIGHT;
			moveValueH = 0.0f;
			moveValueV = 0.0f;
		}

		moveValueH += speed * time;
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

	if (GetAsyncKeyState(VK_UP) & BEING_PRESSED){
		if (directionV != UP && moveValueV != 0.0f){
			directionV = UP;
			moveValueV = 0.0f;
			moveValueH = 0.0f;
		}

		moveValueV += speed * time;
	}
	else if (GetAsyncKeyState(VK_DOWN) & BEING_PRESSED){
		if (directionV != DOWN && moveValueV != 0.0f){
			directionV = DOWN;
			moveValueV = 0.0f;
			moveValueH = 0.0f;
		}

		moveValueV += speed * time;
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

void Player::Update(long int time){
	if (isAlive == true) {
		Move(time);
		ManageShooting(time);
	}

	ManageShots(time);
}

/*
	Verify if the player tried to shoot. If so, create a shot entity and add into the shots collection to be managed.
*/
void Player::ManageShooting( long int time ){
	timeFromLastShot += time; // increment shooting time

	if ((GetAsyncKeyState('A') & BEING_PRESSED) && timeFromLastShot > intervalBetweenShots){
		Shot* shot = new Shot();
		shot->x = x;
		shot->y = y - 1; // create a shot in front of the player
		shots.push_back( shot );
		timeFromLastShot = 0; // reset shooting time
	}
}

/*
	Update shots and remove them if they went off the screen
*/
void Player::ManageShots( long int time ){
	for (std::vector<Shot*>::iterator it = shots.begin(); it != shots.end();){
		(*it)->Update(time);
		
		if (!(*it)->isAlive)
			it = shots.erase(it);
		else
			it++;
	}
}
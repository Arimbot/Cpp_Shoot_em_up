#include "EnemyFactory.h"

/*
	Factory to create the enemies
*/
AEnemy EnemyFactory::CreateEnemy(enemyType_t enemyType) {
	AEnemy enemy;
	
	switch ( enemyType ) {
	case CLASSIC:
		enemy = Classic();
		break;
	case CLASSIC_SHOOTER:
		enemy = ClassicShooter();
		break;
	case BOSS:
		enemy = Boss();
		break;
	}

	return enemy;
}
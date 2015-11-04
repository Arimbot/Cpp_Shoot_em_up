#include "EnemyFactory.h"

/*
	Factory to create the enemies
*/
AEnemy* EnemyFactory::CreateEnemy(enemyType_t enemyType) {
	AEnemy* enemy = NULL;
	
	switch ( enemyType ) {
	case CLASSIC:
		enemy = new Classic();
		break;
	case CLASSIC_SHOOTER:
		enemy = new ClassicShooter();
		break;
	case BOSS:
		enemy = new Boss();
		break;
	}

	return enemy;
}
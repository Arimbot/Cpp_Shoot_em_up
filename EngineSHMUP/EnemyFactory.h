#pragma once
#include "AEnemy.h" 
#include "enemyType_t.h"
#include "Boss.h"
#include "Classic.h"
#include "ClassicShooter.h"

static class EnemyFactory
{
public:
	static AEnemy CreateEnemy(enemyType_t enemyType);
};


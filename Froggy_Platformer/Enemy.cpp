#include "stdafx.h"
#include "Enemy.h"
Enemy::Enemy() {
	HP = ENEMY_HP;
	ATTACK = ENEMY_ATTACK;
	SPEED = ENEMY_SPEED;
	JUMP = 0;
	random_crit = 1;
}
double Enemy::get_random() {
	srand(time(NULL));
	random_crit = (rand() % 200 + 100) / 100; 
	return random_crit; 
}
void Enemy::set_ATTACK(double random_crit, int yes) {
	// yes == 1 means to multiply the ATTACK value with random_crit. yes == 0 means to reset ATTACK to default
	if(yes == 1)
		ATTACK *= random_crit;
	else 
		ATTACK = ENEMY_ATTACK;
}
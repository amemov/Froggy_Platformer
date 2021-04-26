#include "stdafx.h"
#include "Enemy.h"
Enemy::Enemy() {
	HP = ENEMY_HP;
	ATTACK = ENEMY_ATTACK;
	SPEED = ENEMY_SPEED;
	JUMP = 0;
	random_crit = 1;
}
void Enemy::set_random() {
	srand(time(NULL));
	random_crit = (rand() % 200 + 100) / 100; 
}
void Enemy::set_ATTACK(int yes) {
	// yes == 1 means to multiply the ATTACK value with random_crit. yes == 0 means to reset ATTACK to default
	if (yes == 1)
	{
		set_random();
		ATTACK *= random_crit;
	}	 
	else 
		ATTACK = ENEMY_ATTACK;
}
void Enemy::set_HP(int HP) {
	this->HP += HP;
}
void Enemy::set_SPEED(int SPEED) {
	this->SPEED = SPEED;
}
void Enemy::set_JUMP(int JUMP) {
	this->JUMP = JUMP;
}
#include "stdafx.h"
#include "Player.h"
Player::Player() {
	HP = PLAYER_HP;
	ATTACK = PLAYER_ATTACK;
	SPEED = PLAYER_SPEED;
	JUMP = PLAYER_JUMP;
	X = 3;
	Y = 3;
}
void Player::set_HP(int HP) {
	this->HP = HP;
}
void Player::set_ATTACK(int ATTACK) {
	this->ATTACK = ATTACK;
}
void Player::set_SPEED(int SPEED) {
	this->SPEED = SPEED;
}
void Player::set_JUMP(int JUMP) {
	this->JUMP = JUMP;
}
void Player::draw() {

	init_pair(2,COLOR_BLUE,COLOR_RED);
	std::cout << (char)PLAYER;
}

Player& operator+(Player& what, Item t) {
	what.Inventory.push_back(t);
	return what;
}
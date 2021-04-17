// Written by Anton Shepelev, University of South Florida Computer Science Student.  
// Establishes Enemy class
/* get_random() - Generates a number from 100 to 200. After that it is converted to percents ( 1 <= random crit <= 2 ) */
/* set_ATTACK() - Updates attack value, depending on yes parameter. If yes == 1, then current ATTACK value is multiplied by random_crit. If yes == 0, ATTACK resets to default */
#ifndef ENEMY_H
#define ENEMY_H
#include "Character.h"
class Enemy: public Character {
	private: 
		double random_crit;
	public:
		Enemy();
		double get_random();
		void set_ATTACK(double random_crit, int yes);
};
#endif
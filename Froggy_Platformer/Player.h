// Written by Anton Shepelev, University of South Florida Computer Science Student.  
// Establishes Player class
#ifndef PLAYER_H
#define PLAYER_H
#include "Item.h"
#include "Character.h"
class Player: public Character {
	private: 
		//std::vector <Item> Inventory;
	public:
		std::vector <Item> Inventory;
		Player();
		void set_HP(int HP);
		void set_ATTACK(int ATTACK);
		void set_SPEED(int SPEED);
		void set_JUMP(int JUMP);
		void draw();
	
		friend Player& operator + (Player& what, Item t); // !!!!!!!!!!!!!!!!!!!!!! - seems resolved //

};
#endif
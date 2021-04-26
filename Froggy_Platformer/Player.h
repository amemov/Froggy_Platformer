// Written by Anton Shepelev, University of South Florida Computer Science Student.  
// Establishes Player class
#ifndef PLAYER_H
#define PLAYER_H
#include "Item.h"
#include "Character.h"
class Player: public Character {
	private: 
		int inventory_count;
	public:
		std::vector <Item> Inventory;
		Player();
		
		void set_HP(int HP);
		void set_ATTACK(int ATTACK);
		void set_SPEED(int SPEED);
		void set_JUMP(int JUMP);

		friend Player& operator += (Player& what, Item t);  
		int get_inv_count() { return inventory_count; };
		void set_inv_count(int count);
		void print_inventory();
		void use_inventory();
		void save_inv();
		
		//void draw();

};
#endif
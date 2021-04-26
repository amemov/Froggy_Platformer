// Written by Anton Shepelev, University of South Florida Computer Science Student.  
// Establishes Character class
#ifndef CHARACTER_H
#define CHARACTER_H
class Character {
	public:
		// Character attributes
		int HP = 0;
		int SPEED = 0;
		int ATTACK = 0;
		int X = 0;
		int Y = 0;
		int JUMP = 0;

	 
		//Character(int HP, int ATTACK, int SPEED, int JUMP);
		// Getters
		int get_HP() { return HP; };
		int get_SPEED() { return SPEED; };
		int get_ATTACK() { return ATTACK; };
		int get_x() { return X; };
		int get_y() { return Y; };
		
		// Pure Virtual Setters. Children must override 
		virtual void set_HP(int HP) = 0;
		virtual void set_SPEED(int SPEED) = 0;
		virtual void set_ATTACK(int ATTACK) = 0;
		virtual void set_JUMP(int JUMP) = 0;

};
#endif

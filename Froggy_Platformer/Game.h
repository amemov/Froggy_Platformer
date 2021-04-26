// Written by Anton Shepelev, University of South Florida Computer Science Student.  
// Establishes Game class
/*	start() - starts the game 
 	save()  - saves the game by creating a txt file that contains data for configuring game level ( lelvel number )
	load()  - loads the game by reading a txt file 
	about() - prints information about the game
	exit() - prints exit statement

	initialize_inv() - activates if save() is called. Reads data from Inventory.txt and adds that information in the Player's inventory
	 
	update_name() - updates level name based on current level_count ( level number ). Searches the name in Level_Info.txt
	
	level() - initializes a level. Searches for correct level based on current level_count
	boss_fight() - function that triggers fighgt with a boss ( occurs after the level reached the its end ) */
#ifndef GAME_H
#define GAME_H
#include "Player.h"
#include "Enemy.h"
class Game {
	private: 
		Player player; Enemy enemy;  
		std::string level_name = " ";
		int level_count = 10;
		static int enemies;
	public:
		// Level associated functions
		void update_name();
		void update_count() { level_count += 1; };
		int get_count() { return level_count; };
		static void enemy_counter(int plus) { if (plus == 1) enemies = 1; else enemies = 0; };

		// Game functions
		void start();
		void save();
		void load();
		void about();
		void exit();
		void initialize_inv();
		 

		// Level + Stages
		void level();
		int boss_fight();
};
#endif
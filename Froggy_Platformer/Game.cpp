#include "stdafx.h"
#include "Game.h"
void Game::start() {
	// Reset player's Inventory file
	std::ofstream inventor;
	inventor.open("Inventory.txt", std::ofstream::out | std::ofstream::trunc);
	inventor.close();

	// Start new game
	level_count = def_lvl;
	level();
}
void Game::save() {
	// Open save file - save Level specifications. Open Inventory file - save current stat of the player and the inventory
	std::ofstream save;  
	save.open("Save.txt");
	save << level_count << level_name;
	save.close();

	player.save_inv();
}
void Game::load() {
	// Open save file - load Level specifications, using setter functions. 
	std::ifstream save; std::string lvl_name, line; int lvl_count;
	save.open("Save.txt");
	while (std::getline(save, line))
	{
		std::stringstream ss(line);
		ss >> lvl_name >> lvl_count;
		level_name = lvl_name;
		level_count = lvl_count;
		save.close();
	}

	// Open Inventory file - update Player's specs, using setter functions, and write information in the Inventory vector
	initialize_inv();

	// Load current level
	level();

}
void Game::about() {
	std::cout << "\n\n \t\t\t ABOUT \n";
	std::this_thread::sleep_until(std::chrono::system_clock::now() + std::chrono::seconds(1));
	std::cout << "\n \t\t\t Hi! My name is Anton and this is my game about a Froggy.\n" <<
		"Froggy lives in a pond like any hard-working frogg. He got injured and because of that his temporarily blind.\n" <<
		"This game is a demo version of future game that I would like to release in future - which will be done Unity, using 2D pixel-art.\n" <<
		"Even though it's a very short 'game', I hope you enjoy it and might learn something from the code that was written to implement it. Thank you! \n\n\n";
}
void Game::exit() {
	std::cout << "\n \t\t\t Thank you! Check github.com/amemov for future updates! \n\n";
}

void Game::update_name() {
	// Open txt file. Based on level count, finds appropriate line with level name
	std::ifstream level_file; std::string line; int what_level_need;
	int control = 0;
	level_file.open("Level_Info.txt");

	// Search for correct line
	while (std::getline(level_file, line))
	{
		std::stringstream ss(line);
		// Look for needed level number. If found, increment control variable 
		if (ss >> what_level_need)
			control++;

		// Write new name for the level
		if (control == 1)
			level_name = ss.str();
	}

	// Close file
	level_file.close();
}
void Game::initialize_inv() {
	// Open inventory file. Read data from file and write in vector
	// Open txt file. Based on level count, finds appropriate line with level name
	std::ifstream inv_file; std::string line; int temp_counter = 0;
	inv_file.open("Inventory.txt");
	while (std::getline(inv_file, line))
	{
		std::stringstream ss(line);
		std::string name; int what_stat, impact;

		// Copy contnents for the Item object
		ss >> name >> what_stat >> impact;

		// Create an item object and add it to Inventory vector
		Item object(name, what_stat, impact);
		player += object;
		temp_counter++;
	}
	player.set_inv_count(temp_counter);

	inv_file.close();
}
void Game::level() {
	// Open txt file. Based on level count, finds appropriate line with level name
	std::ifstream level_file; std::string line; int what_level_need;
	int control = 0; int selection;
	level_file.open("Level_Info.txt");

	// Search for correct line
	while (std::getline(level_file, line))
	{ 
		std::stringstream ss(line);

		// Correct level found
		if (ss >> what_level_need)
		{
			if(what_level_need == level_count)
				control = 1;
		}

		// Extract lines for this level
		if (control == 1)
		{
			while (std::getline(level_file, line))
			{
				std::stringstream ss(line);

				 

				// Check if next line is an Item information!
				if (ss.str().at(0) == 'C' || ss.str().at(0) == 'S' || ss.str().at(0) == 'P' || ss.str().at(0) == 'E')
				{					 

					// Extract information about an item 
					std::string item_name; int impact;  int stat;
					ss >> item_name >> impact >> stat;
					
					// Check if an item impacts ATTACK or SPEED. if so, just alter characteristics
					if (impact == 2 || impact == 3)
					{
						if (impact == 2)
							player.set_ATTACK(stat);
						else
							player.set_SPEED(stat);
					}
					else
					{
						// Is inventory full?
						if (player.get_inv_count() == 4) {
							std::cout << "\nYour inventory is full!\n";
							break;
						}

						// Create an object
						Item object(item_name, impact, stat);

						// Add it to the inventory
						player += object;
						player.set_inv_count(1);
					}
					// Go to next line 
					continue;
				}
					 
				// New level reached?
				if (ss >> what_level_need) {
					control = -1;
					break;
				}
				
				// Story text with selection
				if (ss.str().at(0) == '.')
				{
					/* Skip first character */
					//ss.ignore(line.length(), '.');
					ss.str().at(0) = 0;

					// Print with delay
					std::cout << ss.str() << "\n";
					std::this_thread::sleep_until(std::chrono::system_clock::now() + std::chrono::seconds(2));

					std::cout << "What would you do ( type 1 or 2 ): ";
					std::cin >> selection;
					std::cin.ignore(1000, '\n');
					while (std::cin.fail() || selection<1 || selection>2 )
					{
						std::cin.clear();
						std::cout << "ERROR. What would you do ( type 1 or 2 ): ";
						std::cin >> selection;
						std::cin.ignore(1000, '\n');
					}

					// Process Selection! And reset it back to 0
					while (selection == 1)
					{
						std::getline(level_file, line);
						std::stringstream ss(line);
						if (ss.str().at(0) == '1')
						{
							/* Skip first character */
							ss.ignore(line.length(), '1');
							std::cout << ss.str() << "\n";
							selection = 0;
							std::getline(level_file, line);
							std::stringstream ss(line);
						}			  
						 
					}
					while (selection == 2)
					{
						std::getline(level_file, line);
						std::stringstream ss(line);
						if (ss.str().at(0) == '2')
						{
							/* Skip first character */
							ss.ignore(line.length(), '1');
							std::cout << ss.str() << "\n";
							selection = 0;
						}
					}
				}

				 
				 
				// Just a story text
				else {
					// Print with delay
					std::cout << ss.str() << "\n";
					std::this_thread::sleep_until(std::chrono::system_clock::now() + std::chrono::seconds(2));
				}
			}
			 
		}

		if (control == -1)
			break;
	}
	// Close level file
	level_file.close();

	//	Boss fight.
	std::this_thread::sleep_until(std::chrono::system_clock::now() + std::chrono::seconds(2));
	std::cout << std::setw(10) << "\n\t\t\tBOSS FIGHT\n";
	int check = boss_fight();
	// Failed battle
	if (check == 1)
	{
		std::this_thread::sleep_until(std::chrono::system_clock::now() + std::chrono::seconds(2));
		std::cout << std::setw(10) << "\nGAME OVER\n";
	}
	// Successful battle
	else{
		// Save the progress or no?
		char yes_no;
		std::cout << "\nCongratulations! You have reached the end of the demo! Would you like to save your progress(y/n)? - ";
		std::cin >> yes_no;
		std::cin.ignore(1000, '\n');
		while (std::cin.fail() || (yes_no != 'y' && yes_no != 'n'))
		{
			std::cin.clear();
			std::cout << "\nERROR. You have reached the end of the demo! Would you like to save your progress(y/n)? - ";
			std::cin >> yes_no;
			std::cin.ignore(1000, '\n');
		}
		// Proccess input
		if (yes_no == 'y')
		{
			level_count += 10;
			update_name();
			save();
		}
 
		 
	}

}
int Game::boss_fight() {
 
	while (enemy.get_HP() > 0)
	{
		// Check if player is dead
		if (player.get_HP() < 0)
		{
			std::cout << "\t\t\t You are in a better place now";
			return 1;
		}



		int select = 0;
		// Show current stat
		std::cout << "Player HP: " << player.get_HP() << "\t\tPlayer ATTACK: " << player.get_ATTACK() << "\t\tPlayer Speed: " << player.get_SPEED() << "\n";
		std::cout << "Enemy HP: " << enemy.get_HP() << "\t\tEnemy ATTACK: " << enemy.get_ATTACK() << "\t\tEnemy Speed: " << enemy.get_SPEED() << "\n";
		std::this_thread::sleep_until(std::chrono::system_clock::now() + std::chrono::seconds(1));

		// Provide options 
		std::cout << "\nWhat to do? (1) Attack, (2) Open Inventory, (3) Use inventory: ";
		std::cin >> select;
		std::cin.ignore(1000, '\n');
		while (std::cin.fail() || select > 3 || select < 1)
		{
			std::cin.clear();
			std::cout << "\n \t\tERROR. What to do? (1) Attack, (2) Open Inventory, (3) Use inventory: ";
			std::cin >> select;
			std::cin.ignore(1000, '\n');
		}
		
		// Process selection
		switch (select) 
		{
			case 1: enemy.set_HP(-player.get_ATTACK()); break;
			case 2: player.print_inventory(); break;
			case 3: player.use_inventory(); break;
		}
		if (select == 2)
			continue;

		// Enemy starts attacking. Initialize crit damage
		enemy.set_random(); int deal_crit_or_not = rand() % 2;
		if(deal_crit_or_not == 0) // No crit
		{
			enemy.set_ATTACK(0);
			std::cout << "Enemy dealt " << enemy.get_ATTACK() << " to you!\n\n";
			player.set_HP(-enemy.get_ATTACK());
		}
		if (deal_crit_or_not == 1) // Crit damage
		{
			enemy.set_ATTACK(1);
			std::cout << "\t\t\t CRIT DAMAGE	\n";
			std::cout << "Enemy dealt " << enemy.get_ATTACK() << " to you!\n\n";
			player.set_HP(-enemy.get_ATTACK());

		}
	}
	std::this_thread::sleep_until(std::chrono::system_clock::now() + std::chrono::seconds(1));
	std::cout << "\t\t\tYou won the battle. And only time will tell what will happen next.\n";
 
	return 0;
}
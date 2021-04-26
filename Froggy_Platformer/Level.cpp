#include "stdafx.h"
#include "Level.h"
Level::Level() {
	level_name = " ";
	level_count = 1;
}
void Level::update_name() {
	// Open txt file. Based on level count, finds appropriate line with level name
	std::ifstream level_file; std::string line; int what_level_need = level_count * 10;
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
void Level::update_count() {
	level_count += 1;
}
void Level::level_one() {
	// Open txt file. Based on level count, finds appropriate line with level name
	std::ifstream level_file; std::string line; int what_level_need = level_count * 10;
	int control = 0; int selection;
	level_file.open("Level_Info.txt");
	
	// Search for correct line
	while (std::getline(level_file, line))
	{
		std::stringstream ss(line);

		// Correct level found
		if (ss >> what_level_need)
			control++;

		// Extract lines for this level
		while (control == 1)
		{
			// Story text with selection
			if (ss.str().at(0) == '.')
			{
				std::cout << ss.str() << "\n";
				std::cout << "What would you do ( type 1 or 2 ): ";
				std::cin >> selection;
				std::cin.ignore(1000, '\n');
				while (std::cin.fail())
				{
					std::cin.clear();
					std::cout << "ERROR. What would you do ( type 1 or 2 ): ";
					std::cin >> selection;
					std::cin.ignore(1000, '\n');
				}
			} 
			// Just a story text
			else {

			}
			

		}
		
		if (control == -1)
			break;
	}

	// Correct line is found
}
#include "stdafx.h"
#include "Game.h"
// Written by Anton Shepelev, University of South Florida Computer Science Student.  
// Main file of the Froggy The Game
void ClearScreen()
{
    for (int n = 0; n < 10; n++)
        std::cout << "\n\n\n\n\n\n\n\n\n\n";
}
int main()
{
    
    // Main Menu of the game. Should show: the name of the game, NEW GAME, LOAD GAME, and About
     /*After selecting an option, the window should be cleared and input should be processed with clean screen*/
    Game game; int option = 0;
    while (option != 4)
    {
        std::cout << "\t\t\tFroggy The Game\n\n";
        std::cout << "\t\t1. START NEW GAME\n";
        std::cout << "\t\t2. LOAD GAME\n";
        std::cout << "\t\t3. ABOUT\n";
        std::cout << "\t\t4. EXIT\n\n";
        std::cout << "---------------------------------------\n";
        
        std::cout << "OPTION(1-4): ";
        std::cin >> option;
        while (std::cin.fail() || option > 4 || option < 1)
        {
            std::cin.clear();
            std::cout << "\nERROR.OPTION(1 - 4): ";
            std::cin >> option;
            std::cin.ignore(1000, '\n');
        }

        switch (option)
        {
        case 1: ClearScreen(); game.start(); break;
        case 2: ClearScreen(); game.load();  break;
        case 3: game.about(); break;
        case 4: game.exit(); break;
        }
    }
      
    return 0;
     
}
 
#include "stdafx.h"
#include "Player.h"
// Written by Anton Shepelev, University of South Florida Computer Science Student.  
// Main file of the Froggy Platformer game. 

/*Set Text Color Function*/
void set_Color() {

}
int main()
{
    Player player;
    player.draw();
	
	// Essentials
	WINDOW* win = newwin(30, 30, 5, 10);
	initscr();
	cbreak();
	noecho();
	scrollok(win, TRUE);
	nodelay(win, TRUE);

    do {
        // _kbhit function checks the console for a recent keystroke.
			//int key = getch();
			//if (key == KEY_ESCAPE) exit = true;

			///if (player.getDelay() == 0)
			//{

				//if (!key || key == 0xe0)
				int key = getch();
				int refresh(void); 
				int wrefresh(WINDOW * win);

				switch (key)
				{
				case KEY_LEFT:	wmove(win, 3, 3); player.draw(); break;
				//case KEY_RIGHT: player.wmove(RIGHT); break;
				//case KEY_UP:	player.wmove(UP); break;
				//case KEY_DOWN:	player.wmove(DOWN); break;
				//case KEY_RETURN: game.restart(); break;
				}
			//}

        //}
    } while (true); /* change to if HP is zero or exit is executed */
     
}
 
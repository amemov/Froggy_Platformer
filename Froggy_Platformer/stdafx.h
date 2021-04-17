// Written by Anton Shepelev, University of South Florida Computer Science Student.  
// 'Precompiled Header' File
#ifndef STDAFX_H
#define STDAFX_H

	// :0
		#include <SDKDDKVer.h>  /* 'support' for different windows versions*/
		//#include <conio.h>		/* 'responsible' for moving player object */
		#include <iostream>
		#include <curses.h>	
		//#include <windows.h>
		#include <vector>
		#include <string>
		#include <stdlib.h>     /* srand, rand */
		#include <time.h>		/* time */

	// Map size boundries	
		const int MAX_X = 30;
		const int MAX_Y = 30;
	
	// Map, Characters, Items, and User Interface (UI) blocks ( ASCII numbers )
	/*UI.	EDGE_TL = Edge Top Left */
		#define BOUNDRY_SIDE_UI 179		 
		#define BOUNDRY_TOPBOTTOM_UI 196   
		#define BOUNDRY_EDGE_TL_UI 218	 
		#define BOUNDRY_EDGE_TR_UI 191	 
		#define BOUNDRY_EDGE_BL_UI 192	 
		#define BOUNDRY_EDGE_BR_UI 217	 
	/*Map*/
		#define BIG_BLOCK 219  // bottom Rocks?
		#define HALF_BLOCK 220 // bottom Grass?
		#define CLEAN 32	   // empty block
	/*Characters*/
		#define PLAYER 2 
		#define ENEMY 224
	/*Items*/
		#define CHOKY_MILK 4   // makes pain go away
		#define HEALTH_BAR 3   // adds hp
		#define POISON 10	   // decreases hp
	
	//Default Stats for Characters//
	/*Player*/
		#define PLAYER_ATTACK 20
		#define PLAYER_HP 180
		#define PLAYER_JUMP 2
		#define PLAYER_SPEED 2
	/*Enemy*/
		#define ENEMY_ATTACK 30
		#define ENEMY_HP 200
		#define ENEMY_SPEED 1
	
	//Key definitions//
	/*For switches and if statements*/
		#define UP	  10000
		#define DOWN  10001
		#define RIGHT 10002
		#define LEFT  10003
	/*Actual keys*/
	/*	const int KEY_UP = 0x48;
		const int KEY_DOWN = 0x50;
		const int KEY_LEFT = 0x4b;
		const int KEY_RIGHT = 0x4d;
		const int KEY_ESCAPE = 0x1b;
		const int KEY_RETURN = 0x0d;*/
	// rewrite!!!!!!!!!!!!!!!!!!!!!!!!!!!	
		enum color
		{
			black,
			darkblue,
			darkgreen,
			darkcyan,
			darkred,
			darkpurple,
			darkgray,
			darkwhite,
			gray,
			blue,
			green,
			cyan,
			red,
			purple,
			yellow,
			white
		};
#endif
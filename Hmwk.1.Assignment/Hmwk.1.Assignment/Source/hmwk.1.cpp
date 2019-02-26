/*
* Author:	Keith Bush
*			UALR
* 
* Date:		November 28, 2014	
*
* File:		hmwk.1.cpp
*
* Purpose:	The purpose of this homework is to review Programming I topics covering
*           file input/output, header/object files, random number generation seeding and
*           usage, as well as linking with the SDL graphics libraries
*/

#include <cstdlib> 
#include <ctime> 
#include <string>
#include <iostream>
#include <random>

//Task 1: Install Libaries and Get the GUI Running
#include "gui.h"

#include "engine.h"
#include "constants.h"

using namespace std;

int main(int argc, char *argv[]){

	//Task 2: Seed random number generator
	srand((unsigned)time(0));


	//Declare  Link Properties*/
	int linkPosX = 0;
	int linkPosY = 0;
	int linkSpriteID = 0;

	// Declare Zelda2 Properties
	int numBlocks=0;                     //Number of blocks to render
	const int MAX_NUM_BLOCKS = 600;      //Maximum possible blocks
	int blockPosX[MAX_NUM_BLOCKS];       //Array of X positions (as pixels)
	int blockPosY[MAX_NUM_BLOCKS];       //Array of Y positions (as pixels)
	bool blockTop[MAX_NUM_BLOCKS];       //Array of booleans (on top or not?)

	//Initialize the game's data source
	string gameFile("./Assets/Config/game.txt");

	//Task 3: Load block structure from a file
	
	loadBlockData(gameFile, numBlocks, blockPosX, blockPosY, blockTop);

	//Task 4: Randomize Link Sprite Appearance
	
	randomZelda2Data(linkPosX,linkPosY,linkSpriteID,numBlocks, blockPosX, blockPosY, blockTop);

	//Construct GUI
	GUI gui;

	//Initialize Termination Criteria
	bool quit = false;
	
	//While the user hasn't quit
	while(quit == false){
		
		//GUI waits for mouse events
		while(gui.observeEvent()){

			//GUI transmits quit event
			if(gui.quitGame()){

				quit=true;

			}

		}

		//Task 5: Pass Game State Data to the GUI
		gui.displayGameState(linkPosX,linkPosY,linkSpriteID,numBlocks,blockPosX,blockPosY,blockTop);
	}

	//Return
	return 0;

}
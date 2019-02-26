/*
* Author:	Keith Bush
*			UALR
*
* Date:		December 1, 2014
*
* File:		hmwk.3.cpp
*
* Purpose:	The purpose of this homework is to illustrate the use of objects in
*           abstracting and simplifying game implementation*/

#include <fstream>
#include <cstdlib> 
#include <ctime> 
#include <string>
#include <iostream>

//Game Architecture Types and Headers
#include "GUI.h"
#include "Timer.h"
#include "engine.h"
#include "constants.h"

//Game Specific Types
#include "Link.h"
#include "Block.h"

using namespace std;

int main(int argc, char *argv[]) {


	//Initialize GUI->Engine communication*/
	LK_TRANSITION command = NA;

	//Construct Timer
	Timer fps;

	//Construct GUI
	GUI gui;

	//Construct link
	Link* link = new Link;

	//Construct Blocks
	int numBlocks = 0;
	Block** blocks = constructBlocks("./Assets/Config/level.txt", numBlocks);

	//Initialize Termination Criteria
	bool quit = false;


	//While the user hasn't quit
	while (quit == false) {

		//Start the frame timer
		fps.start();

		//GUI waits for mouse events
		while (gui.observeEvent()) {

			//Receive Command From GUI
			command = gui.getCommand();

			//GUI transmits quit event
			if (gui.quitGame()) {

				quit = true;

			}

		}

		//Task 3: Update Game state
		changeGameState(command, link, blocks, numBlocks);

		//Render Game Data
		gui.displayGameState(link, blocks, numBlocks);

		//Adjust Frame Rate
		if (fps.get_ticks() < FRAME_DELAY) {
			SDL_Delay(FRAME_DELAY - fps.get_ticks());
		}

	}

	//Return
	return 0;

}
/*
* Author:	Sean Orme
*			UALR
*
* Date:		February 17, 2016
*
* File:		hmwk.2.cpp
*
* Purpose:	The purpose of this homework is to illustrate pointers, dynamic memory
*           allocation, handling user inputs (as part of the GUI/Engine design
*           pattern and 2D animation (including the use of frame timers).*/

#include <fstream>
#include <cstdlib> 
#include <ctime> 
#include <string>
#include <iostream>

#include "gui.h"
#include "engine.h"
#include "constants.h"
#include "timer.h"

using namespace std;

int main(int argc, char *argv[])
{
	//Seed random number generator
	srand((unsigned)time(0));

	//Declare  link Properties
	int linkPosX = 0;
	int linkPosY = 0;
	LK_STATE linkState = STILL_RIGHT;
	int linkAnimID = 0;
	int linkSpriteID = 0;

	int numStates;
	int* animationSize;
	int** animationMap;

	//Initialize GUI->Engine communication*/
	LK_TRANSITION command = NA;

	//Initialize the game's data source
	string gameFile("./Assets/Config/animation.txt");

	//Task 1: Load block structure from a file
	loadAnimationMap(gameFile, numStates, animationSize, animationMap); //Uncomment after implentation

	//Task 2: Place link in the bottom leftRandomize link Sprite Appearance
	initLinkData(linkPosX, linkPosY, linkState, linkAnimID, animationMap, linkSpriteID);//Uncomment after implentation

	//Construct Timer
	Timer fps;

	//Construct GUI
	GUI gui;

	//Initialize Termination Criteria
	bool quit = false;

	//While the user hasn't quit
	while (quit == false)
	{
		//Start the frame timer
		fps.start();

		//GUI waits for mouse events
		if (gui.observeEvent())
		{
			//Receive Command From GUI
			command = gui.getCommand();

			//GUI transmits quit event
			if (gui.quitGame())
			{
				quit = true;
			}
		}

		//Task 3: Update Game state
		changeGameState(command, linkPosX, linkPosY, linkState, linkAnimID, animationSize, animationMap, linkSpriteID);//Uncomment after implentation

		//Render Game Data
		gui.displayGameState(linkPosX, linkPosY, linkSpriteID);

		//Adjust Frame Rate
		if (fps.get_ticks() < FRAME_DELAY)
		{
			SDL_Delay(FRAME_DELAY - fps.get_ticks());
		}
	}

	//Return
	return 0;

}
/*
* Author:	Keith Bush
*			UALR
* 
* Date:		December 2, 2014	
*
* File:		hmwk.4.cpp
*
* Purpose:	The purpose of this homework is to illustrate the use of objects in
*           abstracting and simplifying game implementation*/

//System Headers
#include <fstream>
#include <cstdlib> 
#include <ctime> 
#include <string>
#include <iostream>

//GUI Headers
#include "GUI.h"
#include "Timer.h"

//Game Headers
#include "Engine.h"
#include "constants.h"

using namespace std;

extern "C" {FILE __iob_func[3] = { *stdin,*stdout,*stderr };}

int main(int argc, char *argv[]){

	//Initialize GUI->Engine communication
	LK_TRANSITION command = NA;

	//Construct Timer
	Timer fps;
	
	//Construct GUI
	GUI gui;

	//Construct Engine
	Engine engine;

	//Initialize Termination Criteria
	bool quit = false;
	
	//While the user hasn't quit
	while(quit == false){

		//Start the frame timer
		fps.start();
		
		//GUI waits for mouse events
		while(gui.observeEvent()){

			//Receive Command From GUI
			command = gui.getCommand();

			//GUI transmits quit event
			if(gui.quitGame()){

				quit=true;

			}
		}

		//Update Game state
		engine.changeGameState(command);

		//Render Game Data
		gui.displayGameState(engine); 

		//Adjust Frame Rate
		if(fps.get_ticks() < FRAME_DELAY){
			SDL_Delay( FRAME_DELAY - fps.get_ticks() );
		}

	}

	//Return
	return 0;

}
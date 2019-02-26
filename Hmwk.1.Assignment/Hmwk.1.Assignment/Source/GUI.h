#ifndef GUI_H
#define GUI_H

#include <string>

//GUI definitions
#include "SDL.h"
#include "SDL_image.h"
#include "SDL_ttf.h"

//User-defined tools
#include "Texture.h"
#include "constants.h"

using namespace std;

class GUI
{

public:
	GUI();
	~GUI();
	int observeEvent();
	bool quitGame();
	void displayGameState(int, int, int, int, int [], int [], bool []);

private:

	//
	// PRIVATE METHODS
	//
	void initGUI();
	void loadMedia();
	void cleanUp();

	//
	//PRIVATE MEMBERS
	//
	bool quit;

	//Window(s) to display graphics
	SDL_Window* window;

	//Hardware accelerated renderer
	SDL_Renderer* renderer;

	//The texture and clipping that will be used for link
	Texture* zelda2SheetTexture;
	SDL_Rect zelda2Clips[Z2_NUM_SPRITES];
	
	//The texture to be used for the blocks
	Texture* blockSheetTexture;
	Texture* topBlockSheetTexture;

	//The event structure that will be used
	SDL_Event event;

};

#endif

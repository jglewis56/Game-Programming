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

//Game specific types
#include "Block.h"
#include "Link.h"

using namespace std;

class GUI {

public:
	GUI();
	~GUI();
	int observeEvent();
	LK_TRANSITION getCommand();
	bool quitGame();
	void displayGameState(Link*, Block**, int);

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

	bool attack;

	//Window(s) to display graphics
	SDL_Window* window;

	//Hardware accelerated renderer
	SDL_Renderer* renderer;

	//The texture and clipping that will be used for megaman
	Texture* linkSheetTexture;
	SDL_Rect linkClips[LK_NUM_SPRITES];

	//The texture to be used for the block
	Texture* blockSheetTexture;

	//The texture to be used for the text
	TTF_Font* normalFont;

	//The event structure that will be used
	SDL_Event event;

	//Maintain last player command given
	LK_TRANSITION command;

};



#endif

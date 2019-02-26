#include <iostream>
#include <fstream>
#include <string>

#include "GUI.h"
#include "Texture.h"
#include "constants.h"

using namespace std;

GUI::GUI(){

	//Initialize the window
	window = NULL;

    //Initialize the renderer

	//Images surfaces used in GUI
	zelda2SheetTexture = NULL;
    blockSheetTexture = NULL;
	topBlockSheetTexture = NULL;

	//Start-up the GUI!
	initGUI();

	//Load in all the images and clip (if necessary)
	loadMedia();

	//Exit criteria
	quit=false;

}

GUI::~GUI(){
	cleanUp();
}

int GUI::observeEvent(){
	return(SDL_PollEvent( &event ));
}

bool GUI::quitGame(){
	return(event.type == SDL_QUIT );
}

void GUI::initGUI(){

	//Initialize all SDL subsystems
    if(SDL_Init(SDL_INIT_EVERYTHING) < 0){

		printf( "SDL could not initialize! SDL_Error: %s\n", SDL_GetError() );
		exit(1);
	}

	//Construct and check window construction
	window = SDL_CreateWindow("Zelda2 Clone",
					SDL_WINDOWPOS_UNDEFINED,
					SDL_WINDOWPOS_UNDEFINED,
                    SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);

	if(window==NULL){

			printf( "Window could not be created! SDL_Error: %s\n", SDL_GetError() );
			exit(1);
	}

	//Construct and check renderer construction
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	if(renderer == NULL){

		printf( "Window could not be created! SDL_Error: %s\n", SDL_GetError() );
		exit(1);

	}

}

void GUI::loadMedia(){

	//Open Zelda2 Sprite Sheet Forward
	zelda2SheetTexture = new Texture();
	zelda2SheetTexture->load(renderer,"./Assets/Images/Zelda2S3.png");

	//Parse Zelda2 Sprite Sheet Forward
	for(int i=0;i<Z2_NUM_SPRITES;i++){
		
		int row = i/Z2_SPRITE_NCOLS;
		int col = i%Z2_SPRITE_NCOLS;

		zelda2Clips[i].x = col*Z2_SPRITE_WIDTH+27;
		zelda2Clips[i].y = row*Z2_SPRITE_HEIGHT+9;
		zelda2Clips[i].w = Z2_SPRITE_WIDTH;
		zelda2Clips[i].h = Z2_SPRITE_HEIGHT;
	}

	//Open Block Sprite Sheet
	blockSheetTexture = new Texture();
	blockSheetTexture->load(renderer,"./Assets/Images/block.png");
	//Open Top Block Sprite Sheet
	topBlockSheetTexture = new Texture();
	topBlockSheetTexture->load(renderer,"./Assets/Images/top_block.png");
	
}

void GUI::cleanUp(){

	//Free the window
	SDL_DestroyWindow(window);
    window = NULL;

    //Free the renderer
   	SDL_DestroyRenderer(renderer);
    renderer = NULL;

    //Free loaded images
	zelda2SheetTexture->free();
    blockSheetTexture->free();
	topBlockSheetTexture->free();

    //Quit SDL Subsystems
   	IMG_Quit();
    SDL_Quit();

}

void GUI::displayGameState(int linkPosX, int linkPosY, int linkSpriteID, int numBlocks, int blockPosX[], int blockPosY[], bool blockTop[]){

	//Clear screen
	SDL_SetRenderDrawColor(renderer,0,0,0,255);  
	SDL_RenderClear(renderer);

    //Render Blocks
	for(int i=0;i<numBlocks;i++){
		if(blockTop[i])
		{
			topBlockSheetTexture->render(renderer, blockPosX[i], blockPosY[i], NULL);
		}
		else
		{
			blockSheetTexture->render(renderer, blockPosX[i], blockPosY[i], NULL);
		}
	}

    //Render Zelda2
	zelda2SheetTexture->render(renderer, linkPosX, linkPosY, &zelda2Clips[linkSpriteID]);

	//Update the visible screen
	SDL_RenderPresent(renderer);
	
}
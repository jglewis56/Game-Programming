#include <iostream>
#include <fstream>
#include <string>

#include "GUI.h"
#include "Texture.h"

using namespace std;

GUI::GUI()
{
	//Initialize the window
	window = NULL;

	//Initialize the renderer
	renderer = NULL;

	//Image textures used in GUI
	linkSheetTexture = NULL;
	blockSpriteTexture = NULL;
	deelerSpriteTexture = NULL;

	//Text structures used in GUI
	normalFont = NULL;

	//Start-up the GUI!
	initGUI();

	//Load in all the images and clip (if necessary)
	loadMedia();

	attack = false;
	//Exit criteria
	quit=false;

}

GUI::~GUI()
{
	cleanUp();
}

int GUI::observeEvent()
{
	return(SDL_PollEvent( &event ));
}

LK_TRANSITION GUI::getCommand()
{
	//Base command is "NA" for "Not Applicable"
	command = NA;

	//If a key was pressed
	if (attack)
	{
		command = ATTACK;
		SDL_FlushEvent(771);
	}
	else
		if (event.type == SDL_KEYDOWN) {
			{
				//Animate
				switch (event.key.keysym.sym) {

				case SDLK_a: command = ATTACK; attack = true; break;
				case SDLK_UP: command = UP; break;
				case SDLK_DOWN:
					command = DOWN; break;
				case SDLK_LEFT: command = LEFT; break;
				case SDLK_RIGHT: command = RIGHT; break;

				}
			}

		}

	if (event.type == SDL_KEYUP)
	{
		attack = false;
		command = NA;


	}

	return(command);
}

bool GUI::quitGame()
{
	return(event.type == SDL_QUIT );
}

void GUI::initGUI(){

	//Initialize all SDL subsystems
	if(SDL_Init(SDL_INIT_EVERYTHING) < 0)
	{
		printf( "SDL could not initialize! SDL_Error: %s\n", SDL_GetError() );
		exit(1);
	}

	//Initialize PNG loading
	int imgFlags = IMG_INIT_PNG;
	if( !( IMG_Init( imgFlags ) & imgFlags ) )
	{
		printf( "SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError() );
		exit(1);
	}

	//Initialize SDL_ttf
	if( TTF_Init() == -1 )
	{
		printf( "SDL_ttf could not initialize! SDL_ttf Error: %s\n", TTF_GetError() );
		exit(1);
	}

	//Construct and check window construction
	window = SDL_CreateWindow("Link Clone",
		SDL_WINDOWPOS_UNDEFINED,
		SDL_WINDOWPOS_UNDEFINED,
		SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);

	if(window==NULL)
	{
		printf( "Window could not be created! SDL_Error: %s\n", SDL_GetError() );
		exit(1);
	}

	//Construct and check renderer construction
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	if(renderer == NULL)
	{
		printf( "Window could not be created! SDL_Error: %s\n", SDL_GetError() );
		exit(1);

	}

}

void GUI::loadMedia()
{
	//Open Link Sprite Sheet Forward
	linkSheetTexture = new Texture();
	linkSheetTexture->load(renderer,"./Assets/Images/link.png");

	//Parse Link Sprite Sheet Forward
	//Parse link Sprite Sheet Forward

	//Still Right
	linkClips[0].x = 1;
	linkClips[0].y = 3;
	linkClips[0].w = LK_SPRITE_WIDTH;
	linkClips[0].h = LK_SPRITE_HEIGHT;

	//Walk Right
	linkClips[1].x = 21;
	linkClips[1].y = 3;
	linkClips[1].w = LK_SPRITE_WIDTH;
	linkClips[1].h = LK_SPRITE_HEIGHT;

	linkClips[2].x = 41;
	linkClips[2].y = 3;
	linkClips[2].w = LK_SPRITE_WIDTH;
	linkClips[2].h = LK_SPRITE_HEIGHT;

	linkClips[3].x = 60;
	linkClips[3].y = 3;
	linkClips[3].w = LK_SPRITE_WIDTH;
	linkClips[3].h = LK_SPRITE_HEIGHT;

	//JUMP RIGHT
	linkClips[4].x = 83;
	linkClips[4].y = 3;
	linkClips[4].w = LK_SPRITE_WIDTH;
	linkClips[4].h = LK_SPRITE_HEIGHT - 5;

	//Land Right
	linkClips[5].x = 104;
	linkClips[5].y = 3;
	linkClips[5].w = LK_SPRITE_WIDTH;
	linkClips[5].h = LK_SPRITE_HEIGHT;

	linkClips[6].x = 123;
	linkClips[6].y = 3;
	linkClips[6].w = LK_SPRITE_WIDTH;
	linkClips[6].h = LK_SPRITE_HEIGHT;

	//Attach Right
	linkClips[7].x = 144;
	linkClips[7].y = 3;
	linkClips[7].w = LK_SPRITE_WIDTH + 7;
	linkClips[7].h = LK_SPRITE_HEIGHT;

	linkClips[8].x = 175;
	linkClips[8].y = 3;
	linkClips[8].w = LK_SPRITE_WIDTH * 2;
	linkClips[8].h = LK_SPRITE_HEIGHT;

	//Crouch Right
	linkClips[9].x = 213;
	linkClips[9].y = 3;
	linkClips[9].w = LK_SPRITE_WIDTH;
	linkClips[9].h = LK_SPRITE_HEIGHT;

	//Crouch Attack Right
	linkClips[10].x = 236;
	linkClips[10].y = 3;
	linkClips[10].w = LK_SPRITE_WIDTH * 2;
	linkClips[10].h = LK_SPRITE_HEIGHT;

	//Still Left
	linkClips[11].x = 523;
	linkClips[11].y = 3;
	linkClips[11].w = LK_SPRITE_WIDTH;
	linkClips[11].h = LK_SPRITE_HEIGHT;

	//Walk Left
	linkClips[12].x = 503;
	linkClips[12].y = 3;
	linkClips[12].w = LK_SPRITE_WIDTH;
	linkClips[12].h = LK_SPRITE_HEIGHT;

	linkClips[13].x = 483;
	linkClips[13].y = 3;
	linkClips[13].w = LK_SPRITE_WIDTH;
	linkClips[13].h = LK_SPRITE_HEIGHT;

	linkClips[14].x = 464;
	linkClips[14].y = 3;
	linkClips[14].w = LK_SPRITE_WIDTH;
	linkClips[14].h = LK_SPRITE_HEIGHT;

	//JUMP LEFT
	linkClips[15].x = 441;
	linkClips[15].y = 3;
	linkClips[15].w = LK_SPRITE_WIDTH;
	linkClips[15].h = LK_SPRITE_HEIGHT - 5;

	//Land Left
	linkClips[16].x = 420;
	linkClips[16].y = 3;
	linkClips[16].w = LK_SPRITE_WIDTH;
	linkClips[16].h = LK_SPRITE_HEIGHT;


	linkClips[17].x = 401;
	linkClips[17].y = 3;
	linkClips[17].w = LK_SPRITE_WIDTH;
	linkClips[17].h = LK_SPRITE_HEIGHT - 5;

	//Attack Left
	linkClips[18].x = 373;
	linkClips[18].y = 3;
	linkClips[18].w = LK_SPRITE_WIDTH + 7;
	linkClips[18].h = LK_SPRITE_HEIGHT;

	linkClips[19].x = 333;
	linkClips[19].y = 3;
	linkClips[19].w = LK_SPRITE_WIDTH * 2;
	linkClips[19].h = LK_SPRITE_HEIGHT;

	//Crouch Left
	linkClips[20].x = 311;
	linkClips[20].y = 3;
	linkClips[20].w = LK_SPRITE_WIDTH;
	linkClips[20].h = LK_SPRITE_HEIGHT;

	//Crouch Attack Left
	linkClips[21].x = 272;
	linkClips[21].y = 3;
	linkClips[21].w = LK_SPRITE_WIDTH * 2;
	linkClips[21].h = LK_SPRITE_HEIGHT;

	//Open Block Sprite
	blockSpriteTexture = new Texture();
	blockSpriteTexture->load(renderer,"./Assets/Images/block.png");

	//Open Deeler Sprite
	deelerSpriteTexture = new Texture();
	deelerSpriteTexture->load(renderer,"./Assets/Images/deeler.png");

	//Open Elevator Sprite
	elevatorSpriteTexture = new Texture();
	elevatorSpriteTexture->load(renderer, "./Assets/Images/elevator.png");

	//Open the font
	normalFont = TTF_OpenFont( "./Assets/Fonts/impact.ttf", 48 );
	if( normalFont == NULL )
	{
		printf( "Failed to load lazy font! SDL_ttf Error: %s\n", TTF_GetError() );
	}

}

void GUI::cleanUp()
{
	//Free the window
	SDL_DestroyWindow(window);
	window = NULL;

	//Free the renderer
	SDL_DestroyRenderer(renderer);
	renderer = NULL;

	//Free loaded images
	linkSheetTexture->free();
	blockSpriteTexture->free();
	elevatorSpriteTexture->free();

	//Free font structures
	TTF_CloseFont(normalFont);

	//Quit SDL Subsystems
	IMG_Quit();
	TTF_Quit();
	SDL_Quit();
}


void GUI::displayGameState(Engine & engine)
{
	//Clear screen
	SDL_SetRenderDrawColor(renderer,0,0,0,255);  
	SDL_RenderClear(renderer);

	//Render Blocks
	for(int i=0;i<engine.getNumObjects();i++)
	{
		Object* object = engine.getObject(i);
		if(object->getObjectID()==BLOCK)
		{
			blockSpriteTexture->render(renderer, object->plotX(), object->plotY(), NULL);
		}

	}

	//Render Deeler(s)
	for(int i=0;i<engine.getNumObjects();i++)
	{
		Object* object = engine.getObject(i);
		if(object->getObjectID()==DEELER)
		{
			deelerSpriteTexture->render(renderer, object->plotX(), object->plotY(), NULL);
		}
	}

	//Render Elevator(s)
	for (int i = 0; i<engine.getNumObjects(); i++)
	{
		Object* object = engine.getObject(i);
		if (object->getObjectID() == ELEVATOR)
		{
			elevatorSpriteTexture->render(renderer, object->plotX(), object->plotY(), NULL);
		}
	}

	//Render Link
	for(int i=0;i<engine.getNumObjects();i++)
	{
		Object* object = engine.getObject(i);
		if(object->getObjectID()==LINK)
		{
			int adjustedX = object->getPosX();
			if (object->getSpriteID() == 7)
			{
				adjustedX -= 6;
			}
			else if (object->getSpriteID() == 19)
			{
				adjustedX -= 16;
			}

			//Render Link
			linkSheetTexture->render(renderer, adjustedX, object->getPosY(), &linkClips[object->getSpriteID()]);
		}
	}

	//-------------------------------------------------------------
	//Display the User's Command in top right corner OR  end-of-game
	//condition
	//-------------------------------------------------------------
	string text = "None";
	int textX = 0;
	int textY = 0;

	if(!engine.getGameOver()){
		
		//Set the text based on the keyboard command
		switch(command){
		case UP: text = "Up"; break;
		case ATTACK: text = "Attack"; break;
		case DOWN: text = "Down"; break;
		case RIGHT: text = "Right"; break;
		case LEFT: text = "Left"; break;
		case NA: text = "NA"; break;
		}

		//Set the text position at the top right
		textX = 480;
		textY = 10;
	}else{
		
		if (!engine.getGameWon()) {

			//Set the text to end of game condition
			text = "Game Over";

			//Center the text
			textX = 200;
			textY = 140;

		}
		else {

			//Set the win condition
			text = "You Win!";

			//Center the text
			textX = 200;
			textY = 140;
		}

	}

	//Render Command to Text
	SDL_Color textColor = { 255, 255, 153 };
	SDL_Texture* textSheetTexture = SDL_CreateTextureFromSurface( renderer,  TTF_RenderText_Solid(normalFont, text.c_str(), textColor));

	//Set rendering space and render to screen
	int width=0,height=0;
	SDL_QueryTexture(textSheetTexture,NULL,NULL,&width,&height);
	SDL_Rect renderQuad = {textX, textY, width, height};

	//Render to screen
	SDL_RenderCopy(renderer, textSheetTexture, NULL, &renderQuad );
	//-------------------------------------------------------------
	//-------------------------------------------------------------


	//Update the visible screen
	SDL_RenderPresent(renderer);

}
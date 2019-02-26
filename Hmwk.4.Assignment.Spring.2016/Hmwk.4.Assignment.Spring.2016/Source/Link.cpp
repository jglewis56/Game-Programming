#include <iostream>
#include <fstream>

//Game Architecture Headers
#include "constants.h"
#include "Link.h"

Link::Link(int posX, int posY): Object(posX, posY)

{
	objectID = LINK;
	//Initialize at bottom left of screen 
	posX = 0.0f;
	posY =(float)(SCREEN_HEIGHT-LK_SPRITE_HEIGHT);
	//Standing, facing to the right 
	state = STILL_RIGHT; 
	animationID = 0;
	//Load Animation Data 
	loadAnimation("./Assets/Config/animation.txt"); 
	//Compute Initial Sprite 
	updateSprite();
}
Link::~Link() 
{
	//Clean-up ragged 2D array 
	for(int i=0;i<numStates;i++)
	{ 
		delete [] animationMap[i]; 
	} 
	delete [] animationMap;
	//Clean-up 1D array 
	delete [] animationSize;
}
void Link::loadAnimation(string gameFile) 
{
	//Declare and open filestream 
	fstream fin; 
	fin.open(gameFile.c_str(),ios::in);
	//Number of columns to store 
	fin >> numStates;
	//Allocate memory
	animationSize = new int[numStates];
	animationMap = new int*[numStates];
	//Load the ragged array 
	for(int i=0;i<numStates;i++)
	{
	fin >> animationSize[i];
	animationMap[i] = new int[animationSize[i]];
	for (int j = 0; j<animationSize[i]; j++)
	{
		fin >> animationMap[i][j];
	}
}
//Clean-up 
	fin.close();
}
int Link::getState() const
{
	return(state); 
}
//Set Methods
void Link::setState(int state)
{
	this->state = state;
}
void Link::update(LK_TRANSITION command)
{
	switch (command) 
	{
		//Execute the appropriate state transition 
	case ATTACK: 
		moveAttack(); 
		break;
	case DOWN:
		moveDown();
		break; 
	case LEFT:
		moveLeft(); 
		break; 
	case RIGHT: 
		moveRight();
		break; 
	case NA: 
		noAction(); 
		break;
	}
	//Apply Physics
	posY += velY;
	velY += DELTA_T*GRAVITY;
	//Link Boundary Checking (left boundary) 
	if(getPosX() <= 0)
	{
		setPosX(0); 
	}
	//Boundary Checking (top and bottom boundaries) 
	if(getPosY() >= SCREEN_HEIGHT-LK_SPRITE_HEIGHT)
	{ 
		setPosY((float)(SCREEN_HEIGHT-LK_SPRITE_HEIGHT)); 
	} 
	if(getPosY() <= 0)
	{
		setPosY(0.0f); 
	}
}
void Link::moveAttack()
{
	//Changed states: initialize this state 
	switch (state) 
	{
	case STILL_RIGHT:
		state = ATTACK_RIGHT;
		animationID = 0; 
		break;
	case STILL_LEFT: 
		state = ATTACK_LEFT; 
		animationID = 0; 
		break;
	default:
		break;
	}
	updateSprite();
} 
void Link::moveDown()
{
	switch (state) 
	{
	case STILL_LEFT:
		state = CROUCH_LEFT;
		animationID = 0;
		break; 
	case STILL_RIGHT:
		state = CROUCH_RIGHT;
		animationID = 0;
		break;
	}
	updateSprite();
}
void Link::moveRight() 
{
	//Conduct the appropriate state transition and/or animation 
	switch(state)
	{
	case STILL_RIGHT:
		state = WALK_RIGHT;
		animationID = 0;
		posX += LK_RUN_SPEED;
		break; 
	case WALK_RIGHT:
		posX += LK_RUN_SPEED;
		break;
	default: 
		state=STILL_RIGHT; 
		animationID = 0; 
	} 
	updateSprite();
}
void Link::moveLeft() 
{
	//Conduct the appropriate state transition and/or animation 
	switch(state)
	{
	case STILL_LEFT: 
		state = WALK_LEFT; 
		animationID = 0;
	posX -= LK_RUN_SPEED;
	break; 
	case WALK_LEFT:
		posX -= LK_RUN_SPEED; 
		break; 
	default: 
		state = STILL_LEFT;
		animationID = 0;
}
	updateSprite();
}
void Link::noAction()
{
	if (state != STILL_LEFT || state != STILL_RIGHT) 
	{ //Conduct the appropriate state transition 
		switch (state)
		{
		case ATTACK_RIGHT: 
		case CROUCH_RIGHT:
		case WALK_RIGHT:
		state = STILL_RIGHT;
		break;
		case ATTACK_LEFT:
		case CROUCH_LEFT:
		case WALK_LEFT:
		state = STILL_LEFT;
		break;
		} 
		//Reset animation and update the sprite
		animationID=0; 
		updateSprite();
	}
}
void Link::updateSprite()
{
	animationID++;
	//Wrap animation sequence 
	if(animationID>=animationSize[state])
	{
		animationID = 0; 
	}
	//Map sprite ID 
	spriteID = animationMap[state][animationID];
}
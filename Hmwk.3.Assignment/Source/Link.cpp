#include <iostream>
#include <string>
#include <fstream>
#include "Link.h"
#include "constants.h"
using namespace std;
// Default constructor that intializes link into the bottom left of the screen
Link::Link()
{
	loadAnimation("./Assets/Config/animation.txt");
	linkPosX = 0;
	linkPosY = SCREEN_HEIGHT - LK_SPRITE_HEIGHT;
	linkState = STILL_RIGHT;
	linkAnimID = 0;
	linkSpriteID = animationMap[linkState][linkAnimID];
}
Link::~Link()
{

}

void Link::loadAnimation(string gameFile)
{
	//Declare and open filestream
	fstream fin;
	fin.open(gameFile);
	//Number of columns to store
	fin >> numStates;
	//Allocate memory
	animationSize = new int[numStates];
	animationMap = new int*[numStates];
	//Load the ragged array
	for (int i = 0;i<numStates;i++)
	{
		fin >> animationSize[i];
		animationMap[i] = new int[animationSize[i]];
		for (int j = 0;j<animationSize[i];j++)
		{
			fin >> animationMap[i][j];
		}
	}
	//Clean-up
	fin.close();
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
	case NA: noAction();
		break;
	}
	//Update the sprite
	updateSprite();
	//Boundary Checking (left and right boundaries)
	if (linkPosX >= SCREEN_WIDTH/2 - LK_SPRITE_WIDTH)
	{
		linkPosX = SCREEN_WIDTH/2 - LK_SPRITE_WIDTH;
	}
	if (linkPosX <= 0)
	{
		linkPosX = 0;
	}
	//Boundary Checking (top and bottom boundaries)
	if (linkPosY >= SCREEN_HEIGHT - LK_SPRITE_HEIGHT)
	{
		linkPosY = SCREEN_HEIGHT - LK_SPRITE_HEIGHT;
	}
	if (linkPosY <= 0)
	{
		linkPosY = 0;
	}
}

// Homework 2 functionality
void Link::moveAttack()
{
	switch (linkState)
	{
	case STILL_RIGHT:
		linkState = ATTACK_RIGHT;
		linkAnimID = 0;
		break;
	case STILL_LEFT:
		linkState = ATTACK_LEFT;
		linkAnimID = 0;
		break;
	default:
		break;
	}
}
void Link:: moveDown()
{
	//Changed states: initialize this state
	if (linkState == STILL_LEFT)
	{
		linkState = CROUCH_LEFT;
		linkAnimID = 0;
	}
	else if (linkState == STILL_RIGHT)
	{
		linkState = CROUCH_RIGHT;
		linkAnimID = 0;
	}
}
void Link:: moveRight()
{
	//Conduct the appropriate state transition and/or animation
	switch (linkState)
	{
	case STILL_RIGHT:
		linkState = WALK_RIGHT;
		linkAnimID = 0;
		linkPosX += LK_RUN_SPEED;
		break;
	case STILL_LEFT:
		linkState = STILL_RIGHT;
		linkAnimID = 0;
		break;
	case WALK_RIGHT:
		linkPosX += LK_RUN_SPEED;
		break;
	default:
		linkState = STILL_RIGHT;
		linkAnimID = 0;
	}
}
void Link:: moveLeft()
{
	//Conduct the appropriate state transition and/or animation
	switch (linkState)
	{
	case STILL_LEFT:
		linkState = WALK_LEFT;
		linkAnimID = 0;
		linkPosX -= LK_RUN_SPEED;
		break;
	case STILL_RIGHT:
		linkState = STILL_LEFT;
		linkAnimID = 0;
		break;
	case WALK_LEFT:
		linkPosX -= LK_RUN_SPEED;
		break;
	default:
		linkState = STILL_LEFT;
		linkAnimID = 0;
	}
}
void Link:: noAction()
{
	if (linkState != STILL_LEFT || linkState != STILL_RIGHT)
	{
		//Conduct the appropriate state transition
		switch (linkState) {
		case ATTACK_RIGHT:
		case CROUCH_RIGHT:
		case WALK_RIGHT:
			linkState = STILL_RIGHT;
			break;
		case ATTACK_LEFT:
		case CROUCH_LEFT:
		case WALK_LEFT:
			linkState = STILL_LEFT;
			break;
		}
		//Reset animation and update the sprite
		linkAnimID = 0;
	}
}
void Link:: updateSprite()
{
	linkAnimID++;
	//Wrap animation sequence
	if (linkAnimID >= animationSize[linkState])
	{
		linkAnimID = 0;
	}
	//Map sprite ID
	linkSpriteID = animationMap[linkState][linkAnimID];
}
int Link::getPosX() const
{
	return(linkPosX);
}
int Link::getPosY() const
{
	return(linkPosY); 
}
int Link::getState() const
{
	return(linkState);
}
int Link::getSpriteID()const
{
	return(linkSpriteID);
}
void Link::setPosX(float linkPosX)
{
	this->linkPosX = linkPosX;
}
void Link::setPosY(float linkPosY)
{
	this->linkPosY = linkPosY;
}
void Link::setState(int linkState)
{
	this->linkState = linkState;
}
void Link::setSpriteID(int linkSpriteID)
{
	this->linkSpriteID = linkSpriteID;
}
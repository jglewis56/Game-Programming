#include <fstream>
#include <string>
#include <iostream>

#include "engine.h"
#include "constants.h"

using namespace std;

void loadAnimationMap(string gameFile, int & numStates, int* & sizeSequence, int** & sequence)
{
	fstream fin;
	fin.open(gameFile, ios::in);
	fin >> numStates;
	sizeSequence = new int[numStates];
	sequence = new int*[numStates];
	int i = 0;
	while (!fin.eof())
	{
		fin >> sizeSequence[i];
		sequence[i] = new int[sizeSequence[i]];
		for (int j = 0;j < sizeSequence[i];j++)
		{
			fin >> sequence[i][j];
		}
		i++;
	}
	fin.close();
}
void initLinkData(int & linkPosX, int & linkPosY, LK_STATE & linkState, int & linkAnimID, int** animationMap, int & linkSpriteID)
{
	linkPosX = 0;
	linkPosY = SCREEN_HEIGHT - LK_SPRITE_HEIGHT;
	linkState = STILL_RIGHT;
	linkSpriteID = animationMap[linkState][linkAnimID];
}
void changeGameState(LK_TRANSITION command, int & linkPosX, int & linkPosY, LK_STATE & linkState, int & linkAnimID, int* animationSize, int** animationMap, int & linkSpriteID)
{
	if(command== RIGHT)
	{
		moveRight(linkState, linkAnimID, animationSize, animationMap, linkSpriteID, linkPosX, linkPosY);
	}
	if(command==LEFT)
	{
		moveLeft(linkState, linkAnimID, animationSize, animationMap, linkSpriteID, linkPosX, linkPosY);
	}
	if(command==DOWN)
	{
		moveDown(linkState, linkAnimID, animationSize, animationMap,linkSpriteID, linkPosX, linkPosY);
	}
    if(command==ATTACK)
	{
		moveAttack(linkState, linkAnimID, animationSize, animationMap, linkSpriteID,  linkPosX, linkPosY);
	}
    if(command==NA)
	{
		noAction( linkState, linkAnimID, animationSize,animationMap, linkSpriteID, linkPosX, linkPosY);
	}
 }

void updateSprite(LK_STATE linkState, int & linkAnimID, int* animationSize, int** animationMap, int & linkSpriteID)
{
	linkAnimID = linkAnimID%animationSize[linkState];
	linkSpriteID = animationMap[linkState][linkAnimID];
	linkAnimID++;

}
void moveAttack(LK_STATE & linkState, int & linkAnimID, int* animationSize, int** animationMap, int & linkSpriteID, int & linkPosX, int & linkPosY)
{
	if (linkState == STILL_RIGHT)
	{
		linkState = ATTACK_RIGHT;
		updateSprite(linkState, linkAnimID, animationSize, animationMap, linkSpriteID);
	}
	else
		if (linkState == WALK_RIGHT)
		{
			linkState = ATTACK_RIGHT;
			updateSprite(linkState, linkAnimID, animationSize, animationMap, linkSpriteID);
		}
		else
		if (linkState == STILL_LEFT)
		{
			linkState = ATTACK_LEFT;
			updateSprite(linkState, linkAnimID, animationSize, animationMap, linkSpriteID);
		}
	if (linkState == WALK_LEFT)
	{
		linkState = ATTACK_LEFT;
		updateSprite(linkState, linkAnimID, animationSize, animationMap, linkSpriteID);
	}
}
void moveDown(LK_STATE & linkState, int & linkAnimID, int* animationSize, int** animationMap, int & linkSpriteID, int & linkPosX, int & linkPosY)
{

	if (linkState == STILL_RIGHT)
	{
		linkState = CROUCH_RIGHT;
	 updateSprite( linkState, linkAnimID, animationSize, animationMap, linkSpriteID);

	}
	else
		if (linkState == WALK_RIGHT)
		{
			linkState = CROUCH_RIGHT;
			updateSprite(linkState, linkAnimID, animationSize, animationMap, linkSpriteID);
		}
		else
	if (linkState == STILL_LEFT || linkState == WALK_LEFT)
	{
		linkState = CROUCH_LEFT;
		updateSprite(linkState, linkAnimID,  animationSize, animationMap, linkSpriteID);

	}

}

void moveLeft(LK_STATE & linkState, int & linkAnimID, int* animationSize, int** animationMap, int & linkSpriteID, int & linkPosX, int & linkPosY)
{
	if (linkState == STILL_RIGHT || WALK_RIGHT || STILL_LEFT || WALK_LEFT)
	{
		
		updateSprite(linkState, linkAnimID, animationSize, animationMap, linkSpriteID);
	}
	linkPosX = linkPosX-LK_WALK_SPEED;
	linkState = WALK_LEFT;
	updateSprite(linkState, linkAnimID, animationSize, animationMap, linkSpriteID);
}
void moveRight(LK_STATE & linkState, int & linkAnimID, int* animationSize, int** animationMap, int & linkSpriteID, int & linkPosX, int & linkPosY)
{
	if (linkState == STILL_RIGHT || WALK_RIGHT || STILL_LEFT || WALK_LEFT)
	{
		
		updateSprite(linkState, linkAnimID, animationSize, animationMap, linkSpriteID);
	}

	linkPosX =linkPosX+ LK_WALK_SPEED;
	linkState = WALK_RIGHT;
	
}
void noAction(LK_STATE & linkState, int & linkAnimID, int* animationSize, int** animationMap, int & linkSpriteID, int & linkPosX, int & linkPosY)
{
	
	if (linkState == CROUCH_RIGHT)
	{
		linkState = STILL_RIGHT;
		updateSprite(linkState, linkAnimID, animationSize, animationMap, linkSpriteID);
	}
	if (linkState == CROUCH_LEFT)
	{
		linkState = STILL_LEFT;
		updateSprite(linkState, linkAnimID, animationSize, animationMap, linkSpriteID);
	}
	if (linkState == ATTACK_RIGHT)
	{
		linkState = STILL_RIGHT;
		updateSprite(linkState, linkAnimID, animationSize, animationMap, linkSpriteID);
	}
	if (linkState == ATTACK_LEFT)
	{
		linkState = STILL_LEFT;
		updateSprite(linkState, linkAnimID, animationSize, animationMap, linkSpriteID);
	}
}
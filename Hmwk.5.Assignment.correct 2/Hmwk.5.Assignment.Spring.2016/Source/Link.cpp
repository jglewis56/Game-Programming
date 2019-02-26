#include <iostream>
#include <fstream>

//Game Architecture Headers
#include "constants.h"
#include "Link.h"
#include "Object.h"
using namespace std;

Link::Link(int posX, int posY, int velY) :Object(posX, posY, velY)
{
	objectID = LINK;
	loadAnimation("./Assets/Config/animation.txt");

	//initialize the Link's game/animation state
	state = STILL_RIGHT;
	animationID = 0;

	//initialize physics
	velY = 0.0f;

	//compute Initial SpriteID
	updateSprite();
}
Link::~Link()
{
	for (int i = 0;i<numStates;i++) {
		delete[] animationMap[i];
	}
	delete[] animationMap;
	//Clean-up 1D array
	delete[] animationSize;
}
void Link::loadAnimation(string gameFile)
{
	//Declare and open filestream
	fstream fin;
	fin.open(gameFile.c_str(), ios::in);
	//Number of columns to store
	fin >> numStates;
	//Allocate memory
	animationSize = new int[numStates];
	animationMap = new int*[numStates];
	//Load the ragged array
	for (int i = 0;i<numStates;i++) {
		fin >> animationSize[i];
		animationMap[i] = new int[animationSize[i]];
		for (int j = 0;j<animationSize[i];j++) {
			fin >> animationMap[i][j];
		}
	}
	//Clean-up
	fin.close();
}

//Get Methods

int Link::getState() const
{
	return(state);
}

//Set Methods

void Link::setState(int state)
{
	this->state = state;
}

//Collision Detection method
bool Link::collisionDetected(Object*object)
{
	int objectWidth = -1;
	int objectHeight = -1;

	//switch on objectType statement to set objectWidth and objectHeight
	switch (object->getObjectID())
	{
	case DEELER:
		objectWidth = DEELER_SPRITE_WIDTH;
		objectHeight = DEELER_SPRITE_HEIGHT;
		break;
	case BLOCK:
		objectWidth = BLOCK_SPRITE_WIDTH;
		objectHeight = BLOCK_SPRITE_HEIGHT;
		break;
	case ELEVATOR:
		objectWidth = ELEVATOR_SPRITE_WIDTH;
		objectHeight = ELEVATOR_SPRITE_HEIGHT;
		break;
	}
		//Find center of link
		int linkLeftX = plotX();
		int linkTopY = plotY();
		int linkRightX = plotX() + LK_SPRITE_WIDTH;
		int linkBottomY = plotY() + LK_SPRITE_HEIGHT;
		int objectLeftX = object->plotX();
		int objectTopY = object->plotY();
		int objectRightX = object->plotX() + objectWidth;
		int objectBottomY = object->plotY() + objectHeight;

		//Detect link collision with Block
		if (((linkRightX > objectLeftX && linkLeftX < objectRightX) && (linkTopY<objectBottomY&&linkBottomY>objectTopY)))
		{
			collision = true;
		}
		else
			collision = false;
			return (collision);
	}

		
	

//Animation Function		
void Link::update(LK_TRANSITION command, vector<Object*> & objects)
{
	switch (command) {
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
	case NA: noAction(); break;
	}
	//Apply Physics
	posY += velY;
	velY += DELTA_T*GRAVITY;
	//Left Boundary Detect & Resolve
	if (plotX() <= 0) {
		setPosX(0);
	}
	// interate over each object in the vector of objects
	vector<Object*>::iterator oi;
	for (oi = objects.begin();oi != objects.end();oi++)

	{

		if ((*oi)->getObjectID() == BLOCK)
		{
			if (collisionDetected(*oi))
			{
				posY = (*oi)->getPosY() - LK_SPRITE_HEIGHT;
				velY = 0.0f;
			}
		}
		if ((*oi)->getObjectID() == ELEVATOR)
		{
			if (collisionDetected(*oi))
			{
				posY = (*oi)->getPosY()+1;
				posX = posX;
				velY = 0.0f;
			}
		}
	}
}




void Link::updateSprite()
{
	animationID++;
	//Wrap animation sequence
	if (animationID >= animationSize[state]) {
		animationID = 0;
	}
	//Map sprite ID
	spriteID = animationMap[state][animationID];
}

// Still need to do this
void Link::moveUp()
{

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
void Link::moveLeft()
{
	switch (state) {
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
void Link::moveRight()
{
	//Conduct the appropriate state transition and/or animation
	switch (state) {
	case STILL_RIGHT:
		state = WALK_RIGHT;
		animationID = 0;
		posX += LK_RUN_SPEED;
		break;
	case WALK_RIGHT:
		posX += LK_RUN_SPEED;
		break;
	default:
		state = STILL_RIGHT;
		animationID = 0;
	}
	updateSprite();
}
void Link::noAction()
{
	if (state != STILL_LEFT || state != STILL_RIGHT)
	{
		//Conduct the appropriate state transition
		switch (state) {
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
		animationID = 0;
		updateSprite();
	}
}


//System Headers
#include <fstream>
#include <string>
#include <iostream>

//Game Headers
#include "constants.h"
#include "Engine.h"
#include "Object.h"
#include "Link.h"
#include "Block.h"
#include "Deeler.h"
#include "Elevator.h"

using namespace std;
//System Headers
#include <fstream>
#include <string>
#include <iostream>

//Game Headers
#include "constants.h"
#include "Engine.h"
#include "Object.h"
#include "Link.h"
#include "Block.h"
#include "Deeler.h"
#include "Elevator.h"

using namespace std;


Engine::Engine()
{

	Object* tmpObject = NULL;
	fstream fin;
	int objectID;
	int positionX;
	int positionY;
	//fin.open("./Assets/Config/levelEC.txt", ios::in);
	fin.open("./Assets/Config/level.txt", ios::in);
	while (!fin.eof())
	{
		fin >> objectID >> positionX >> positionY;

		switch (objectID)
		{
		case DEELER:
			tmpObject = new Deeler(positionX, positionY, 0);
			tmpObject->setObjectID(DEELER);
			break;
		case BLOCK:
			tmpObject = new Block(positionX, positionY, 0);
			tmpObject->setObjectID(BLOCK);
			break;
		case LINK:
			tmpObject = new Link(positionX, positionY, 0);
			tmpObject->setObjectID(LINK);
			break;
		case ELEVATOR:
			tmpObject = new Elevator(positionX, positionY, 0);
			tmpObject->setObjectID(ELEVATOR);
			break;
		}
		objects.push_back(tmpObject);
	}

}


Object* Engine::getObject(int index)
{
	return(objects[index]);
}
int Engine::getNumObjects()
{
	return(objects.size());
}
bool Engine::getGameOver()
{
	return(gameOver);
}
bool Engine::getGameWon()
{
	return(gameWon);
}
void Engine::changeGameState(LK_TRANSITION command)
{
	if (!gameOver)
	{
		for (auto object : objects)
		{
			object->update(command, objects);
		}
		Link* link = NULL;
		Deeler* deeler = NULL;
		Block* block = NULL;
		Elevator* elevator = NULL;
	}
	//-------------------// Implement Scrolling //-------------------
	/*
	1. Find x value of last blcok
	a. loop through the vector of objects
	b. for block objects, find the largest x value
	2. When last block is on screen (i.e. when x value < screen width)
	3. stop scrolling
	*/
	//Find the Link pointer 
	Link* link = NULL;
	int largestBlockX = 0;
	for (auto object : objects)
	{
		if (object->getObjectID() == LINK)
		{
			link = (Link*)object;
		}
		if (object->getObjectID() == BLOCK && object->getPosX() > largestBlockX)
		{
			largestBlockX = object->getPosX();
		}
	}
	//Scroll the game objects (compare x-position to Link)
	//if statment here
	if (link->getPosX() > SCREEN_WIDTH / 2)
	{
	if (largestBlockX + BLOCK_SPRITE_WIDTH > SCREEN_WIDTH)

		{
			link->setPosX(SCREEN_WIDTH / 2);
			//Scroll each object individually 
			for (int i = 0; i < objects.size(); i++)
			{
				Object* object = getObject(i);
				if (object->getObjectID() == BLOCK || object->getObjectID() == DEELER)
				{
					object->setPosX(object->getPosX() - LK_RUN_SPEED);
				}
			}
		}
	}


	//end if statement
	//-------------------// Detect end-of-game //-------------------
	////Find Deeler and detect collision with Link 

	for (auto object : objects)
	{
		if (object->getObjectID() == DEELER)
			if (link->collisionDetected(object))	
				gameOver = true;
	}

	if (link->getPosY() > SCREEN_HEIGHT)
		gameOver = true;
	if (link->getPosX() > SCREEN_WIDTH)
	{
		gameOver = true;
		gameWon = true;
	}

}

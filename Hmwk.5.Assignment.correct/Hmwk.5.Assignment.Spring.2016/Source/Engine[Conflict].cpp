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

using namespace std;

Engine::Engine()
{

	numObjects = 0;
	objects = NULL;

	//Open configuration file
	fstream fin;
	fin.open("./Assets/Config/level.txt",ios::in);

	//Get Number of Objects in configuration file
	fin >> numObjects;

	//Construct an array to store the game's objects
	objects = new Object*[numObjects];

	//Convert the configuration file into game objects
	int id = -1, x = -1, y = -1;

	//Each line of the config file specifies an object
	for(int i=0;i<numObjects;i++)
	{
		//Read in the data
		fin >> id >> x >> y;

		//Construct the appropriate object
		switch(id)
		{
		case LINK: objects[i] = new Link(x,y); break;
		case BLOCK: objects[i] = new Block(x,y); break;
		case DEELER: objects[i] = new Deeler(x,y); break;
		}

	}

	//Clean-up
	fin.close();

	//Set end-of-game condition
	gameOver = false;

}	

Object* Engine::getObject(int index)
{
	Object* result = NULL;
	if(index>=0 && index<numObjects)
	{
		result = objects[index];
	}
	return(result);
}

int Engine::getNumObjects()
{
	return(numObjects);
}

bool Engine::getGameOver()
{
	return(gameOver);
}

void Engine::changeGameState(LK_TRANSITION command)
{
	if(!gameOver)
	{
		//------------------
		//Update all objects
		//------------------
		for(int i=0;i<numObjects;i++)
		{
			objects[i]->update(command);
		}

		//--------------------
		// Implement Scrolling
		//--------------------

		//Find the Link pointer
		Object* link = NULL;
		for(int i=0;i<getNumObjects();i++)
		{
			Object* object = getObject(i);
			if(object->getObjectID()==LINK)
			{
				link = object;
			}
		}

		//Scroll the game objects (compare x-position to Link)
		if(link->getPosX() > SCREEN_WIDTH/2)
		{
			link->setPosX(SCREEN_WIDTH/2);

			//Scroll each object individually
			for(int i=0;i<numObjects;i++)
			{
				Object* object = getObject(i);
				if(object->getObjectID() == BLOCK || object->getObjectID() == DEELER)
				{
					object->setPosX(object->getPosX()-LK_RUN_SPEED);
				}
			}
		}

		//--------------------
		// Detect end-of-game
		//--------------------

		//Find Deeler and detect collision with Link
		for(int i=0;i<numObjects;i++)
		{
			Object* object = getObject(i);
			if(object->getObjectID() == DEELER)
			{
				//Find center of link
				int linkTopLeftX = link->plotX();
				int linkTopRightY = link->plotY();
				int linkBottomRightX = link->plotX() + LK_SPRITE_WIDTH;
				int linkBottomLeftY = link->plotY() + LK_SPRITE_HEIGHT;

				//Detect link collision with Deeler
				if(linkCenterX > object->plotX() && linkCenterX < object->plotX()+DEELER_SPRITE_WIDTH)
				{
					if(linkCenterY > object->plotY() && linkCenterY < object->plotY()+DEELER_SPRITE_HEIGHT)
					{
						gameOver = true;
					}
				}
			}
		}
	}
}
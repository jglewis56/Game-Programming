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
		fstream fin;
		fin.open("./Assets/Config/level.txt",ios::in);
		fin >> numObjects;
		objects = new Object*[numObjects];
		int id = 0, objectX = 0, objectY = 0;
		for (int i = 0; i < numObjects; i++)
		{
			fin >> id >> objectX >> objectY;
			switch(id)
			{
			case LINK: 
				objects[i] = new Link(objectX, objectY);
				break;
			case BLOCK:
				objects[i] = new Block(objectX, objectY);
				break;
			case DEELER:
				objects[i] = new Deeler(objectX, objectY);
				break;
			}
		}
		fin.close();
		gameOver = false;
}
Object* Engine::getObject(int index)
{
	Object* result = NULL;
	if (index >= 0 && index < numObjects)
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
	if (!gameOver)
	{
		for (int i = 0; i < numObjects; i++)
		{
			objects[i]->update(command);
		}
		//finding link
		Object* link = NULL;
		for (int i = 0; i < getNumObjects(); i++)
		{
			Object* object = getObject(i);
			if (object->getObjectID() == LINK)
			{
				link = object;
			}
		}

		// Detecting collision
		if (link->getPosX() > SCREEN_WIDTH / 2)
		{
			link->setPosX(SCREEN_WIDTH / 2);
			for (int i = 0; i < numObjects; i++)
			{
				Object* object = getObject(i);
				if (object->getObjectID() == BLOCK || object->getObjectID() == DEELER)
				{
					object->setPosX(object->getPosX() - LK_RUN_SPEED);
				}
			}
		}
		for (int i = 0; i < numObjects; i++)
		{
			Object* object = getObject(i);
			if (object->getObjectID() == DEELER)
			{
				int linkCenterX = link->plotX() + LK_SPRITE_WIDTH / 2;
				int linkCenterY = link->plotY() + LK_SPRITE_HEIGHT / 2;
				if (linkCenterX > object->plotX() && linkCenterX < object->plotX() + DEELER_SPRITE_WIDTH)
				{
					if (linkCenterY > object->plotY() && linkCenterY < object->plotY() + DEELER_SPRITE_HEIGHT)
					{
						gameOver = true;
					}
				}
			}
		}
	}
	// this will pause the console before the "Game Over" text is rendered
	/*if (gameOver == true)
	{
		system("PAUSE");
	}*/
}
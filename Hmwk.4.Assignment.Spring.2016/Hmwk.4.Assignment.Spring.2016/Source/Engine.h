#ifndef ENGINE_H
#define ENGINE_H

#include <string>
#include "constants.h" 
#include "Link.h"
#include "Block.h"
#include "Object.h"

class Engine
{
public:
	Engine();
	void changeGameState(LK_TRANSITION);
	Object* getObject(int index);
	int getNumObjects();
	bool getGameOver();
private:
	int numObjects;
	Object** objects;
	bool gameOver;
};

#endif
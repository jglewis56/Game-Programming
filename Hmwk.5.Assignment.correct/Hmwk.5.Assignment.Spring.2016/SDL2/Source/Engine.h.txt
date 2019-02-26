#ifndef ENGINE_H
#define ENGINE_H

//System Headers
#include <string>
#include <vector>

//Game Headers
#include "Object.h"

using namespace std;

class Engine
{

public:

	//Constructor
	Engine();

	//Accessor Methods
	Object* getObject(int);
	int getNumObjects();
	bool getGameOver();
	bool getGameWon();

	//Game specific method
	void changeGameState(LK_TRANSITION);


private:

	vector<Object*> objects;
	bool gameOver;
	bool gameWon;
	int lastBlockX;

};

#endif
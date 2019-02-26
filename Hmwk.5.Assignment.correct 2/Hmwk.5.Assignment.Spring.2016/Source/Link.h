#ifndef Link_H
#define Link_H

//System Headers
#include <string>

//Game Headers
#include "Object.h"
#include "constants.h"

using namespace std;

class Link: public Object
{

public:

	Link(int,int, int);
	~Link();
	
	//Get Methods
	
	int getState() const;

	//Set Methods
	
	void setState(int);

	//Collision Detection method
	bool collisionDetected(Object*);

	//Animation Function		
	void update(LK_TRANSITION, vector<Object*> &);

protected:

	//Declare class specific properties
	int state;
	int animationID;
	bool collision;

	//Animation Storage
	int numStates;
	int* animationSize;
	int** animationMap;

	//Private functions to manipulate internal class state
	void loadAnimation(string);
	void updateSprite();
	void moveUp();
	void moveAttack();
	void moveDown();
	void moveLeft();
	void moveRight();
	void noAction();

};

#endif
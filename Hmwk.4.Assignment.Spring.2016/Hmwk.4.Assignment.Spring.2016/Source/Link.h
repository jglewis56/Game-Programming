#ifndef Link_H
#define Link_H

#include <string> 
#include "constants.h"
#include "Object.h"

using namespace std;
class Link : public Object
{
public:
	Link(int,int); 
	~Link();
	//Get Methods 
	int getState() const;
	//Set Methods 
	void setState(int); 
	//Animation Function 
	void update(LK_TRANSITION);
protected:
	float velY;
	//Declare  Link Properties 
	int state; 
	int animationID;
	//Storage 
	int numStates; 
	int* animationSize; 
	int** animationMap;
	//Private functions to manipulate internal Link state 
	void loadAnimation(string); 
	void updateSprite();
	void moveDown();
	void moveAttack();
	void moveLeft();
	void moveRight();
	void noAction();
};

#endif
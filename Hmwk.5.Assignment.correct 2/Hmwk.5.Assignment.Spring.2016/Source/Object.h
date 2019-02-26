#ifndef OBJECT_H
#define OBJECT_H

#include "constants.h"
#include <vector>
using namespace std;

class Object
{

public:

	Object(int,int, int);
	
	//Get Methods
	float getPosX() const;
	float getPosY() const;
	float getVelY() const;
	int getWidth() const;
	int getHeight() const;
	int getObjectID() const;
	int getSpriteID() const;

	//Set Methods
	void setPosX(float);
	void setPosY(float);
	void setVelY(float);
	void setWidth(int);
	void setHeight(int);
	void setObjectID(OBJECT_ID);
	void setSpriteID(int);

	//Plotting Methods
	int plotX();
	int plotY();

	//Animation Function		
	virtual void update(LK_TRANSITION, vector<Object*> &)=0;

protected:

	//Declare Object Properties
	float posX;
	float posY;
	float velY;
	int width;
	int height;

	OBJECT_ID objectID;
	int spriteID;

};

#endif
#ifndef LINK_H
#define LINK_H
#include <iostream>
#include <string>
#include "constants.h"
using namespace std;

class Link
{
private:
	float linkPosX;
	float linkPosY;
    int linkState;
	int linkSpriteID;
    int linkAnimID;
    int numStates;
	int* animationSize;
	int** animationMap;
	void updateSprite();
	void moveAttack();
	void moveDown();
	void moveLeft();
	void moveRight();
	void noAction();
	void loadAnimation(string);

public:
	Link();
	~Link();
	int getPosX() const;
	int getPosY() const;
	int getState() const;
	int getSpriteID() const;
	void setPosX(float x);
	void setPosY(float y);
	void setState(int);
	void setSpriteID(int);
	void update(LK_TRANSITION);
};
#endif
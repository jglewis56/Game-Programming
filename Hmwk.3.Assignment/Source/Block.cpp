#include <iostream>
#include "Block.h"
using namespace std;
//conversion constructor that initializes the blocks position

Block::Block(float x, float y)
{
	posX = x;
	posY = y;
	velY = 0;
	reached = false;
}
Block::~Block()
{

}

void Block::update(float linkPosX) // makes the block fall
{
	if (linkPosX > getPosX())
	{
		setReached(true);
	}
	if (getReached() == true)
	{
		velY = velY + (DELTA_T*GRAVITY); // the physics involved
		posY = posY + (DELTA_T*velY);
	}

}

int Block::getPosX() const // gets the blocks x position
{
	return posX;
}

int Block::getPosY() const // gets the y position
{
	return posY;
}
bool Block::getReached() // gets the reached bool
{
	return reached;
}
void Block::setPosX(float x)
{
	posX = x;
}
void Block::setPosY(float y)
{
	posY = y;
}
void Block::setReached(bool reached)
{
	this-> reached =reached;
}
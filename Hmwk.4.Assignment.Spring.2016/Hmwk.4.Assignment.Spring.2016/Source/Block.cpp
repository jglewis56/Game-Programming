#include <cmath> 
#include <iostream>

#include "constants.h"
#include "Block.h"	

using namespace std;

Block::Block(int posX, int posY) :Object(posX,posY)
{
	objectID = BLOCK;
}
void Block::update(LK_TRANSITION command)
{
	
}
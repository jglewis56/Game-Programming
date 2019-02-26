#include "constants.h"
#include "Deeler.h"	

using namespace std;

Deeler::Deeler(int posX, int posY, int velY):Object(posX,posY, velY)
{
	objectID = DEELER;
	width = DEELER_SPRITE_WIDTH;
	height = DEELER_SPRITE_HEIGHT;
	rise = true;
	moveCount = 0;
	moveCountMax = 50;
}

void Deeler::update(LK_TRANSITION command, vector<Object*> & objects)
{

	if(rise)
	{
		if(moveCount<moveCountMax)
		{
			posY-=DEELER_SPEED;
			moveCount++;
		}
		else
		{
			rise = false;
			moveCount = 0;
		}
	}
	else
	{
		if(moveCount<moveCountMax)
		{
			posY+=DEELER_SPEED;
			moveCount++;
		}
		else
		{
			rise = true;
			moveCount = 0;
		}
	}
}

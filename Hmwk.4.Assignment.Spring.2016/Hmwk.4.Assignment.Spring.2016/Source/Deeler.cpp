#include "constants.h"
#include "Deeler.h"	

using namespace std;
int objectID;

Deeler::Deeler(int posX, int posY):Object(posX,posY)
{
	objectID = DEELER;
	rise = true;
	moveCount = 0;
	moveCountMax = 50;
}
Deeler::Deeler()
{

}
// creates the moving dealer
void Deeler::update(LK_TRANSITION command)
{
	if (rise)
	{
		if (moveCount < moveCountMax)
		{
			posY -= DEELER_SPEED;
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
		if (moveCount < moveCountMax)
		{
			posY += DEELER_SPEED;
			moveCount++;
		}
		else
		{
			rise = true;
			moveCount = 0;
		}
	}
}
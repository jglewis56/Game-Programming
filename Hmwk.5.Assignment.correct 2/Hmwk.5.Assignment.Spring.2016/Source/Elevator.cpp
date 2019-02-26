#include "constants.h"
#include "Elevator.h"	


using namespace std;

Elevator::Elevator(int posX, int posY, int velY):Object(posX,posY, velY)
{
	objectID = ELEVATOR;
	width = ELEVATOR_SPRITE_WIDTH;
	height = ELEVATOR_SPRITE_HEIGHT;
}

void Elevator::update(LK_TRANSITION command, vector<Object*> & objects)
{
	switch (command)
	{
	case UP:
		posY = posY - BLOCK_SPRITE_HEIGHT;
		break;
	case DOWN:
		posY = posY + BLOCK_SPRITE_HEIGHT;
		break;
	default:
		break;
	}
}

#include "constants.h"
#include "Block.h"	

using namespace std;

Block::Block(int posX, int posY, int velY):Object(posX,posY, velY)
{
	objectID = BLOCK;
	width = BLOCK_SPRITE_WIDTH;
	height = BLOCK_SPRITE_HEIGHT;
}

void Block::update(LK_TRANSITION command, vector<Object*> & objects)
{
	

}

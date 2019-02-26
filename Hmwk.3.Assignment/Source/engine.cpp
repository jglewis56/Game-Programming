#include <iostream>
#include <fstream>
#include <string>

#include "engine.h"
#include "Link.h"

Block** constructBlocks(string file, int& numBlocks) //build the blocks based on the block configuration file
{
	fstream fin;
	fin.open(file, ios::in);
	fin >> numBlocks;

	float blockX, blockY;
	Block** blockArray = new Block*[numBlocks]; //create array of pointers with length equal numBlocks

	for (int i = 0; i<numBlocks; i++) //loop through the blocks and add a pointer to each one in the blockArray
	{
		fin >> blockX >> blockY;
		blockArray[i] = new Block(blockX, blockY);
	}

	return blockArray;
}

void changeGameState(LK_TRANSITION command, Link* link, Block** blocks, int numBlocks)
{
	link->Link::update(command); // updates link
	int linkPosX = link->Link::getPosX();


	for (int i = 0; i < numBlocks; i++)
	{
		blocks[i]->Block::update(linkPosX);
	}

	if (linkPosX == (SCREEN_WIDTH / 2 - LK_SPRITE_WIDTH) & command == RIGHT)
	{
		for (int j = 0; j < numBlocks; j++)
		{
			float blockX = blocks[j]->Block::getPosX();
			blocks[j]->Block::setPosX(blockX - LK_RUN_SPEED);// shifts the blocks over to the left
		}
	}
}
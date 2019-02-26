 #include <fstream>
#include <string>
#include <iostream>
#include "engine.h"
#include "constants.h"
#include <random>

using namespace std;
void loadBlockData(string sourcefile, int &numBlocks, int positionX[], int positionY[], bool topOfBlock[])
{
	int columnCount = 0;
	int rowCount = 0;
	int totColumnCount = 0;

	fstream fin;
	fin.open(sourcefile,ios::in);


	while (!fin.eof())
	{
		fin >> columnCount;
		fin >> rowCount;

		for (int k = 0;k < columnCount;k++)
		{
		
			for (int i = 0;i <= rowCount;i++)
			{
				positionX[numBlocks] = totColumnCount*BLOCK_SPRITE_WIDTH;
				positionY[numBlocks] = SCREEN_HEIGHT - BLOCK_SPRITE_HEIGHT*i;
				if (i == rowCount) //i ==(rowCount-1)
					topOfBlock[numBlocks] = true;
				else
					topOfBlock[numBlocks] = false;
				numBlocks++;
			}
		totColumnCount++;
	  }

	}
	fin.close();
}

void randomZelda2Data(int &linkPosX, int & linkPosY, int & linkSpriteID, int numBlocks, int blockPosX[], int blockPosY[], bool blockTop[])
{
	std::random_device rdev;
	static std::default_random_engine e(rdev());
	static std::uniform_int_distribution<int> xposition(0, SCREEN_WIDTH - Z2_SPRITE_WIDTH);
	static std::uniform_int_distribution<int> spriteID(0, 6);
	
	linkPosX = xposition(e);
	linkSpriteID = spriteID(e);
	linkPosY = getMaxYOfBlock(linkPosX, Z2_SPRITE_WIDTH, numBlocks, blockPosX, blockPosY, blockTop);

}

int getMaxYOfBlock(int x, int width, int numBlocks, int blockPosX[], int blockPosY[], bool blockTop[])
{
	int startingPoint= x;
	int endingPoint = startingPoint + width;
	int Y = SCREEN_HEIGHT;

	int k = 0;
	do
	{
		if (blockTop[k])
		{
			int Start = blockPosX[k];
			int End = blockPosX[k] + BLOCK_SPRITE_WIDTH;
			
			if (End >= startingPoint) 
				if (Start < startingPoint)
			{
				if (blockPosY[k] < Y)
					Y = blockPosY[k];
			}
			if (Start >= startingPoint)
				if(End <= endingPoint)
			{
				if (blockPosY[k] < Y)
					Y = blockPosY[k];
			}
		}
		k++;
	}
	while (k < numBlocks);
	return(Y - Z2_SPRITE_HEIGHT);
}
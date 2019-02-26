#ifndef ENGINE_H
#define ENGINE_H

#include <string>

using namespace std;

void loadBlockData(string, int &, int[], int[], bool[]);
void randomZelda2Data(int &, int &, int &, int, int[], int[], bool[]);
int getMaxYOfBlock(int x, int width, int numBlocks, int blockPosX[], int blockPosY[], bool blockTop[]);

#endif
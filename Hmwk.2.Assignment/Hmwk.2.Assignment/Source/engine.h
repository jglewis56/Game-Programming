#ifndef ENGINE_H
#define ENGINE_H

#include <string>
#include "constants.h"

using namespace std;

//Game Utilities
void loadAnimationMap(string gameFile, int & numStates, int* & sizeSequence, int** & sequence);
void initLinkData(int & linkPosX, int & linkPosY, LK_STATE & linkState, int & linkAnimID, int** animationMap, int & linkSpriteID);
void changeGameState(LK_TRANSITION command, int & linkPosX, int & linkPosY, LK_STATE & linkState, int & linkAnimID, int* animationSize, int** animationMap, int & linkSpriteID);

//Helper functions
void updateSprite(LK_STATE linkState, int & linkAnimID, int* animationSize, int** animationMap, int & linkSpriteID);
void moveAttack(LK_STATE & linkState, int & linkAnimID, int* animationSize, int** animationMap, int & linkSpriteID, int & linkPosX, int & linkPosY);
void moveDown(LK_STATE & linkState, int & linkAnimID, int* animationSize, int** animationMap, int & linkSpriteID, int & linkPosX, int & linkPosY);
void moveLeft(LK_STATE & linkState, int & linkAnimID, int* animationSize, int** animationMap, int & linkSpriteID, int & linkPosX, int & linkPosY);
void moveRight(LK_STATE & linkState, int & linkAnimID, int* animationSize, int** animationMap, int & linkSpriteID, int & linkPosX, int & linkPosY);
void noAction(LK_STATE & linkState, int & linkAnimID, int* animationSize, int** animationMap, int & linkSpriteID, int & linkPosX, int & linkPosY);

#endif
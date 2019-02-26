#ifndef ENGINE_H
#define ENGINE_H

#include <string>

#include "constants.h"
#include "Link.h"
#include "Block.h"

Block** constructBlocks(string,int&);
void changeGameState(LK_TRANSITION, Link*, Block**, int);

#endif
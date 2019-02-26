#ifndef CONSTANTS_H
#define CONSTANTS_H

//GUI Constants
const int SCREEN_WIDTH = 600;
const int SCREEN_HEIGHT = int(floor((float(2) / 3)*SCREEN_WIDTH));
const int SCREEN_BPP = 32;
const int FRAMES_PER_SECOND = 12;
const int FRAME_DELAY = 1000 / FRAMES_PER_SECOND;

//Animation Constants
enum LK_STATE { STILL_RIGHT, STILL_LEFT, WALK_RIGHT, WALK_LEFT, ATTACK_RIGHT, ATTACK_LEFT, CROUCH_RIGHT, CROUCH_LEFT };
enum LK_TRANSITION { UP, DOWN, LEFT, RIGHT, ATTACK, NA };
const int LK_WALK_SPEED = 6;



//LINK Constants
const int LK_NUM_SPRITES = 22;
const int LK_SPRITE_HEIGHT = 32;
const int LK_SPRITE_WIDTH = 16;


#endif
#ifndef CONSTANTS_H
#define CONSTANTS_H

//GUI Constants
const int SCREEN_WIDTH = 600;
const int SCREEN_HEIGHT = 400;
const int SCREEN_BPP = 32;
const int FRAMES_PER_SECOND = 25;
const int FRAME_DELAY = 1000/FRAMES_PER_SECOND;

//Animation Constants
enum LK_STATE { STILL_RIGHT, STILL_LEFT, WALK_RIGHT, WALK_LEFT, ATTACK_RIGHT, ATTACK_LEFT, CROUCH_RIGHT, CROUCH_LEFT };
enum LK_TRANSITION { UP, DOWN, LEFT, RIGHT, ATTACK, NA };
const int LK_RUN_SPEED = 12;
const int LK_CLIMB_SPEED = 6;
const int DEELER_SPEED = 2;

//Object Constants
enum OBJECT_ID {OBJECT,LINK,BLOCK,DEELER,ELEVATOR};

//Physics Constants
const float DELTA_T = 0.1f;
const float GRAVITY = 5.0f;

//Link Constants
const int LK_NUM_SPRITES = 22;
const int LK_SPRITE_HEIGHT = 32;
const int LK_SPRITE_WIDTH = 16;

//Block Constants
const int BLOCK_SPRITE_HEIGHT = 20;
const int BLOCK_SPRITE_WIDTH = 20;

//Deeler Constants
const int DEELER_SPRITE_HEIGHT = 16;
const int DEELER_SPRITE_WIDTH = 16;

//Elevator constants
const int ELEVATOR_SPRITE_HEIGHT = 48;
const int ELEVATOR_SPRITE_WIDTH = 24;

#endif
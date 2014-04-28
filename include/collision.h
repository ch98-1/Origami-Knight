#ifndef _COLLISION_H_
    #define _COLLISION_H_
//ork stands for Origami Knight

#include "all.h"

//character movement function with collision detection
//returns 1 for no collision and 0 for collision 
//returns 2 if it moved the screen position
//it may be moved even with collision
//don't put large value in because character may look like it is floating
//mpos is x and y movement of sprite
//pointer for linked list of collision boxes
int move(struct pos mpos, struct objects* pos);
 
#endif
#ifndef _ALL_H_
    #define _ALL_H_

#include "SDL.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//object linked list structure
struct objects{
	char name[15];
	char idef[10];
	SDL_Rect image;
	SDL_Rect cbox;
	struct objects* next;
};
 
struct objects* lpos;

struct pos{
	float x;
	float y;
};


//player position and camera position
struct pos ppos;
struct pos cpos;

//player hight and with
struct pos psize;

//player accelelation and gravity
struct pos acc;
struct pos grav;

//player jump power
struct pos maxp;

//ground and air risistance
struct pos gris;
struct pos aris;

//power when kicking or jumping vertically (like kicking sideways for jumping up) stands for wall kick.
struct pos wk;

void init();


#endif

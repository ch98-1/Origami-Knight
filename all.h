#ifndef _ALL_H_
    #define _ALL_H_

#include "SDL.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//object linked list structure
struct objects{
	long wid;
	char name[15];
	char idef[10];
	SDL_Rect image;
	SDL_Rect cbox;
	struct objects* next;
};
 
struct objects* lpos;

struct pos{
	long x;
	long y;
};


#endif
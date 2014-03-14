#ifndef _ORK_H_
    #define _ORK_H_
//ork stands for Origami Knight
#include "SDL.h"
#include <stdio.h>
#include <stdlib.h>
//including all things

void sprite (SDL_Surface* image,
                SDL_Surface* screen,
                int sorX, int sorY,
                int scrX, int scrY,
                int width, int height,
		int zoom, int cr,
		int cg, int cb);

 
#endif

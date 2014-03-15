#ifndef _SPRITE_H_
    #define _SPRITE_H_

#include "SDL.h"
#include <stdio.h>
#include <stdlib.h>

void sprite (SDL_Surface* image,
                SDL_Surface* screen,
                int sorX, int sorY,
                int scrX, int scrY,
                int width, int height,
		int cr,
		int cg, int cb);
#endif

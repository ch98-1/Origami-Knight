#ifndef _SPRITE_H_
    #define _SPRITE_H_

#include "SDL.h"
#include <stdio.h>
#include <stdlib.h>


//draw sprite
void dsprite (SDL_Renderer* ren,
                SDL_Texture* tex,
                int sorX, int sorY,
                int scrX, int scrY,
                int width, int height);
#endif

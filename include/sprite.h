#ifndef _SPRITE_H_
    #define _SPRITE_H_


#include "all.h"


//draw sprite
void dsprite(SDL_Renderer* ren,
			SDL_Texture* tex,
			struct pos sor,
			struct pos map,
			int width, int height,
			float zoom);

#endif

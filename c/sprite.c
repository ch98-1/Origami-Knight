#include "sprite.h"

//draw sprite function
//sor is source x and y pos
//scr is screen x and y pos
//width and height is size of image


void dsprite (SDL_Renderer* ren,
                SDL_Texture* tex,
                int sorX, int sorY,
                int scrX, int scrY,
                int width, int height)
{

    // Part of the bitmap that we want to draw
   SDL_Rect source;
   source.x = sorX;
   source.y = sorY;
   source.w = width;
   source.h = height;

   // Part of the screen we want to draw the sprite to
   SDL_Rect destination;
   destination.x = scrX;
   destination.y = scrY;
   destination.w = width;
   destination.h = height;
	SDL_RenderCopy(ren, tex, &source, &destination);
}



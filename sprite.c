#include "sprite.h"


//sor is source x and y pos
//scr is screen x and y pos
//width and height is size of image
//cr, cg, cb is clear pixel's rgb

void sprite (SDL_Surface* image,
                SDL_Surface* screen,
                int sorX, int sorY,
                int scrX, int scrY,
                int width, int height,
		int cr,
		int cg, int cb)
{
SDL_SetColorKey( image, SDL_TRUE, SDL_MapRGB(image->format, cr, cg, cb) ); 
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
	SDL_BlitSurface(image, &source, screen, &destination);
}






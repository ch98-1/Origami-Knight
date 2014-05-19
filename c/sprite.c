#include "sprite.h"

//draw sprite function
//sor is source x and y pos
//map is map x and y pos
//width and height is size of image
//zoom is size compared to original


void dsprite (SDL_Renderer* ren,
                SDL_Texture* tex,
                struct pos sor,
				struct pos map,
                int width, int height,
				float zoom)
{

    // Part of the bitmap that we want to draw
   SDL_Rect source;
   source.x = sor.x;
   source.y = sor.y;
   source.w = width;
   source.h = height;

   // Part of the screen we want to draw the sprite to
   SDL_Rect destination;
   destination.x = map.x - rm.cpos.x;
   destination.y = map.y - rm.cpos.y;
   destination.w = width*zoom;
   destination.h = height*zoom;
	SDL_RenderCopy(ren, tex, &source, &destination);
}



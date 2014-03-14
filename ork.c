#include "ork.h"

int main (int argc, char *argv[])
{
//no function is used to make stuff simpler
SDL_Init(SDL_INIT_EVERYTHING);

    SDL_Window *window;                    // Declare a pointer

    window = SDL_CreateWindow(
        "An SDL2 window",                  // window title
        SDL_WINDOWPOS_UNDEFINED,           // initial x position
        SDL_WINDOWPOS_UNDEFINED,           // initial y position
        640,                               // width, in pixels
        480,                               // height, in pixels
        SDL_WINDOW_OPENGL                  // flags - see below
    );
    if (window == NULL) {
        // If window could not be made...
        printf("Could not create window: %s\n", SDL_GetError());
        return 1;
    }
    //load bmp
    SDL_Surface* box = SDL_LoadBMP("media/box.bmp");

    SDL_Surface* screen = SDL_GetWindowSurface( window );
  
    sprite (box, screen, 0, 0, 50, 50, 250, 193, 1, 255, 0, 255);

    SDL_UpdateWindowSurface( window );

    SDL_Delay(3000);  // Pause execution for 3000 milliseconds

    // clear screen
    SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 0, 0, 0));

    //free opend surface 
    SDL_FreeSurface(box);

    // Close and destroy the window
    SDL_DestroyWindow(window);

    // Clean up
    SDL_Quit();
}



//sor is source x and y pos
//scr is screen x and y pos
//width and height is size of image
//zoom is size of image
//cr, cg, cb is clear pixel's rgb

void sprite (SDL_Surface* image,
                SDL_Surface* screen,
                int sorX, int sorY,
                int scrX, int scrY,
                int width, int height,
		int zoom, int cr,
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
   destination.w = width * zoom;
   destination.h = height * zoom;
	SDL_BlitSurface(image, &source, screen, &destination);
}






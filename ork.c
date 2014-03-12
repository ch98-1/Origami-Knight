#include "ork.h"

int main (int argc, char *argv[])
{
//no function is used to make stuff simpler
SDL_Init(SDL_INIT_EVERYTHING);
IMG_Init(IMG_INIT_JPG);


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
SDL_Surface* box = NULL;
SDL_Renderer *ren = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
box = IMG_Load("box.jpg");
SDL_Texture *tex = SDL_CreateTextureFromSurface(ren, box);
SDL_FreeSurface(box);
SDL_RenderClear(ren);
SDL_RenderCopy(ren, tex, NULL, NULL);
SDL_RenderPresent(ren);

    SDL_Delay(3000);  // Pause execution for 3000 milliseconds
     

    SDL_DestroyTexture(tex);
    SDL_DestroyRenderer(ren);
    // quit SDL_image
    IMG_Quit();

    // Close and destroy the window
    SDL_DestroyWindow(window);

    // Clean up
    SDL_Quit();
}









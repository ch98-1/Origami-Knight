#include "ork.h"

int main (int argc, char *argv[])
{
init();
    SDL_Window *window;                    // Declare a pointer

//to be in init
    SDL_Init(SDL_INIT_VIDEO);
    window = SDL_CreateWindow(
        "An SDL2 window",                  // window title
        SDL_WINDOWPOS_UNDEFINED,           // initial x position
        SDL_WINDOWPOS_UNDEFINED,           // initial y position
        640,                               // width, in pixels
        480,                               // height, in pixels
        SDL_WINDOW_OPENGL                  // flags - see below
    );
    if (window == NULL) {
        // In the event that the window could not be made...
        printf("Could not create window: %s\n", SDL_GetError());
        return 1;
    }
//to be in init

    SDL_Delay(3000);  // Pause execution for 3000 milliseconds, for example
cleanup(window);
}

int init ()
{


}

int cleanup (unsigned long *window)
{

    // Close and destroy the window
    SDL_DestroyWindow(window);

    // Clean up
    SDL_Quit();
}


#include "ork.h"

int main()
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
        SDL_WINDOW_OPENGL|SDL_WINDOW_RESIZABLE                
 // flags 
    );
    if (window == NULL) {
        // If window could not be made...
        printf("Could not create window: %s\n", SDL_GetError());
        return 1;
    }

 
    //create renderer
    SDL_Renderer* screen = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

	//Event handler
	SDL_Event ev;

	//player position having problem with structures 
	int pposx = 100;
	int pposy = 100;


    //load bmp
    SDL_Surface* box = SDL_LoadBMP("media/image/box.bmp");
    SDL_Surface* ork = SDL_LoadBMP("media/image/Gami_2.bmp");
    //set clear
    SDL_SetColorKey( box, SDL_TRUE, SDL_MapRGB(box->format, 255, 0, 255) ); 
	SDL_SetColorKey( ork, SDL_TRUE, SDL_MapRGB(box->format, 255, 0, 255));
    //create texture
    SDL_Texture* Ork = SDL_CreateTextureFromSurface(screen,ork);
    SDL_Texture* Box = SDL_CreateTextureFromSurface(screen,box);
    //free opend surface 
    SDL_FreeSurface(box);
    SDL_FreeSurface(ork);

	//main loop
	while (quit == 0)
	{
		//event handling
		//Handle events on queue
		while (SDL_PollEvent(&ev) != 0)
		{

			switch (ev.type)
			{

			//User requests quit
			case SDL_QUIT:
					quit = 1;
				break;

			//User presses a key
			case SDL_KEYDOWN:

				//Select surfaces based on key press
				switch (ev.key.keysym.sym)
				{
				case SDLK_UP:
						pposy = pposy - 3;
					break;

				case SDLK_DOWN:
						pposy = pposy + 3;
					break;

				default:
						
					break;
				}

				break;
			default:
				break;
			}
		}

		//key DETECTION
		const Uint8 *state = SDL_GetKeyboardState(NULL);
		if (state[SDL_SCANCODE_LEFT]) {
			pposx = pposx - 3;
		}
		if (state[SDL_SCANCODE_RIGHT]) {
			pposx = pposx + 3;
		}



		//clear
		SDL_RenderClear(screen);
		//draw
		dsprite(screen, Box, 0, 0, 50, 50, 250, 193);
		dsprite(screen, Ork, 0, 0, pposx, pposy, 32, 32);
		//update
		SDL_RenderPresent(screen);
		SDL_Delay(10);  // Pause execution for 10 milliseconds
	}

    // clear screen
    SDL_RenderClear(screen);


    //free all textures
    SDL_DestroyTexture(Ork);
    SDL_DestroyTexture(Box);

    //Destroy Renderer
    SDL_DestroyRenderer(screen);
    // Close and destroy the window
    SDL_DestroyWindow(window);

    // Clean up
    SDL_Quit();
}

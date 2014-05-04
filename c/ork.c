#include "ork.h"

int main()
{

init();

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

	//player position 
	ppos.x = 320;
	ppos.y = 240;

	//player hight (y) and with (x)
	psize.x = 32;
	psize.y = 32;


    //create texture
    SDL_Texture* Ork = limg("Gami_2", screen);
	SDL_Texture* Box = limg("box", screen);
	SDL_Texture* ch98 = limg("ch98", screen);


	//set draw color
	SDL_SetRenderDrawColor(screen, 200, 200, 200, 255);

	//movement position structure
	struct pos mpos;


	//main loop
	while (quit == 0)
	{
		mpos.x = 0;
		mpos.y = 0;
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
						mpos.y = mpos.y - 3;
					break;

				case SDLK_DOWN:
						mpos.y = mpos.y + 3;
					break;

				case SDLK_LEFT:
					mpos.x = mpos.x - 1;
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
			mpos.x = mpos.x - 3;
		}
		if (state[SDL_SCANCODE_RIGHT]) {
			mpos.x = mpos.x + 3;
		}
		if (state[SDL_SCANCODE_UP]) {
			mpos.y = mpos.y - 1;
		}
		if (state[SDL_SCANCODE_DOWN]) {
			mpos.y = mpos.y + 1;
		}

		//window with and window hight
		int* ww;
		int* wh;

		//get window size seem to stop something from working
		SDL_GetWindowSize(window, &ww, &wh);

		
		//fake gravity
		mpos.y = mpos.y + 1;

		//movement position for only x and y
		struct pos mposx;
		struct pos mposy;
		mposx.x = mpos.x;
		mposx.y = 0;
		mposy.y = mpos.y;
		mposy.x = 0;

		//move function with collision detection
		move(mposx, lpos, ww, wh);
		move(mposy, lpos, ww, wh);


		//box position and ch98 block position 
		struct pos boxp;
		boxp.x = 50;
		boxp.y = 50;
		struct pos ch98p;
		ch98p.x = 100;
		ch98p.y = 100;
		//0,0 position
		struct pos opos;
		opos.x = 0;
		opos.y = 0;


		//clear
		SDL_RenderClear(screen);
		//draw
		dsprite(screen, ch98, opos, ch98p, 200, 200, 0.5);
		dsprite(screen, Box, opos, boxp, 250, 193, 0.3);
		dsprite(screen, Ork, opos, ppos, psize.x, psize.y, 1);
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

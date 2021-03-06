#include "ork.h"

int main()
{

init();

//no function is used to make stuff simpler
SDL_Init(SDL_INIT_EVERYTHING);

    SDL_Window *window;                    // Declare a pointer

    window = SDL_CreateWindow(
        wtitle,                  // window title
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

	//set last frame time and last FPS time to now
	lft = SDL_GetTicks();
	lfps = SDL_GetTicks();
	lfpss = SDL_GetTicks();


 
    //create renderer
    SDL_Renderer* screen = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

	//Event handler
	SDL_Event ev;



    //create texture
    SDL_Texture* Ork = limg("Gami_2", screen);
	SDL_Texture* Box = limg("box", screen);
	SDL_Texture* ch98 = limg("ch98", screen);


	//set draw color
	SDL_SetRenderDrawColor(screen, 200, 200, 200, 255);

	//movement position structure
	struct pos mpos;

	//collision detection result
	struct pos col;
	col.x = 0;
	col.y = 0;


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
				switch (ev.key.keysym.sym)
				{
				case SDLK_UP: //jump up
						//if keypress is up
					break;

				case SDLK_DOWN:
						//if keypress is down
					break;

				case SDLK_LEFT:
						//if keypress is left
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
			mpos.x = mpos.x - 0;
			if (!col.x){
				pl.acc.x = pl.acc.x - pl.maxp.x;
			}
			if (!col.y){
				pl.acc.x = pl.acc.x - (pl.maxp.x * pl.wk.x);
			}
		}
		if (state[SDL_SCANCODE_RIGHT]) {
			mpos.x = mpos.x + 0;
			if (!col.x){
				pl.acc.x = pl.acc.x + pl.maxp.x;
			}
			if (!col.y){
				pl.acc.x = pl.acc.x + (pl.maxp.x * pl.wk.x);
			}
		}
		if (state[SDL_SCANCODE_UP]) {
			if (!col.y){
				pl.acc.y = pl.acc.y - pl.maxp.y;
			}
			if (!col.x){
				pl.acc.y = pl.acc.y - (pl.maxp.y * pl.wk.y);
			}
		}
		if (state[SDL_SCANCODE_DOWN]) {
			//if keydown is down
		}

		//window with and window hight
		int* ww;
		int* wh;

		//get window size seem to stop something from working
		SDL_GetWindowSize(window, &ww, &wh);


		//ground and air risistance
		if (!col.y){
			pl.acc.x = pl.acc.x - (pl.acc.x * pl.gris.x);
		}
		else{
			pl.acc.x = pl.acc.x - (pl.acc.x * pl.aris.x);
		}
		if (!col.x){
			pl.acc.y = pl.acc.y - (pl.acc.y * pl.gris.y);
		}
		else{
			pl.acc.y = pl.acc.y - (pl.acc.y * pl.aris.y);
		}

		
		//gravity and accelelation 
		pl.acc.y = pl.acc.y + pl.grav.y;
		pl.acc.x = pl.acc.x + pl.grav.x;

		//movement position for only x and y
		struct pos mposx;
		struct pos mposy;
		mposx.x = mpos.x + pl.acc.x;
		mposx.y = 0;
		mposy.y = mpos.y + pl.acc.y;
		mposy.x = 0;


		//move function with collision detection
		col.x = move(mposx, ww, wh);
		col.y = move(mposy, ww, wh);

		//gravity, accelelation reset
		if (!col.x){
			pl.acc.x = 0;
		}
		else if (!col.y){
			pl.acc.y = 0;
		}


		//box position and ch98 block position 
		struct pos boxp;
		boxp.x = 50;
		boxp.y = 50;
		struct pos ch98p;
		ch98p.x = 200;
		ch98p.y = 200;
		//0,0 position
		struct pos opos;
		opos.x = 0;
		opos.y = 0;


		//clear
		SDL_RenderClear(screen);
		//draw
		dsprite(screen, ch98, opos, ch98p, 200, 200, 0.5);
		dsprite(screen, Box, opos, boxp, 250, 193, 0.3);
		dsprite(screen, Ork, opos, pl.ppos, pl.psize.x, pl.psize.y, 1);
		//update
		SDL_RenderPresent(screen);
		if (16 > (SDL_GetTicks() - lft) ) {
			SDL_Delay(16 - (SDL_GetTicks() - lft));  // Pause execution for 16 milliseconds from last  frame
		}
		lft = SDL_GetTicks();
		fps = (float)1000/(SDL_GetTicks() - lfps);
		lfps = SDL_GetTicks();
		if (1000 < (SDL_GetTicks() - lfpss) ){
			strcpy(wtitle, "Origami Knight ");
			char sfps[10];
			sprintf(sfps, "%.1f", fps);
			strcat(wtitle, sfps);
			strcat(wtitle, "fps");
			SDL_SetWindowTitle(window, wtitle);
			lfpss = SDL_GetTicks();
		}
	}

    // clear screen
    SDL_RenderClear(screen);


    //free all textures
    SDL_DestroyTexture(Ork);
	SDL_DestroyTexture(Box);
	SDL_DestroyTexture(ch98);

    //Destroy Renderer
    SDL_DestroyRenderer(screen);
    // Close and destroy the window
    SDL_DestroyWindow(window);

    // Clean up
    SDL_Quit();
}

#include "imagel.h"

//imput array pointer and it filles it up

//load texture "name" in image folder of media  
//
SDL_Texture* limg(const char* name, SDL_Renderer* ren)
{
	char dir[300] = "media/image/";
	strcat(dir, name);
	strcat(dir, ".bmp");
	//load bmp
	SDL_Surface* surface = SDL_LoadBMP(dir);
	//set clear
	SDL_SetColorKey(surface, SDL_TRUE, SDL_MapRGB(surface->format, 255, 0, 255));
	//create texture
	return SDL_CreateTextureFromSurface(ren, surface);
	//free opend surface 
	SDL_FreeSurface(surface);
}
#ifndef _ORK_H_
    #define _ORK_H_
//ork stands for Origami Knight
#include "SDL.h"
#include "SDL_image.h"
#include <stdio.h>
#include <stdlib.h>
//including all things

int init ();
int event ();
int loop ();
int render ();
int cleanup (unsigned long *window, unsigned long *box);
 
#endif

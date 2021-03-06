#ifndef _ALL_H_
    #define _ALL_H_

#include "SDL.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct mapobj{//linked list of objects in sections of the map
	int objid;//object id on object array
	SDL_Rect cbox;
	int dint[4];//integer data for each objects in map
	struct mapobj* next;
}mapobj;

//test map object section
mapobj* tmaps;


struct arpam{//map of an area
	char name[15]; //file name of the area
	mapobj* map[50][50];//it can get bigger
};

struct objid{//map object id
	int oid;//object id
	int movement;//how it moves
};

struct pos{//simplex and y position. may be used as hight and with
	float x;
	float y;
};

struct pobj{//plater object defenition
	//object position and camera position
	struct pos ppos;
	struct pos cpos;

	//object hight and with
	struct pos psize;

	//object accelelation and gravity
	struct pos acc;
	struct pos grav;

	//object jump power
	struct pos maxp;

	//ground and air risistance 
	struct pos gris;
	struct pos aris;

	//power when kicking or jumping vertically (like kicking sideways for jumping up) stands for wall kick.
	struct pos wk;

};

struct objmov{
	short unsigned int mtf; //if it can move, it is true (1 or more) 0 or false for immovable object
	struct pos acc;//object accelelation
	struct pos grav;//object personal gravity
	//ground and air risistance 
	struct pos gris;
	struct pos aris;
	//object hight and with
	struct pos psize;
	//power when kicking or jumping vertically (like kicking sideways for jumping up) stands for wall kick.
	struct pos wk;
};

struct objint{
	short unsigned int collision;//true or false of if it will collide
};

//set object defenition structure as type
//object defenition structure
typedef struct objects{
	char name[8];//name of image
	struct objmov mov;//object movemend defenition
	struct objint ia;//object interaction defenition
	struct pos image;//image with and hight
}object;


//list of all possible obects including all possible players.
object obj[1000];

//player initial settings
struct pobj pl;

//time of last frame and last FPS last FPS shown
unsigned int lft;
unsigned int lfps;
unsigned int lfpss;

//window title
char wtitle[50];

//frame per second
float fps;

//init function
void init();


#endif

#include "all.h"



//set game to starting point
//movement is pixel per second
void init()
{
	pl.cpos.x = 0;
	pl.cpos.y = 0;
	pl.acc.x = 0;
	pl.acc.y = 0;
	pl.grav.x = 0;
	pl.grav.y = 3;
	pl.maxp.x = 5;
	pl.maxp.y = 300;
	pl.gris.x = 0.5;
	pl.gris.y = 0.2;
	pl.aris.x = 0.02;
	pl.aris.y = 0.02;
	pl.wk.x = 30;
	pl.wk.y = 30;
	pl.ppos.x = 225;
	pl.ppos.y = 150;
	pl.psize.x = 32;
	pl.psize.y = 32;
	strcpy(wtitle, "Origami Knight");
	fps = 60;
}
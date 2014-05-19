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
	pl.grav.y = 0.05;
	pl.maxp.x = 5;
	pl.maxp.y = 5;
	pl.gris.x = 0.5;
	pl.gris.y = 0.2;
	pl.aris.x = 0.02;
	pl.aris.y = 0.02;
	pl.wk.x = 0.5;
	pl.wk.y = 0.5;
	rm.cpos.x = 0;
	rm.cpos.y = 0;
	rm.acc.x = 0;
	rm.acc.y = 0;
	rm.grav.x = 0;
	rm.grav.y = 0.05;
	rm.maxp.x = 5;
	rm.maxp.y = 5;
	rm.gris.x = 0.5;
	rm.gris.y = 0.2;
	rm.aris.x = 0.02;
	rm.aris.y = 0.02;
	rm.wk.x = 0.5;
	rm.wk.y = 0.5;
	rm.ppos.x = 225;
	rm.ppos.y = 150;
	rm.psize.x = 32;
	rm.psize.y = 32;
	frame = 0;
}
#include "collision.h"

int move(struct pos mpos, int w, int h)
{

	//SDL_Rect structure for testing the collision
	SDL_Rect cbox;
	cbox.x = 200;
	cbox.y = 200;
	cbox.w = 100;
	cbox.h = 100;

	mpos.x = mpos.x / fps;
	mpos.y = mpos.y / fps;


	int n = 0;//object list number
	int c = 0;//check for collision with while loop
	int end = 0;//if while loop ends or not
	while (!end){
		n++;
		if (!(cbox.x >= pl.ppos.x + mpos.x + pl.psize.x || cbox.x + cbox.w <= pl.ppos.x + mpos.x || cbox.y >= pl.ppos.y + mpos.y + pl.psize.y || cbox.y + cbox.h <= pl.ppos.y + mpos.y)){
			c = 1;
			return 0;
		}
		if (1){//if it hits end of map objects list
			end = 1;
		}
	}
	if (!c){//ckeck if it colided then if it is within about 50 pixel from window border
		if (pl.ppos.x + mpos.x <= pl.cpos.x + 50 || pl.ppos.x + mpos.x >= pl.cpos.x + w - 80 || pl.ppos.y + mpos.y <= pl.cpos.y + 50 || pl.ppos.y + mpos.y >= pl.cpos.y + h - 80){
			pl.cpos.x = pl.cpos.x + mpos.x;
			pl.cpos.y = pl.cpos.y + mpos.y;
			pl.ppos.x = pl.ppos.x + mpos.x;
			pl.ppos.y = pl.ppos.y + mpos.y;
			return 2;
		}
		//when there is no border collision
		else {
			pl.ppos.x = pl.ppos.x + mpos.x;
			pl.ppos.y = pl.ppos.y + mpos.y;
			return 1;
		}
	}
}
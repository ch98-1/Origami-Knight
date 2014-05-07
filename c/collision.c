#include "collision.h"

int move(struct pos mpos, struct objects* pos, int w, int h)
{

	//SDL_Rect structure for testing the collision
	SDL_Rect cbox;
	cbox.x = 200;
	cbox.y = 200;
	cbox.w = 100;
	cbox.h = 100;


	int n = 0;//object list number
	int c = 0;//check for collision with while loop
	int end = 0;//if while loop ends or not
	while (!end){
		n++;
		if (!(cbox.x >= ppos.x + mpos.x + psize.x || cbox.x + cbox.w <= ppos.x + mpos.x || cbox.y >= ppos.y + mpos.y + psize.y || cbox.y + cbox.h <= ppos.y + mpos.y)){
			c = 1;
			return 0;
		}
		if (1){//if it hits end of map objects list
			end = 1;
		}
	}
	if (!c){//ckeck if it colided then if it is within about 50 pixel from window border
		if (ppos.x + mpos.x <= cpos.x + 50 || ppos.x + mpos.x >= cpos.x + w - 80 || ppos.y + mpos.y <= cpos.y + 50 || ppos.y + mpos.y >= cpos.y + h - 80){
			cpos.x = cpos.x + mpos.x;
			cpos.y = cpos.y + mpos.y;
			ppos.x = ppos.x + mpos.x;
			ppos.y = ppos.y + mpos.y;
			return 2;
		}
		//when there is no border collision
		else {
			ppos.x = ppos.x + mpos.x;
			ppos.y = ppos.y + mpos.y;
			return 1;
		}
	}
}
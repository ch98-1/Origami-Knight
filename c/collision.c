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
		if (!(cbox.x >= rm.ppos.x + mpos.x + rm.psize.x || cbox.x + cbox.w <= rm.ppos.x + mpos.x || cbox.y >= rm.ppos.y + mpos.y + rm.psize.y || cbox.y + cbox.h <= rm.ppos.y + mpos.y)){
			c = 1;
			return 0;
		}
		if (1){//if it hits end of map objects list
			end = 1;
		}
	}
	if (!c){//ckeck if it colided then if it is within about 50 pixel from window border
		if (rm.ppos.x + mpos.x <= rm.cpos.x + 50 || rm.ppos.x + mpos.x >= rm.cpos.x + w - 80 || rm.ppos.y + mpos.y <= rm.cpos.y + 50 || rm.ppos.y + mpos.y >= rm.cpos.y + h - 80){
			rm.cpos.x = rm.cpos.x + mpos.x;
			rm.cpos.y = rm.cpos.y + mpos.y;
			rm.ppos.x = rm.ppos.x + mpos.x;
			rm.ppos.y = rm.ppos.y + mpos.y;
			return 2;
		}
		//when there is no border collision
		else {
			rm.ppos.x = rm.ppos.x + mpos.x;
			rm.ppos.y = rm.ppos.y + mpos.y;
			return 1;
		}
	}
}
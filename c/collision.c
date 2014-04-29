#include "collision.h"

int move(struct pos mpos, struct objects* pos, int w, int h)
{
	if (ppos.x + mpos.x <= cpos.x + 50 || ppos.x + mpos.x >= cpos.x + w - 80|| ppos.y + mpos.y <= cpos.y + 50 || ppos.y + mpos.y >= cpos.y + h - 80 ){
		cpos.x = cpos.x + mpos.x;
		cpos.y = cpos.y + mpos.y;
		ppos.x = ppos.x + mpos.x;
		ppos.y = ppos.y + mpos.y;
		return 2;
	}
	else {
		ppos.x = ppos.x + mpos.x;
		ppos.y = ppos.y + mpos.y;
		return 1;
	}
}
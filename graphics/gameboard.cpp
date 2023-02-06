#include"graphics.h"
void gameboard() {
	//initialize the gameboard.
	initwindow(540, 540, "PENTAGOL");
	setfillstyle(1, 4);
	bar(60, 60, 480, 480);
	setcolor(15);
	line(270, 60, 270, 480);
	line(60, 270, 480, 270);
	int i=0, j=0;
	for (j = 120; j <= 420; j = j + 60) {
		for (i = 120; i <= 420; i = i + 60) {
			setcolor(15);
			circle(i, j, 15);
		}
	}
}

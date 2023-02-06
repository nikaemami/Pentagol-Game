#include"graphics.h"
void place_marble(char table[6][6]) {
//check which circle the player chose, to color it black or white
	int i=0, j=0;
	for (j = 120; j <= 420; j = j + 60) {
		for (i = 120; i <= 420; i = i + 60) {
			if (table[j / 60 - 2][i / 60 - 2] == 'b') {
				setcolor(0);
				setfillstyle(1, 0);
				fillellipse(i, j, 15, 15);
			}
			else if (table[j / 60 - 2][i / 60 - 2] == 'w') {
				setcolor(15);
				setfillstyle(1, 15);
				fillellipse(i, j, 15, 15);
			}
		}
	}
	}

		

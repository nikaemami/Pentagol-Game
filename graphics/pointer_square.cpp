#include"graphics.h"
void pointer_square(char table[6][6], char symbol,int turn) {
	int value = 1;
	char input;
	int x1 = 115, x2 = 125, y1 = 115, y2 = 125;
	do {
		input = getch();
		//moving the pointer square from a circle to another one
			if (table[(y1 + 5) / 60 - 2][(x1 + 5) / 60 - 2] == 'w') {
				setcolor(15);
				rectangle(x1, y1, x2, y2);
			}
			else if (table[(y1 + 5) / 60 - 2][(x1 + 5) / 60 - 2] == 'b') {
				setcolor(0);
				rectangle(x1, y1, x2, y2);
			}
		else {
			setcolor(4);
			rectangle(x1, y1, x2, y2);
		}

		//get the direction of moving from keyboard
		if (input == 'd') {
			x1 = x1 + 60;
			x2 = x2 + 60;
			value = 2;
		}
		else if (input == 'a') {
			x1 = x1 - 60;
			x2 = x2 - 60;
			value = 2;
		}
		else if (input == 'w') {
			y1 = y1 - 60;
			y2 = y2 - 60;
			value = 2;
		}
		else if (input == 's') {
			y1 = y1 + 60;
			y2 = y2 + 60;
			value = 2;
		}
		else if (input == 'f') {
			if (table[(y1 + 5) / 60 - 2][(x1 + 5) / 60 - 2] == '.') { //check if the place on board is empty
				table[(y1 + 5) / 60 - 2][(x1 + 5) / 60 - 2] = symbol;
				value = 1;
			}
			else {
				setcolor(0);
				setfillstyle(1, 0);
				bar(100, 10, 380, 50);
				setcolor(14);
				outtextxy(160, 30, "already full. choose another one.");
				value = 2;
			}
		}
		//check if input is valid
		else {
			setcolor(0);
			setfillstyle(1, 0);
			bar(100, 10, 380, 50);
			setcolor(14);
			outtextxy(170, 30, "Invalid input.Try again");
			value = 2;
		}
		
		//pointer square should not exit the red board.(if it's on the edge, it should not move.)
		if (y1 == 55) {
			y1 = y1 + 60;
			y2 = y2 + 60;
		}
		else if (y2 == 485) {
			y1 = y1 - 60;
			y2 = y2 - 60;
		}
		else if (x1 == 55) {
			x1 = x1 + 60;
			x2 = x2 + 60;
		}
		else if (x2 == 485) {
			x1 = x1 - 60;
			x2 = x2 - 60;
		}
		setcolor(14);
		rectangle(x1, y1, x2, y2);
		//

	} while (value == 2);
	//if f is pressed on keyboard, marble should be placed
	if (turn % 2 == 0) {
		setcolor(0);
		setfillstyle(1, 0);
		fillellipse(x1 + 5, y1 + 5, 15, 15);
	}
	else if (turn % 2 == 1) {
		setcolor(15);
		setfillstyle(1, 15);
		fillellipse(x1 + 5, y1 + 5, 15, 15);
	}
	
	//

}

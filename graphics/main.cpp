#include<stdio.h>
#include"graphics.h"
#include"gameboard.h"
#include"pointer_square.h"
#include"place_marble.h"
#include"rotate.h"
#include"winning_condition.h"
int main() {

	//assign each circle to an element of an array.
	int i=0, j=0;
	char table[6][6];
    char alternative[6][6];
	for (j = 120; j <= 420; j = j + 60) {
		for (i = 120; i <= 420; i = i + 60) {
				table[j / 60 - 2][i /60 - 2] = '.' ;
		}
	}
	
	//initialize game board
	gameboard();
	int turn = 0;
	char symbol;
    int main_value[1];  //an array as an argument and return value to check winning condition.
    main_value[0]=1;
	do {

		//draw the pointer square in the first circle
	int x1 = 115, x2 = 125, y1 = 115, y2 = 125;
	setcolor(14);
	rectangle(x1, y1, x2, y2);

    //decide black or white turn
	setcolor(0);
	setfillstyle(1, 0);
	bar(100, 10, 380, 50);
	setcolor(14);
		if (turn % 2 == 0) {
			outtextxy(230, 30, "Black Player's Turn.");
			symbol = 'b';
		}
		else if (turn % 2 == 1) {
			outtextxy(230, 30, "White Player's Turn.");
			symbol = 'w';
		}
		
		//moving pointer square
         pointer_square(table,symbol,turn);
         turn++; //change turn (if the inputs are valid in the previous function)
         
		 system("cls");
         rotate (table,alternative);
		 closegraph();
		 gameboard();//rotate game board according to the given section and direction
		 place_marble(table);
		 winning_condition(table,main_value); //check if anyone wins to end the game
		 if (main_value[0] == 2) {
                         delay(3000);
			 return 0;
		 }
	}
		 while(main_value[0]==1); //play until there is winning or equal condition
	return 0;
}

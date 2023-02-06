#include"graphics.h"
int winning_condition(char table[6][6],int main_value[1]) {
    int i=0, j=0;
    int value_b = 1, value_w = 1;
    setcolor(0);
    setfillstyle(1, 0);
    bar(100, 10, 380, 50);
    setcolor(14);
    //check if there is a shape of 'L' for each player.
    //vertical black
    for (j = 0; j < 6; j++) {
        for (i = 0; i < 3; i++) {
            if ((table[i][j] == 'b') && (table[i + 1][j] == 'b') && (table[i + 2][j] == 'b') &&
                (table[i + 3][j] == 'b') && ((table[i][j + 1] == 'b') || (table[i][j - 1] == 'b') || (table[i + 3][j + 1] == 'b') || (table[i + 3][j - 1] == 'b'))) {
                value_b = 2;
                
            }

            //vertical white
            if ((table[i][j] == 'w') && (table[i + 1][j] == 'w') && (table[i + 2][j] == 'w') &&
                (table[i + 3][j] == 'w') && ((table[i][j + 1] == 'w') || (table[i][j - 1] == 'w') || (table[i + 3][j + 1] == 'w') || (table[i + 3][j - 1] == 'w'))) {
                value_w = 2;
              
            }
        }
    }

    //horizontal black
    for (i = 0; i < 6; i++) {
        for (j = 0; j < 3; j++) {
            if ((table[i][j] == 'b') && (table[i][j + 1] == 'b') && (table[i][j + 2] == 'b') &&
                (table[i][j + 3] == 'b') && ((table[i + 1][j] == 'b') || (table[i - 1][j] == 'b') || (table[i + 1][j + 3] == 'b') || (table[i - 1][j + 3] == 'b'))) {
                value_b = 2;
              
            }
            //horizontal white
            if ((table[i][j] == 'w') && (table[i][j + 1] == 'w') && (table[i][j + 2] == 'w') &&
                (table[i][j + 3] == 'w') && ((table[i + 1][j] == 'w') || (table[i - 1][j] == 'w') || (table[i + 1][j + 3] == 'w') || (table[i - 1][j + 3] == 'w'))) {
                value_w = 2;
               
            }
        }
    }

    //orib black
    for (j = 0; j < 3; j++) {
        for (i = 0; i < 3; i++) {
            if ((table[i][j] == 'b') && (table[i + 1][j + 1] == 'b') && (table[i + 2][j + 2] == 'b') &&
                (table[i + 3][j + 3] == 'b') && ((table[i - 1][j + 1] == 'b') || (table[i + 1][j - 1] == 'b') || (table[i + 2][j + 4] == 'b') || (table[i + 4][j + 2] == 'b'))) {
                value_b = 2;
                
            }
        }
        for (i = 3; i < 6; i++) {
            if ((table[i][j] == 'b') && (table[i - 1][j + 1] == 'b') && (table[i - 2][j + 2] == 'b') &&
                (table[i - 3][j + 3] == 'b') && ((table[i + 1][j + 1] == 'b') || (table[i - 1][j - 1] == 'b') || (table[i - 2][j + 4] == 'b') || (table[i - 4][j + 2] == 'b'))) {
                value_b = 2;
                
            }
        }
        //orib white
        for (i = 0; i < 3; i++) {
            if ((table[i][j] == 'w') && (table[i + 1][j + 1] == 'w') && (table[i + 2][j + 2] == 'w') && (table[i + 3][j + 3] == 'w') &&
                ((table[i - 1][j + 1] == 'w') || (table[i + 1][j - 1] == 'w') || (table[i + 2][j + 4] == 'w') || (table[i + 4][j + 2] == 'w'))) {
                value_w = 2;
               
            }
        }
        for (i = 3; i < 6; i++) {
            if ((table[i][j] == 'w') && (table[i - 1][j + 1] == 'w') && (table[i - 2][j + 2] == 'w') &&
                (table[i - 3][j + 3] == 'w') && ((table[i + 1][j + 1] == 'w') || (table[i - 1][j - 1] == 'w') || (table[i - 2][j + 4] == 'w') || (table[i - 4][j + 2] == 'w'))) {
                value_b = 2;
                
            }
        }

    }
    //decide the winner
    if ((value_b == 2) && (value_w == 2)) {
        main_value[0]=2;
        outtextxy(190, 30, "equal! both win.");
    }
    else if ((value_b == 2) && (value_w != 2)) {
        main_value[0]=2;
        outtextxy(190, 30, "Black Player Wins!");
        
    }
    else if ((value_b != 2) && (value_w == 2)) {
        outtextxy(190, 30, "White Player Wins!");
        main_value[0]=2;
       
    }
    //full board and no winner//
    else {
        int count = 0;
        for (i = 0; i < 6; i++) {
            for (j = 0; j < 6; j++) {
                if (table[i][j] == '.') {
                    count++;
                }
            }
        }
        if (count == 0) {
            outtextxy(150, 30, "no more place left on board!");
            main_value[0]=2;
           
        }
        else {
            main_value[0]=1;
            
        }
    }
        return main_value[1];
   
}

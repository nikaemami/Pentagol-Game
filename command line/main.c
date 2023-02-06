#include<stdio.h>
#include"gameboard.h"
#include "place marble.h"
#include"rotate.h"
#include"winning condition.h"
int main() {
    //initialize the array.
    int i = 0, j = 0, turn = 0;
    char table[6][6];
    char alternative[6][6];
    for (i = 0; i < 6; i++) {
        for (j = 0; j < 6; j++) {
            table[i][j] = '.';
        }
    }
    gameboard(table);  //print the initialized gameboard
    int main_value[1];//an array as an argument and return value to check winning condition.
    main_value[0]=1;
    do {
        place_marble(table, turn); //print b or w on the board
        turn++;
        rotate(table, alternative); //rotate game board according to the given section and direction
        system("cls");
        gameboard(table);  //print the new board after rotation
        winning_condition(table,main_value); //check if anyone wins to end the game
        if (main_value[0] == 2) {
            return 0;
        }
    } while (main_value[0] == 1);
    return 0;
}





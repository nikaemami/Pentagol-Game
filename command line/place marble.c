#include<stdio.h>
#include<string.h>
void gameboard (char table[6][6]);
void place_marble(char table[6][6], int turn){
char symbol='o';
    //decide whose turn it is.
    if(turn%2==0){
             printf("Black player's turn:\n");
                symbol='b';
            }
            else if (turn%2==1){
                 printf("White player's turn:\n");
                symbol='w';
            }
    //get the place to put marble.
    printf("choose place on board.\n");
    int condition=0,i,j;
   char number[100];
   while(condition==0){
       //read input as string for limiting the input.
        fgets(number,99,stdin);
       //check if input is integer
         if (sscanf_s(number,"%d",& condition)!=1){
             condition=0;
             printf("invalid input.try again\n");
             continue;
         }
       //check if the input is not float read as integer.
       if (strlen(number)!=3){
           printf("invalid input.try again.\n");
           condition = 0;
           continue;
       }
       //check if the input is in the range of gameboard
             int row=condition/10;
             int column=condition%10;
         if((row>0)&&(row<7)&&(column>0)&&(column<7)){
     for (i=0;i<6;i++){
         for (j=0;j<6;j++){
             if((i+1==row)&&(j+1==column)){
                 if (table[row - 1][column - 1] == '.') { //check if the place on board is empty
                     table[row - 1][column - 1] = symbol;//print b or w in the chosen place
                     system("cls");
                     gameboard(table);
                 }
                 else {
                     printf("already full.try again.\n");
                     condition=0;
                 }
             }
         }
     }
         }
         else {
             printf("invalid input.try again\n");
             condition=0;
             continue;
         }
       }
}
   
    
    
    
     

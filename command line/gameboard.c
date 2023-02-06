#include<stdio.h>
void gameboard (char table[6][6]){
    int i,j;
printf ("    1   2   3 | 4   5   6\n"); // show the number of column.
for (i = 0; i<6; i++) {
    printf("%d   ",i+1); // show the number of row.
    for (j = 0; j<6; j++) {
        if (j==2){
            printf("%c | ", table[i][j]);} //show the section dividing lines.
        else{
            printf("%c   ", table[i][j]);}
    }
    if(i==2){
        printf("\n-- -- -- -- -- -- -- -- --\n"); //show the section dividing lines.
    }
            else {
        printf("\n\n");}
}
}

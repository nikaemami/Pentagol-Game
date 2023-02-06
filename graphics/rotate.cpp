#include<stdio.h>
#include<string.h>
void rotate (char table[6][6],char alternative[6][6]){
    //initialize an alternative array to change elements for rotating.
    int i=0, j=0;
    for (i = 0; i < 6; i++) {
        for (j = 0; j < 6; j++) {
            alternative[i][j] = table[i][j];
        }
    }
    int section=0;
    do {
    printf("enter section\n");
         //read input section as string to limit inputs.
        char input_s[100];
             fgets(input_s,99,stdin);
        //check if input is integer
              if (sscanf(input_s,"%d",& section)!=1){
                  section=0;
                  printf("invalid input.try again\n");
                  continue;
              }
        //check if input is 1,2,3 or 4.
             if(section<1 || section>4){
                 section=0;
                 printf("invalid input.try again\n");
                 continue;
             }
        //check if input is not float read as integer.
        if (strlen(input_s)!=2){
            printf("invalid input.try again.\n");
            section = 0;
            continue;
        }
        char direction='a';
        do{
        printf("direction?\n");
            //read input direction as string to limit inputs.
            char input_d[100];
                 fgets(input_d,99,stdin);
            //check if input is character
                  if (sscanf(input_d,"%c",& direction)!=1){
                      direction='a';
                      printf("invalid input.try again\n");
                      continue;
                  }
            //check if input is only + or -
                 if(direction != '+' && direction != '-'){
                     direction='a';
                     printf("invalid input.try again\n");
                     continue;
                 }
            //limit other char inputs that start with - or +
            if (strlen(input_d)!=2){
                printf("invalid input.try again.\n");
                direction='a';
                continue;
            }
            //assign different elements of array a to array b, to rotate according to the section and direction
if((section==2)&&(direction=='+')){
alternative[0][0]=table[2][0];
alternative[0][1]=table[1][0];
alternative[0][2]=table[0][0];
alternative[1][0]=table[2][1];
alternative[1][2]=table[0][1];
alternative[2][0]=table[2][2];
alternative[2][1]=table[1][2];
alternative[2][2]=table[0][2];
            }
else if((section==2)&&(direction=='-')){
alternative[0][0]=table[0][2];
alternative[0][1]=table[1][2];
alternative[0][2]=table[2][2];
alternative[1][0]=table[0][1];
alternative[1][2]=table[2][1];
alternative[2][0]=table[0][0];
alternative[2][1]=table[1][0];
alternative[2][2]=table[2][0];
}
else if((section==1)&&(direction=='+')){
alternative[0][3]=table[2][3];
alternative[0][4]=table[1][3];
alternative[0][5]=table[0][3];
alternative[1][3]=table[2][4];
alternative[1][5]=table[0][4];
alternative[2][3]=table[2][5];
alternative[2][4]=table[1][5];
alternative[2][5]=table[0][5];
}
else if((section==1)&&(direction=='-')){
alternative[0][3]=table[0][5];
alternative[0][4]=table[1][5];
alternative[0][5]=table[2][5];
alternative[1][3]=table[0][4];
alternative[1][5]=table[2][4];
alternative[2][3]=table[0][3];
alternative[2][4]=table[1][3];
alternative[2][5]=table[2][3];
}
else if((section==3)&&(direction=='+')){
alternative[3][0]=table[5][0];
alternative[3][1]=table[4][0];
alternative[3][2]=table[3][0];
alternative[4][0]=table[5][1];
alternative[4][2]=table[3][1];
alternative[5][0]=table[5][2];
alternative[5][1]=table[4][2];
alternative[5][2]=table[3][2];
}
else if((section==3)&&(direction=='-')){
alternative[3][0]=table[3][2];
alternative[3][1]=table[4][2];
alternative[3][2]=table[5][2];
alternative[4][0]=table[3][1];
alternative[4][2]=table[5][1];
alternative[5][0]=table[3][0];
alternative[5][1]=table[4][0];
alternative[5][2]=table[5][0];
}
else if((section==4)&&(direction=='+')){
alternative[3][3]=table[5][3];
alternative[3][4]=table[4][3];
alternative[3][5]=table[3][3];
alternative[4][3]=table[5][4];
alternative[4][5]=table[3][4];
alternative[5][3]=table[5][5];
alternative[5][4]=table[4][5];
alternative[5][5]=table[3][5];
}
else if((section==4)&&(direction=='-')){
alternative[3][3]=table[3][5];
alternative[3][4]=table[4][5];
alternative[3][5]=table[5][5];
alternative[4][3]=table[3][4];
alternative[4][5]=table[5][4];
alternative[5][3]=table[3][3];
alternative[5][4]=table[4][3];
alternative[5][5]=table[5][3];
}
            //change the first array according to the changes.
for (i = 0; i < 6; i++) {
    for (j = 0; j < 6; j++) {
        table[i][j] = alternative[i][j];
    }
}
    }
        while(direction=='a');
    }
    while (section==0);
}


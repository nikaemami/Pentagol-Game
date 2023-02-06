#include<stdio.h>
int winning_condition (char table[6][6],int main_value[1]){
    int i,j;
    int value_b=1, value_w=1;
    
    //vertical black
     for (j=0;j<6;j++){
        for (i=0;i<3;i++){
         if ((table[i][j]=='b')&&(table[i+1][j]=='b')&&(table[i+2][j]=='b')&&
         (table[i+3][j]=='b')&&((table[i][j+1]=='b')|| (table[i][j-1]=='b')||(table[i+3][j+1]=='b')||(table[i+3][j-1]=='b'))){
             value_b=2;
             }
            
            //vertical white
          if ((table[i][j]=='w')&&(table[i+1][j]=='w')&&(table[i+2][j]=='w')&&
         (table[i+3][j]=='w')&&((table[i][j+1]=='w')||(table[i][j-1]=='w') ||(table[i+3][j+1]=='w')||(table[i+3][j-1]=='w'))){
              value_w=2;
             }}}
          
        //horizontal black
        for (i=0;i<6;i++){
          for (j=0;j<3;j++){
           if ((table[i][j]=='b')&&(table[i][j+1]=='b')&&(table[i][j+2]=='b')&&
               (table[i][j+3]=='b')&&((table[i+1][j]=='b')|| (table[i-1][j]=='b')||(table[i+1][j+3]=='b')|| (table[i-1][j+3]=='b'))){
               value_b=2;
        }
              //horizontal white
           if ((table[i][j]=='w')&&(table[i][j+1]=='w')&&(table[i][j+2]=='w')&&
            (table[i][j+3]=='w')&&((table[i+1][j]=='w')||(table[i-1][j]=='w')|| (table[i+1][j+3]=='w')||(table[i-1][j+3]=='w'))){
                  value_w=2;
              }}}
    
        //orib black
        for (j=0;j<3;j++){
          for (i=0;i<3;i++){
           if ((table[i][j]=='b')&&(table[i+1][j+1]=='b')&&(table[i+2][j+2]=='b')&&
           (table[i+3][j+3]=='b')&&((table[i-1][j+1]=='b')||(table[i+1][j-1]=='b') ||(table[i+2][j+4]=='b')||(table[i+4][j+2]=='b'))){
             value_b=2;
           }}
              for (i=3;i<6;i++){
              if((table[i][j]=='b')&&(table[i-1][j+1]=='b')&&(table[i-2][j+2]=='b')&&
              (table[i-3][j+3]=='b')&&((table[i+1][j+1]=='b')||(table[i-1][j-1]=='b') ||(table[i-2][j+4]=='b')||(table[i-4][j+2]=='b'))){
                value_b=2;
              }}
              //orib white
            for (i=0;i<3;i++){
           if((table[i][j]=='w')&&(table[i+1][j+1]=='w')&&  (table[i+2][j+2]=='w')&&(table[i+3][j+3]=='w')&&
                   ((table[i-1][j+1]=='w')||(table[i+1][j-1]=='w') ||(table[i+2][j+4]=='w')||(table[i+4][j+2]=='w'))){
                   value_w=2;
           }}
            for (i=3;i<6;i++){
            if((table[i][j]=='w')&&(table[i-1][j+1]=='w')&&(table[i-2][j+2]=='w')&&
            (table[i-3][j+3]=='w')&&((table[i+1][j+1]=='w')||(table[i-1][j-1]=='w') ||(table[i-2][j+4]=='w')||(table[i-4][j+2]=='w'))){
              value_b=2;
            }}
        }
    if ((value_b==2)&&(value_w==2)){
        printf("equal,both win!\n");
        main_value[0]=2;
    }
    else if((value_b==2)&&(value_w!=2)){
       printf("Winner is BLACK!\n");
         main_value[0]=2;
    }
    else if((value_b!=2)&&(value_w==2)){
       printf("Winner is WHITE!\n");
         main_value[0]=2;
    }
    //full board and no winner//
    else {
        int count=0;
        for(i=0;i<6;i++){
        for(j=0;j<6;j++){
            if(table[i][j]=='.'){
                count ++;
            }}}
            if (count==0){
                printf("no more place left on board!\n");
                 main_value[0]=2;
            }
            else{
                main_value[0]=1;
            }
    }
    return main_value[1];
}

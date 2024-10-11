#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
enum gamestatus{
    LOST,
    WON,
    CONTINUE

};
void print_status(int status);
int roll();
int main(){
    srand(time(NULL));
    int status=0;
    int total=roll();
    switch(total){
        case 2:
        status=LOST;
        break;
        case 3:
        status=LOST;
        break;
        case 7:
        status=WON;
        break;
        case 11:
        status=WON;
        break;
        case 12:
        status=LOST;
        break;
        default:
        printf("Point is %d\n",total);
        while (true){
            int total2=roll();
            if(total==total2){
                status=WON;
                break;
            }
            else if(total2==7){
                status=LOST;
                break;
            }
        }
     
    }
    status(status);
    return 0;
}
int roll(){
     int dice1=1+rand()%6;
     int dice2=1+rand()%6;
     printf("Player rolled %d+%d=%d\n",dice1,dice2,dice1+dice2);
     return dice1+dice2;
}

void print_status(int status){
     if(status==WON){
            printf("Player wins!");
        }
    else{
            printf("Player loses!");
        }
}


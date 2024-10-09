#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int coinflipping();
int main(){
int coin;    
srand(time(NULL));
printf("Heads or Tails ? (0=Heads and 1=Tails) :");
scanf("%d",&coin);
if(coin!=1 && coin!=0){
    printf("Invaild Number!");
    return 0;
}
int result;
result=coinflipping();
if(coin==result){
if(result==0){
 printf("The result of the coin flip is: ");
    printf("Heads!\n");
}
else if(result==1){
    printf("Tails!\n");
}
printf("You win!");
}
else{
    printf("The result of the coin flip is: ");
    if(result==0){
        printf("Heads!\n");
    }
    else if(result==1){
        printf("Tails!\n");
    }
    printf("You lost!");

}

}
int coinflipping(){
return rand()%2;
    
}
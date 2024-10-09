#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
int main(){
srand(time(NULL));
int i=0;
int score=0;
char option[10];
printf("-------Welcome to the High-Low Game!------\n");
printf("------------------------------------------\n");
printf("Rules:\n");
printf("The range of numbers is (0,100).\n");
printf("Please be careful about case sensivity. Only \"higher\" and \"lower\" options are valid.\n");
printf("If the numbers are equal, it will count as a failure.\n");
printf("Let's start :)\n\n");
while (i<5){
    int computer_num=rand()%101;;
    int your_number=rand()%101;;
    printf("Round %d\n",i+1);
    printf("Your number is %d\n",your_number);
    printf("Do you think your number is lower or higher than the computer's ?:");
    scanf("%s",option);
        while (strcmp("higher",option)!=0 && strcmp("lower",option)!=0){
        printf("Invalid choice!\n"); 
        printf("Please enter either higher or lower:");
        scanf("%s",option);
    }
    printf("\n");
    if(strcmp("higher",option)==0 && your_number>computer_num){
        printf("You were right. The computer's number was %d\n",computer_num);
        score++;
        printf("Your score is now %d\n",score);
    }
    else if( strcmp("lower",option)==0 && computer_num>your_number){
        printf("You were right. The computer's number was %d\n",computer_num);
        score++;
        printf("Your score is now %d\n",score);
    }
    else{
        printf("Incorrect. The computer number was %d\n",computer_num);
        printf("Your score is now %d\n",score);
    }

    i++;
    printf("\n");

}
printf("----------RESULT----------\n\n");
if(score==5){
    printf("Total score:%d\n",score);
    printf("Wow! You played perfectly.");
}
else if(score>=2){
    printf("Total score:%d\n",score);
    printf("Good job, you played really well!");
}
else{
    printf("Total score:%d\n",score);
    printf("Better luck next time.");
}
printf("\nThanks for playing the game!");
}
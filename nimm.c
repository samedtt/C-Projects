#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int ai_turn();
void game();
void game_status(char name[],int stones);

int main(){
    game();
    return 0;
   
}

int ai_turn(){
    
    srand(time(NULL));
    
    return (rand()%2)+1;
}

void game(){
    int stones=20;
    int player_turn=0;
    int computer_turn=0;
    int i=0;
   
    while(stones!=0){

        printf("\n\nThere are %d stones left.",stones);
       
        if(i%2==0){
            
            printf("\nPlayer would you like to remove 1 or 2 stones? ");
            
            if(stones==1){

                scanf("%d",&player_turn);
                
                while(player_turn!=1){

                    printf("\n\nPlease enter 1:");
                    scanf("%d",&player_turn);

                }
                
                printf("\nPlayer selected: 1\n");
                stones-=1;

            }
            
            else{

            scanf("%d",&player_turn);
            
            while(player_turn!=1 && player_turn!=2){
                
                printf("\n\nPlease enter 1 or 2:");
                scanf("%d",&player_turn);

            }
            
            printf("\nPlayer selected: %d",player_turn);
            i+=1;
            stones-=player_turn;
            
            }
            
            game_status("Computer",stones);

        }
        
        else{
            printf("\nComputer would you like to remove 1 or 2 stones?\n");
            
            if(stones==1){

                printf("\nComputer selected: 1\n");
                stones-=1;

            }
            
            else{

            computer_turn=ai_turn();
            printf("\nComputer selected: %d\n",computer_turn);
            stones-=computer_turn;
            i+=1;
            
            }
            
            game_status("Player",stones);
        }


    }

}

void game_status(char name[],int stones){
    int choice=0;
    
    if(stones==0){

        printf("\n\n%s wins!\n\n",name);
        printf("\n\n%s, would you like to play again ? (1-Yes, 2-No): ",name);
        
        if(strcmp(name,"Computer")==0){

        choice=ai_turn();

        }
        
        else{
            
            scanf("%d",&choice); 
            
            while(choice!=1 && choice!=2){

                printf("\n\nPlease enter 1 or 2 (1-Yes, 2-No):");
                scanf("%d",&choice);
            
            }
        }
        printf("\n%s selected %d.\n\n",name,choice);
        
        if(choice==1){

            game();

        }
        
        else{

            printf("\n\nThanks for playing the game!\n\n");
            exit(0);

        }
    }

}
#include <stdio.h>
#include <stdlib.h>
int menu();
void pin();
void changepin();
int verify();
void cancel();
void balance();
void deposit();
void withdraw();
typedef struct{
unsigned int pin;
unsigned int current;
unsigned long long int balance;
}account;
account Pin;
account newpin;
account transaction;
FILE *yptr;
int main(){
    verify();
    
}
int menu(){
    int choice=0;
    while(1){
    printf("------------------------------\n");
    printf("-----------Git ATM------------\n");
    printf("------------------------------\n");
    printf("|                            |\n");
    printf("|       [1] Deposit          |\n");
    printf("|       [2] Withdraw         |\n");
    printf("|       [3] Balance          |\n");
    printf("|       [4] Change Pin       |\n");
    printf("|       [5] Exit             |\n");
    printf("|                            |\n");
    printf("|                            |\n");
    printf("|                            |\n");
    printf("|----------------------------|\n\n\n");
    printf("Enter your choice:");
    scanf("%d",&choice);
    switch(choice){
        case 1:
        deposit();
        break;
        case 2:
        withdraw();
        break;
        case 3:
        balance();
        break;
        case 4:
        changepin();
        break;
        case 5:
        cancel();
        return 0;
        default:
        printf("\n\nNo Service.\n\n");
    }
    }
}
void pin(){
    printf("------------------------------\n");
    printf("-----------Git ATM------------\n");
    printf("------------------------------\n");
    printf("         Pin:");
    scanf("%u",&Pin.pin);
    printf("\n\n");

}
void changepin(){
    int i=0;
    unsigned int test=0;
    FILE* fptr;
    fptr=fopen("pin.txt","a");
    if(fptr==NULL){
        printf("\n\nChanging PIN is completed unsuccesfully!\n\n");
    }
    else{
    printf("\nEnter your new PIN (Need 6 numbers):");
    scanf("%u",&newpin.pin);
    test=newpin.pin;
    while(test!=0){
        test/=10;
        i++;
     }
    if(i==6){
        fprintf(fptr,"\n");
        fprintf(fptr,"%u",newpin.pin);
        printf("\n\nChanging PIN is completed succesfully\n\n");
        
    }
    else{
        printf("\n\nChanging PIN is completed unsuccesfully!\n\n");
    }
    }
    fclose(fptr);
   

}
int verify(){
    int rights=3;
    int login=0;
    FILE* fptr;
    FILE* xptr;
    xptr=fopen("blocked.txt","a+");
    fptr=fopen("pin.txt","r");
    if(fscanf(xptr,"%d",&login)==1){
       printf("\n\n******!!Your account has been blocked!!******\n\n");
       fclose(xptr);
       fclose(fptr);
       return 0;
    }
    else{
    if(fptr==NULL){
        printf("The system has file problem.\n\n");
    }
    else{
    fseek(fptr,-6,SEEK_END);
    fscanf(fptr,"%u",&Pin.current);
    pin();
    if(Pin.pin==Pin.current){
    printf("You have logged in succesfully\n\n");
     menu();   
    }
    else{    
    while(rights>0){
        printf("You have entered wrong PIN.\n");
        printf("You have %d rights left\n\n",rights);
        pin();
        rights--;
        if(Pin.pin==Pin.current){
            printf("You have logged in succesfully\n\n");
            menu();
            break;
        }
        if(rights==0){
            printf("\n\n***Your account has been blocked.***\n\n");
            fprintf(xptr,"%d\n",1);
            return 0;
        }
    }
    }
    }
}
fclose(xptr);
fclose(fptr);
}
void cancel(){
    printf("\n\n Exitting...\n\n");
    printf("------------------------------\n");
    printf("-----------Git ATM------------\n");
    printf("------------------------------\n");
    printf("|                            |\n");
    printf("|    Collect your ATM Card.  |\n");
    printf("|                            |\n");
    printf("|      Thank       you       |\n");
    printf("|             for            |\n");
    printf("|            using           |\n");
    printf("|                            |\n");
    printf("|          Git  ATM          |\n");
    printf("|                            |\n");
    printf("|                            |\n");
    printf("|----------------------------|\n\n\n");

}
void balance(){
    transaction.balance=0;
    yptr=fopen("balance.txt","r");
    if(yptr==NULL){
        printf("\n\nThe system has file problem.\n\n");
    }
    else{
    fscanf(yptr,"%llu",&transaction.balance);
    printf("\n\nBalance:$%llu\n\n",transaction.balance);
    }
    fclose(yptr);
    
}
void deposit() {
    unsigned long long int amount = 0;
    transaction.balance = 0;
    char option;

    yptr = fopen("balance.txt", "r+");
    if (yptr == NULL) {
        printf("\n\nThe system has a file problem.\n\n");
        return;
    }

    printf("\n\nEnter an amount: ");
    scanf("%llu", &amount);
    if (amount == 0) {
        printf("\n\nInvalid amount. Please enter a positive number.\n\n");
        fclose(yptr);
        return;
    }
    fscanf(yptr, "%llu", &transaction.balance);
    printf("\n\nConfirm deposit? (Y/N): ");
    scanf(" %c", &option);
    if (option == 'N' || option=='n') {
        printf("\n\nDeposit transaction cancelled.\n\n");
    } else if(option=='Y' || option=='y') {
        printf("\n\nDepositing...\n\n");
        transaction.balance += amount;
        printf("$%llu deposited successfully.\n\n", amount);

        
        freopen("balance.txt", "w+", yptr); 
        fprintf(yptr, "%llu", transaction.balance);

        printf("Current Balance: $%llu\n\n", transaction.balance);
    }
    else{
        printf("\n\nInvalid Input! Transaction aborted.\n\n");
    }
    
   
    fclose(yptr);
}
void withdraw() {
    unsigned long long int amount = 0;
    transaction.balance = 0;
    char option;

    yptr = fopen("balance.txt", "r+");
    if (yptr == NULL) {
        printf("\n\nThe system has a file problem.\n\n");
        return;
    }

    fscanf(yptr, "%llu", &transaction.balance); 

    printf("\n\nEnter an amount: ");
    scanf("%llu", &amount);

    
    if (amount == 0) {
        printf("\n\nInvalid amount. Please enter a positive number.\n\n");
        fclose(yptr);
        return;
    }

  
    if (amount > transaction.balance) {
        printf("\n\nInsufficient balance.\n\n");
        fclose(yptr);
        return;
    }

    
    printf("\n\nConfirm withdrawal? (Y/N): ");
    scanf(" %c", &option);

    if (option == 'N' || option == 'n') {
        printf("\n\nWithdrawal transaction cancelled.\n\n");}
    else if(option=='Y' || option=='y'){
        printf("\n\nWithdrawing...\n\n");
        transaction.balance -= amount;
        printf("$%llu withdrawn successfully.\n\n", amount);

        
        freopen("balance.txt", "w+", yptr); 
        fprintf(yptr, "%llu", transaction.balance); 

        printf("Current Balance: $%llu\n\n", transaction.balance);
    }
    else{
        printf("\n\nInvalid Input! Transaction aborted.\n\n");
    }

    fclose(yptr);
}


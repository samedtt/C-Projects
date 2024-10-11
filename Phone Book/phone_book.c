#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
char name[50];
char surname[50];
char phone_num[50];
char birth_date[50];
char birth_date_format[50];
}person;
person temp_p;
person p;

void menu();
void add_person();
void remove_person();
void show_all_persons();
void edit_person();
void count_person();
void search_person();
void remove_all_persons();

FILE *ptr;
FILE *temp;
FILE *countperson;

int main(){

menu();
return 0;

}

void menu(){

    int choice=0;

    while(choice!=8){

        printf("\n\n1- Add a person\n");
        printf("2- Remove a person\n");
        printf("3- Show all persons\n");
        printf("4- Edit Person\n");
        printf("5- Number of people in Phone book\n");
        printf("6- Search Person\n");
        printf("7- Remove all Persons\n");
        printf("8- Exit\n\n");     


        printf("Enter your choice:\n\n");

        scanf("%d",&choice);

        switch(choice){

            case 1:
                add_person();
                break;
            case 2:
                remove_person();
                break;
            case 3:
                show_all_persons();
                break;
            case 4:
                edit_person();
                break;
            case 5:
                count_person();
                break;
            case 6:
                search_person();
                break;
            case 7:
                remove_all_persons();
                break;
            case 8:
                exit(0);
                
    }  
    }
    


}


void add_person(){

    ptr=fopen("phone_book.txt","a");
    countperson=fopen("count.txt","r+");
    char format[10];

    if (ptr==NULL||countperson==NULL){

        printf("\n\nThe system has a problem.");

    }
    else{

        int count=0;

        printf("\n\nEnter the name:");
        scanf("%s",p.name);
        printf("\nEnter the surname:");
        scanf("%s",p.surname);
        printf("\nEnter the phone number:");
        scanf("%s",p.phone_num);
        printf("\nWhich format would you like to enter your birth date: Write M/D/Y ----> (Month/Day/Year) or D/Y/M ----> (Day/Month/Year): ");
        scanf("%s",p.birth_date_format);

        while ((strcmp(p.birth_date_format,"M/D/Y")!=0) && (strcmp(p.birth_date_format,"D/Y/M")!=0)){

            printf("\nEnter the proper format ---> M/D/Y or D/Y/M: ");
            scanf("%s",p.birth_date_format);
        }

        if (strcmp(p.birth_date_format,"M/D/Y")==0){

            printf("\nEnter your birth date (M/D/Y): ");
            scanf("%s",p.birth_date);
                
        }
        else if (strcmp(p.birth_date_format,"D/Y/M")==0){

            printf("\nEnter your birth date (D/Y/M): ");
            scanf("%s",p.birth_date);
                
        }

        fprintf(ptr,"%s %s %s %s %s\n",p.name,p.surname,p.phone_num,p.birth_date,p.birth_date_format);

        fscanf(countperson,"%d",&count);
    
        count+=1;
        rewind(countperson);
        fprintf(countperson,"%d",count);
}

fclose(ptr);
fclose(countperson);

}

void remove_person(){

    ptr=fopen("phone_book.txt","r");
    temp=fopen("temp.txt","w");
    countperson=fopen("count.txt","r+");
    int flag=0;

    if(temp==NULL || ptr==NULL){

        printf("\n\nSystem has a problem.");

    }
    else{

        int count=0;

        printf("\n\nWhich person would you like to remove?");
        printf("\n\nEnter the name of the person: ");
        scanf("%s",temp_p.name);
        printf("\nEnter the surname of the person: ");
        scanf("%s",temp_p.surname);

        while(fscanf(ptr,"%s %s %s %s %s",p.name,p.surname,p.phone_num,p.birth_date,p.birth_date_format)!=EOF){

            if (strcmp(temp_p.name,p.name)==0 && strcmp(temp_p.surname,p.surname)==0){

                flag=1;

            }
            else{

                fprintf(temp,"%s %s %s %s %s\n",p.name,p.surname,p.phone_num,p.birth_date,p.birth_date_format);

            }
        }

        if (flag==0){

            printf("\n\nThe person has not found!\n\n");

        }
        else{

        printf("\n\nThe person has been removed.\n\n");
        fscanf(countperson,"%d",&count);
        count-=1;
        rewind(countperson);
        fprintf(countperson,"%d",count);

        }
    }

    fclose(countperson);
    fclose(ptr);
    fclose(temp);
    remove("phone_book.txt");
    rename("temp.txt","phone_book.txt");

}


void show_all_persons(){

ptr=fopen("phone_book.txt","r");
printf("\n\n----------------------------Phone Book----------------------------\n\n");

while(fscanf(ptr,"%s %s %s %s %s",p.name,p.surname,p.phone_num,p.birth_date,p.birth_date_format)!=EOF){

    printf("\nName: %s",p.name);
    printf("\nSurname: %s",p.surname);
    printf("\nPhone Number: %s",p.phone_num);
    printf("\nBirth Date: %s (%s)",p.birth_date,p.birth_date_format);
    printf("\n\n");

}

printf("\n\n------------------------------------------------------------------\n\n");
fclose(ptr);

}

void search_person(){

ptr=fopen("phone_book.txt","r");
int flag=0;

printf("\n\nWhich person would you like to search?");
printf("\n\nEnter the name of the person: ");
scanf("%s",temp_p.name);
printf("\nEnter the surname of the person: ");
scanf("%s",temp_p.surname);
printf("\n\n-------------------------%s %s's Informations--------------------------\n\n",temp_p.name,temp_p.surname);

while(fscanf(ptr,"%s %s %s %s %s",p.name,p.surname,p.phone_num,p.birth_date,p.birth_date_format)!=EOF){

    if(strcmp(temp_p.name,p.name)==0 && strcmp(temp_p.surname,p.surname)==0){

        printf("\nName: %s",p.name);
        printf("\nSurname: %s",p.surname);
        printf("\nPhone Number: %s",p.phone_num);
        printf("\nBirth Date: %s (%s)",p.birth_date,p.birth_date_format);
        flag=1;
        break;

    }
}

if (flag==0){

printf("\n\n\t\t\tPerson has not found!\n\n");

}

printf("\n\n------------------------------------------------------------------------\n\n");
fclose(ptr);

}


void edit_person(){

    ptr=fopen("phone_book.txt","r");
    temp=fopen("temp.txt","w");
    int flag=0;

    if(ptr==NULL || temp==NULL){

        printf("\n\nSystem has a problem.");

    }
    else{

        person new_p;
        char choice;

        printf("\n\nWhich person would you like to edit?");
        printf("\n\nEnter the name of the person: ");
        scanf("%s",temp_p.name);
        printf("\nEnter the surname of the person: ");
        scanf("%s",temp_p.surname);
    
        while(fscanf(ptr,"%s %s %s %s %s",p.name,p.surname,p.phone_num,p.birth_date,p.birth_date_format)!=EOF){
            
            if (strcmp(temp_p.name,p.name)==0 && strcmp(temp_p.surname,p.surname)==0){

                printf("\nEdit Name (Y/N):");
                scanf(" %c",&choice);

                if (choice=='Y' || choice=='y'){

                    printf("\nEdit new name:");
                    scanf("%s",new_p.name);

                }
                else{

                    strcpy(new_p.name,p.name);

                }

                printf("\nEdit Surname (Y/N):");
                scanf(" %c",&choice);

                if(choice=='Y' || choice=='y'){

                    printf("\nEdit new surname:");
                    scanf("%s",new_p.surname);

                }
                else{

                    strcpy(new_p.surname,p.surname);

                }

                printf("\nEdit Phone Number (Y/N):");
                scanf(" %c",&choice);

                if (choice=='Y' || choice=='y'){

                    printf("\nEdit phone number:");
                    scanf("%s",new_p.phone_num);

                }
                else{

                    strcpy(new_p.phone_num,p.phone_num);

                }

                printf("\nEdit Birth Date (Y/N): ");
                scanf(" %c",&choice);

                if(choice=='Y' || choice=='y'){

                    printf("\nEdit birth date: ");
                    scanf("%s",new_p.birth_date);

                }
                else{

                    strcpy(new_p.birth_date,p.birth_date);

                }

                printf("\nEdit Birth Date Format (Y/N): ");
                scanf(" %c",&choice);

                if(choice=='Y' || choice=='y'){

                    printf("\n Edit birth format:");
                    scanf("%s",new_p.birth_date_format);

                }
                else{

                    strcpy(new_p.birth_date_format,p.birth_date_format);

                }

                fprintf(temp,"%s %s %s %s %s\n",new_p.name,new_p.surname,new_p.phone_num,new_p.birth_date,new_p.birth_date_format);
                flag=1;
            }
            else{

                fprintf(temp,"%s %s %s %s %s\n",p.name,p.surname,p.phone_num,p.birth_date,p.birth_date_format);

            }
        }
        }


        if (flag==0){

            printf("\n\nPerson has not found!\n\n");

        }

        fclose(ptr);
        fclose(temp);
        remove("phone_book.txt");
        rename("temp.txt","phone_book.txt");

    }

void count_person(){

    int count=0;
    countperson=fopen("count.txt","r");

    fscanf(countperson,"%d",&count);

    printf("\n\nThe count of people in the Phone book : %d\n\n",count);

}

void remove_all_persons(){

    countperson=fopen("count.txt","r+");
    char choice;

    printf("\n\nAre you sure to remove all persons (Y/N):");
    scanf(" %c",&choice);

    if (choice=='Y' || choice=='y'){

        printf("\n\nThe Phone Book has been removed.\n\n");
        remove("count.txt");
        remove("phone_book.txt");
        countperson=fopen("count.txt","w");
        fprintf(countperson,"%d",0);

    } 

    fclose(countperson);
    
}
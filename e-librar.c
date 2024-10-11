#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct{
char book_name[100];
char author_name[100];
char author_surname[100];
int page;
double price;
}book_info;
void menu(book_info book[]);
void add_book_info(book_info book[], int *count);
void display_book_info(book_info book[], int *count);
void list_books_of_author(book_info book[], int *count);
void count_of_books(int *count);


int main(){

    book_info book[100];
    menu(book);
    return 0;

}

void menu(book_info book[]){

int book_count=0;
int choice=0;

while(choice!=5){

printf("\n\n************##### E-LIBRARY #####************\n\n");
printf("---------------------------------------------\n\n");
printf("1- Add a book information\n");
printf("2- Display book information\n");
printf("3- List all books of given author\n");
printf("4- List the count of books in the library\n");
printf("5- Exit\n\n");
printf("---------------------------------------------\n\n");

printf("Enter your choice:");
scanf("%d",&choice);

printf("\n\n");

switch(choice){

    case 1:
    add_book_info(book,&book_count);
    break;

    case 2:
    display_book_info(book,&book_count);
    break;

    case 3:
    list_books_of_author(book,&book_count);
    break;

    case 4:
    count_of_books(&book_count);
    break;

    case 5:
    printf("\n\n----------Thanks for using E-LIBRARY----------\n\n");
    exit(0);
    
    }

}

}


void add_book_info(book_info book[],int *count){
    int i=*count;
    
    printf("Enter the book name: ");
    scanf("%s",book[i].book_name);
    printf("Enter the author name: ");
    scanf("%s",book[i].author_name);
    printf("Enter the author surname: ");
    scanf("%s",book[i].author_surname);
    printf("Enter pages: ");
    scanf("%d",&book[i].page);
    printf("Enter price: ");
    scanf("%lf",&book[i].price);
    printf("\n\n---------------- THE BOOK HAS ADDED SUCCESFULLY ----------------\n\n");
    
    *count+=1;
}


void display_book_info(book_info book[],int *count){
    int i;
    int size=*count;
    
    printf("\n\nDisplaying all books...\n\n"); 
    
    if (size==0){

        printf("\n\nThere is no book.\n\n");
    
    }

    else{

    printf("\n\n--------------BOOKS--------------\n\n");

    for(i=0;i<size;i++){
        printf("-Book name: %s\n",book[i].book_name);
        printf("-Author name and surname: %s %s\n",book[i].author_name,book[i].author_surname);
        printf("-Pages: %d\n",book[i].page);
        printf("-Price: $%.2lf\n",book[i].price);
        printf("\n");
    }

    }

    printf("\n\n---------------- ALL BOOKS HAVE DISPLAYED SUCCESFULLY ----------------\n\n");

}


void list_books_of_author(book_info book[], int* count){
    int i;
    int size=*count;
    char name[100];
    char surname[100];
   
    printf("Enter the name of the author: ");
    scanf("%s",name);
    printf("Enter the surname of the author: ");
    scanf("%s",surname);
    printf("\nSearching...\n");

    if (size==0){
   
        printf("\n\nThere is no book yet.\n\n");
   
    }
   
    else{
   
    printf("\n\n--------------BOOKS OF %s %s--------------\n\n",name,surname);
   
    for(i=0;i<size;i++){
   
        if (strcmp(name,book[i].author_name)==0 && strcmp(surname,book[i].author_surname)==0){
            printf("-Book name: %s\n",book[i].book_name);
            printf("-Pages: %d\n",book[i].page);
            printf("-Price: $%.2lf\n",book[i].price);
            printf("\n");
        }
   
    }
   
    printf("\n\n-----------------------------------------------\n");
   
    }

}


void count_of_books(int *count){

    printf("\nCounting...\n");
    printf("\nThe number of the books in the library: %d\n\n",*count);

}

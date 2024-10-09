#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tools.h"

FILE *students;
FILE *courses;
FILE *stu_temp;
FILE *cou_temp;

int main(){
    menu();
    return 0;
}

void menu(){
    int choice=0;
    while (choice!=7){
        printf("\n\n----------------------_______ Student Management System _______----------------------\n\n");
        printf("\t\t\t\t1- Add a New Student\n");
        printf("\t\t\t\t2- Show all Students\n");
        printf("\t\t\t\t3- Search Student\n");
        printf("\t\t\t\t4- Delete All Students\n");
        printf("\t\t\t\t5- Delete Student\n");
        printf("\t\t\t\t6- Edit Student\n");
        printf("\t\t\t\t7- Quit\n");
        printf("--------------------------------------------------------------------------------------");
       
        printf("\n\nEnter your choice:");
        scanf("%d",&choice);
        printf("\n\n");

        switch(choice){
            case 1:
            add_student();
            break;

            case 2:
            show_all_students();
            break;

            case 3:
            search_student();
            break;

            case 4:
            delete_all_students();
            break;

            case 5:
            delete_student();
            break;

            case 6:
            edit_student();
            break;

            case 7:
            quit();
            
        }
    }
}


void add_student(){
    students=fopen("student_info.txt","a+");
    courses=fopen("course_info.txt","a");

    int flag=0;
    int count=0;

    if (students==NULL){
        printf("\n\nSystem has a problem.\n\n");
    }

    else{

        
        if (courses==NULL){
            printf("\n\nSystem has a problem.\n\n");
        }
        
        else{
         int i;
         
         printf("\nEnter the ID of the student:");
         scanf("%s",st.id);
         printf("\nEnter the name of the student:");
         scanf("%s",st.name);
         printf("\nEnter the surname of the student:");
         scanf("%s",st.surname);
         printf("\nEnter the email of the student:");
         scanf("%s",st.email);
         printf("\nEnter the phone number of the student:");
         scanf("%s",st.phone_num);
         printf("\nEnter the number of courses (1-4):");
         scanf("%d",&st.count_of_courses);
         
         
         while (st.count_of_courses>4 || st.count_of_courses<=0){
            printf("\nEnter the number of courses (1-4):");
            scanf("%d",&st.count_of_courses);

         }
         for(i=1;i<st.count_of_courses+1;i++){
            printf("\nEnter the course %d. code:",i);
            scanf("%s",cs[i].course_code);
            printf("\nEnter the course %d. name:",i);
            scanf("%s",cs[i].course_name);

         }

        
        
        fprintf(students,"%s %s %s %s %s %d\n",st.id,st.name,st.surname,st.email,st.phone_num,st.count_of_courses);
       
        for(i=1;i<st.count_of_courses+1;i++){
        fprintf(courses,"%s %s %s\n",st.id,cs[i].course_code,cs[i].course_name);
        } 
       
        }  
       
        }

    fclose(students);
    fclose(courses);
}



void show_all_students(){
students=fopen("student_info.txt","r");

if (students==NULL){
    printf("\n\nThe system has a problem.\n\n");

}

else{
    while(fscanf(students,"%s %s %s %s %s %d",st.id,st.name,st.surname,st.email,st.phone_num,&st.count_of_courses)!=EOF){
        printf("Student ID: %s\n",st.id);
        printf("Student name: %s\n",st.name);
        printf("Student surname: %s\n",st.surname);
        printf("Student email: %s\n",st.email);
        printf("Student phone number: %s\n",st.phone_num);
        printf("Student course no: %d\n",st.count_of_courses);
        printf("\n\n");
    }
}

fclose(students);
}

void search_student(){
    students=fopen("student_info.txt","r");
    courses=fopen("course_info.txt","r");
    
    course cou;
    char st_id[10];
    
    if(students==NULL){
        printf("\n\nThe system has a problem.\n\n");
    }
    
    else{
       
        if (courses==NULL){
            printf("\\nThe system has a problem.\n\n");
        }
        
        else{
        int flag=0;

        printf("\n\nEnter the ID: ");
        scanf("%s",st_id);

        printf("\n--------------_%s's Informations_--------------\n\n",st_id);
        
        while(fscanf(students,"%s %s %s %s %s %d",st.id,st.name,st.surname,st.email,st.phone_num,&st.count_of_courses)!=EOF){
            if(strcmp(st_id,st.id)==0){
                printf("Student ID: %s\n",st.id);
                printf("Student name: %s\n",st.name);
                printf("Student surname: %s\n",st.surname);
                printf("Student email: %s\n",st.email);
                printf("Student phone number: %s\n",st.phone_num);
                printf("Student course no: %d\n",st.count_of_courses);
                printf("\n\n");
                flag=1;
                break;
            }
        }
        
        printf("----------------_%s's Courses_-----------------\n",st_id);

        while(fscanf(courses,"%s %s %s",st.id,cou.course_code,cou.course_name)!=EOF){
            if (strcmp(st_id,st.id)==0){
                printf("\nCourse code: %s",cou.course_code);
                printf("\nCourse name: %s",cou.course_name);
                printf("\n");
            }

        }
        if (flag==0){
            printf("\n\nThe student has not found.\n\n");
        }
        }
    }
    
    fclose(students);
    fclose(courses);
}



void delete_all_students(){
    char choice;
    char student_file[30]="student_info.txt";
    char course_file[30]="course_info.txt";

    printf("\n\nAre you sure to delete the all students ? (Y/N): ");
    scanf(" %c",&choice);
   
    if (choice=='y' || choice=='Y'){
        
        if(remove(student_file)==0){
            printf("\n\nAll students have been deleted.\n\n");
            
            if(remove(course_file)==0){
            printf("\n\nAll courses have been deleted.\n\n");
            }
           
            else{
                printf("Deletetion unsuccesfull.\n\n");
            }
        }
        
        else{
            printf("\n\nDeletetion unsuccesfull.\n\n");
        }
    }
    
    else{
        printf("\n\nThe file has not deleted.\n\n");
    }


}

int delete_student(){
    students=fopen("student_info.txt","r");
    stu_temp=fopen("stu_temp.txt","w");
    course cou;
    int flag=0;
    char temp_id[30];
    printf("Enter the ID:");
    scanf("%s",temp_id);
    while(fscanf(students,"%s %s %s %s %s %d",st.id,st.name,st.surname,st.email,st.phone_num,&st.count_of_courses)!=EOF){
        if(strcmp(temp_id,st.id)==0){
            flag=1;
        }
        else{
            fprintf(stu_temp,"%s %s %s %s %s %d\n",st.id,st.name,st.surname,st.email,st.phone_num,st.count_of_courses);
        }
    }
    if (flag==0){
        printf("\n\nStudent has not found!\n\n");
    }
    else{
    courses=fopen("course_info.txt","r");
    cou_temp=fopen("cou_temp.txt","w");
    while(fscanf(courses,"%s %s %s",st.id,cou.course_code,cou.course_name)!=EOF){
        if(strcmp(temp_id,st.id)==0){
            continue;
        }
        else{
            fprintf(cou_temp,"%s %s %s\n",st.id,cou.course_code,cou.course_name);
        }
    }
    printf("\n\nThe student has been deleted.\n\n");
    fclose(courses);
    fclose(cou_temp);
    remove("course_info.txt");
    rename("cou_temp.txt","course_info.txt");
    }
    
    fclose(students);
    fclose(stu_temp);
    remove("student_info.txt");
    rename("stu_temp.txt","student_info.txt");
    return flag;

}

void edit_student(){
    int result;
    result=delete_student();
    if(result!=0){
        printf("\n\nEnter the new informations about editted student:\n\n");
        add_student();
    }

}

void quit(){
    printf("\n\n----------------------------------------------------\n\n");
    printf("Thanks for using student management system,Good Bye!");
    printf("\n\n----------------------------------------------------\n\n");
    exit(1);
}



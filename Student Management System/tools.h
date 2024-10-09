typedef struct{
char id[10];
char name[20];
char surname[20];
char email[30];
char phone_num[10];
int count_of_courses;
}student;
typedef struct{
char course_code[10];
char course_name[10];
}course;
student st;
course cs[4];
void menu();
void add_student();
void show_all_students();
void search_student();
void delete_all_students();
int delete_student();
void edit_student();
void quit();
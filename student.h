#ifndef STUDENT_H
#define STUDENT_H
struct student {
    char name[50];
    int id;
    char dept[50];
    int rollNo;
    int age;
    struct student* next;
};

struct student* add_student(struct student* head, const char* name, int id, const char* dept);
void view_students(struct student* head);
struct student* load_students_from_file();
void save_students_to_file(struct student* head);
void print_students(struct student* head);
#endif // STUDENT_H

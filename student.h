#ifndef STUDENT_H
#define STUDENT_H
struct student {
    char name[50];
    int id;
    char dept[50];
    struct student* next;
};

struct student* add_student(struct student* head, const char* name, int id, const char* dept);
void view_students(struct student* head);

#endif // STUDENT_H

// staff.h
#ifndef STAFF_H
#define STAFF_H

struct staff {
    char name[50];
    int id;
    char dept[50];
    struct staff* next;
};

struct staff* add_staff(struct staff* head, const char* name, int id, const char* dept);
void view_staff(struct staff* head);

#endif

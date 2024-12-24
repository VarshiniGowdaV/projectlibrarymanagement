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
struct staff* load_staff_from_file();
void save_staff_to_file(struct staff* head);
#endif

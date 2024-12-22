#ifndef SORTBYBOOKNAME_H
#define SORTBYBOOKNAME_H

struct sortbybookname {
    char book_name[50];
    struct sortbybookname* next;
};

struct sortbybookname* add_book_name(struct sortbybookname* head, const char* book_name);
void view_books(const struct sortbybookname* head);

#endif // SORTBYBOOKNAME_H

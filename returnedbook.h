// returnedbook.h
#ifndef RETURNEDBOOK_H
#define RETURNEDBOOK_H

struct returnedbook {
    char student_name[50];
    char usn[50];
    char dept[50];
    int date[20];
    struct returnedbook* next;
};

extern struct returnedbook* head;  // Declare head as extern

int record_returned_book();
void print_returned_books();

#endif // RETURNEDBOOK_H

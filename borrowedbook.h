#ifndef BORROWEDBOOK_H
#define BORROWEDBOOK_H
struct borrowedbook {
    char student_name[50];
    char usn[50];
    char book_name[50];
    char borrowed_date[20];
    struct borrowedbook* next;
};

extern struct borrowedbook* borrowed_books_head;
int record_borrowed_book(void);


#endif // BORROWEDBOOK_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "borrowedbook.h"

struct borrowedbook* borrowed_books_head = NULL;

int record_borrowed_book()
{
    struct borrowedbook* new_borrowed_book = (struct borrowedbook*)malloc(sizeof(struct borrowedbook));
    printf("Enter student name: ");
    scanf("%s", new_borrowed_book->student_name);

    printf("Enter student USN: ");
    scanf("%s", new_borrowed_book->usn);
    printf("Enter book name: ");
    scanf("%s", new_borrowed_book->book_name);

    printf("Enter borrowed date (YYYY-MM-DD): ");
    scanf("%s", new_borrowed_book->borrowed_date);
    new_borrowed_book->next = NULL;
    if (borrowed_books_head == NULL)
    {
        borrowed_books_head = new_borrowed_book;
    }
    else
    {
        struct borrowedbook* temp = borrowed_books_head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = new_borrowed_book;
    }

    printf("Borrowed book recorded successfully!\n");
    return 1;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sortbybookname.h"

struct sortbybookname* create_book_node(const char* book_name)
{
    struct sortbybookname* new_node = (struct sortbybookname*)malloc(sizeof(struct sortbybookname));
    if (new_node == NULL)
    {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    strncpy(new_node->book_name, book_name, sizeof(new_node->book_name) - 1);
    new_node->book_name[sizeof(new_node->book_name) - 1] = '\0';
    new_node->next = NULL;
    return new_node;
}

struct sortbybookname* add_book_name(struct sortbybookname* head, const char* book_name)
{
    struct sortbybookname* new_node = create_book_node(book_name);

    if (head == NULL)
    {
        return new_node;
    }

    struct sortbybookname* temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = new_node;
    return head;
    printf("bookname '%s' added successfully.\n");
}

void view_books(const struct sortbybookname* head)
{
    if (head == NULL)
    {
        printf("No books in the list.\n");
        return;
    }

    const struct sortbybookname* temp = head;
    while (temp != NULL)
    {
        printf("%s\n", temp->book_name);
        temp = temp->next;
    }
}


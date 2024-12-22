#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sortbyauthor.h"

struct sortbyauthor* create_author_node(const char* author_name)
{
    struct sortbyauthor* new_node = (struct sortbyauthor*)malloc(sizeof(struct sortbyauthor));
    if (!new_node)
    {
        printf("Memory allocation failed for new author node.\n");
        exit(EXIT_FAILURE);
    }
    strcpy(new_node->author_name, author_name);
    new_node->next = NULL;
    return new_node;
}

void add_author(struct sortbyauthor** head, const char* author_name)
{
    struct sortbyauthor* new_node = create_author_node(author_name);

    new_node->next = *head;
    *head = new_node;

    printf("Author '%s' added successfully.\n", author_name);
}

void view_authors(struct sortbyauthor* head)
{
    if (!head)
    {
        printf("No authors available.\n");
        return;
    }

    printf("\nList of Authors:\n");
    struct sortbyauthor* current = head;
    while (current)
    {
        printf("- %s\n", current->author_name);
        current = current->next;
    }
}

void sort_authors(struct sortbyauthor* head)
{
    if (!head)
    {
        printf("No authors available to sort.\n");
        return;
    }

    struct sortbyauthor *i, *j;
    char temp[100];

    for (i = head; i != NULL; i = i->next)
    {
        for (j = i->next; j != NULL; j = j->next)
        {
            if (strcmp(i->author_name, j->author_name) > 0)
            {
                strcpy(temp, i->author_name);
                strcpy(i->author_name, j->author_name);
                strcpy(j->author_name, temp);
            }
        }
    }

    printf("Authors sorted alphabetically.\n");
}

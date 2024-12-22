#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "staff.h"

struct staff* create_staff_node(const char* name, int id, const char* dept)
{
    struct staff* new_node = (struct staff*)malloc(sizeof(struct staff));
    if (new_node == NULL)
    {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    strncpy(new_node->name, name, sizeof(new_node->name) - 1);
    new_node->name[sizeof(new_node->name) - 1] = '\0';
    new_node->id = id;
    strncpy(new_node->dept, dept, sizeof(new_node->dept) - 1);
    new_node->dept[sizeof(new_node->dept) - 1] = '\0';
    new_node->next = NULL;
    return new_node;
}
struct staff* add_staff(struct staff* head, const char* name, int id, const char* dept)
{
    struct staff* new_node = create_staff_node(name, id, dept);

    if (head == NULL)
    {
        printf("Staff added successfully.\n");
        return new_node;
    }

    struct staff* temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = new_node;
    printf("Staff added successfully.\n");
    return head;
}
void view_staff(struct staff* head)
{
    if (head == NULL)
    {
        printf("No staff members in the list.\n");
        return;
    }

    struct staff* temp = head;
    while (temp != NULL)
    {
        printf("Name: %s, ID: %d, Department: %s\n", temp->name, temp->id, temp->dept);
        temp = temp->next;
    }
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "staff.h"
struct staff* add_staff(struct staff* head, const char* name, int id, const char* dept)
{
    struct staff* new_staff = (struct staff*)malloc(sizeof(struct staff));
    if (new_staff == NULL)
    {
        printf("Memory allocation failed.\n");
        return head;
    }

    strncpy(new_staff->name, name, sizeof(new_staff->name) - 1);
    new_staff->name[sizeof(new_staff->name) - 1] = '\0';
    new_staff->id = id;
    strncpy(new_staff->dept, dept, sizeof(new_staff->dept) - 1);
    new_staff->dept[sizeof(new_staff->dept) - 1] = '\0';
    new_staff->next = head;

    return new_staff;
}
void view_staff(struct staff* head)
{
    struct staff* current = head;

    if (current == NULL)
    {
        printf("No staff members available.\n");
        return;
    }

    printf("Staff Members:\n");
    while (current != NULL) {
        printf("Name: %s, ID: %d, Department: %s\n", current->name, current->id, current->dept);
        current = current->next;
    }
}


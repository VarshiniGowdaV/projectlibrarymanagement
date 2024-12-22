#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "student.h"

struct student* create_student_node(const char* name, int id, const char* dept)
{
    struct student* new_node = (struct student*)malloc(sizeof(struct student));
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
struct student* add_student(struct student* head, const char* name, int id, const char* dept)
{
    struct student* new_node = create_student_node(name, id, dept);

    if (head == NULL)
    {
        printf("Student added successfully.\n");
        return new_node;
    }

    struct student* temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = new_node;
    printf("Student added successfully.\n");
    return head;
}

void view_students(struct student* head)
{
    if (head == NULL)
    {
        printf("No students in the list.\n");
        return;
    }

    struct student* temp = head;
    while (temp != NULL)
    {
        printf("Name: %s, ID: %d, Department: %s\n", temp->name, temp->id, temp->dept);
        temp = temp->next;
    }
}

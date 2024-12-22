#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "filehanding.h"
#include "sortbybookname.h"
#include "student.h"
#include "staff.h"


void save_books_to_file(struct sortbybookname* head)
{
    FILE* file = fopen("books.txt", "w");
    if (!file)
    {
        perror("Failed to open books file for writing");
        return;
    }
    struct sortbybookname* current = head;
    while (current) {
        fwrite(current, sizeof(struct sortbybookname), 1, file);
        current = current->next;
    }
    fclose(file);
}

struct sortbybookname* load_books_from_file()
{
    FILE* file = fopen("books.txt", "r");
    if (!file)
    {
        perror("Failed to open books file for reading");
        return NULL;
    }
    struct sortbybookname* head = NULL;
    struct sortbybookname* current = NULL;
    struct sortbybookname temp;
    while (fread(&temp, sizeof(struct sortbybookname), 1, file))
    {
        struct sortbybookname* new_node = malloc(sizeof(struct sortbybookname));
        *new_node = temp;
        new_node->next = NULL;
        if (!head)
        {
            head = new_node;
            current = head;
        }
        else
        {
            current->next = new_node;
            current = new_node;
        }
    }
    fclose(file);
    return head;
}

void save_students_to_file(struct student* head)
{
    FILE* file = fopen("students.txt", "w");
    if (!file)
    {
        perror("Failed to open students file for writing");
        return;
    }
    struct student* current = head;
    while (current)
    {
        fwrite(current, sizeof(struct student), 1, file);
        current = current->next;
    }
    fclose(file);
}

struct student* load_students_from_file()
{
    FILE* file = fopen("students.txt", "r");
    if (!file)
    {
        perror("Failed to open students file for reading");
        return NULL;
    }
    struct student* head = NULL;
    struct student* current = NULL;
    struct student temp;
    while (fread(&temp, sizeof(struct student), 1, file))
    {
        struct student* new_node = malloc(sizeof(struct student));
        *new_node = temp;
        new_node->next = NULL;
        if (!head)
        {
            head = new_node;
            current = head;
        }
        else
        {
            current->next = new_node;
            current = new_node;
        }
    }
    fclose(file);
    return head;
}

void save_staff_to_file(struct staff* head)
{
    FILE* file = fopen("staff.txt", "w");
    if (!file)
    {
        perror("Failed to open staff file for writing");
        return;
    }
    struct staff* current = head;
    while (current)
    {
        fwrite(current, sizeof(struct staff), 1, file);
        current = current->next;
    }
    fclose(file);
}

struct staff* load_staff_from_file()
{
    FILE* file = fopen("staff.txt", "r");
    if (!file)
    {
        perror("Failed to open staff file for reading");
        return NULL;
    }
    struct staff* head = NULL;
    struct staff* current = NULL;
    struct staff temp;
    while (fread(&temp, sizeof(struct staff), 1, file))
    {
        struct staff* new_node = malloc(sizeof(struct staff));
        *new_node = temp;
        new_node->next = NULL;
        if (!head)
        {
            head = new_node;
            current = head;
        }
        else
        {
            current->next = new_node;
            current = new_node;
        }
    }
    fclose(file);
    return head;
}

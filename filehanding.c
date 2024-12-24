#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "filehanding.h"
#include "sortbybookname.h"
#include "student.h"
#include "staff.h"

void save_all_to_file(struct sortbybookname* book_head, struct student* student_head, struct staff* staff_head) {
    FILE* file = fopen("project.txt", "w");
    if (file == NULL)
    {
        perror("Failed to open file for writing");
        return;
    }
    struct sortbybookname* current_book = book_head;
    while (current_book) {
        size_t written = fwrite(current_book, sizeof(struct sortbybookname), 1, file);
        if (written != 1) {
            perror("Error writing book data to file");
            fclose(file);
            return;
        }
        current_book = current_book->next;
    }
    struct student* current_student = student_head;
    while (current_student)
    {
        size_t written = fwrite(current_student, sizeof(struct student), 1, file);
        if (written != 1)
        {
            perror("Error writing student data to file");
            fclose(file);
            return;
        }
        current_student = current_student->next;
    }
    struct staff* current_staff = staff_head;
    while (current_staff)
    {
        size_t written = fwrite(current_staff, sizeof(struct staff), 1, file);
        if (written != 1)
        {
            perror("Error writing staff data to file");
            fclose(file);
            return;
        }
        current_staff = current_staff->next;
    }

    fclose(file);
    printf("Data has been successfully saved to project.txt\n");
}



void load_all_from_file(int* books_count, int* students_count, int* staff_count) {
    FILE* file = fopen("project.txt", "r");
    if (!file)
    {
        perror("Failed to open file for reading");
        return;
    }

    struct sortbybookname* book_head = NULL;
    struct student* student_head = NULL;
    struct staff* staff_head = NULL;

    struct sortbybookname* current_book = NULL;
    struct student* current_student = NULL;
    struct staff* current_staff = NULL;

    struct sortbybookname temp_book;
    struct student temp_student;
    struct staff temp_staff;

    *books_count = 0;
    while (fread(&temp_book, sizeof(struct sortbybookname), 1, file))
    {
        struct sortbybookname* new_book = malloc(sizeof(struct sortbybookname));
        if (new_book == NULL)
        {
            perror("Failed to allocate memory for new book");
            fclose(file);
            return;
        }
        *new_book = temp_book;
        new_book->next = NULL;
        if (!book_head)
        {
            book_head = new_book;
            current_book = book_head;
        }
        else
        {
            current_book->next = new_book;
            current_book = new_book;
        }
        (*books_count)++;
    }

    *students_count = 0;
    while (fread(&temp_student, sizeof(struct student), 1, file))
    {
        struct student* new_student = malloc(sizeof(struct student));
        if (new_student == NULL)
        {
            perror("Failed to allocate memory for new student");
            fclose(file);
            return;
        }
        *new_student = temp_student;
        new_student->next = NULL;
        if (!student_head)
        {
            student_head = new_student;
            current_student = student_head;
        }
        else
        {
            current_student->next = new_student;
            current_student = new_student;
        }
        (*students_count)++;
    }

    *staff_count = 0;
    while (fread(&temp_staff, sizeof(struct staff), 1, file))
    {
        struct staff* new_staff = malloc(sizeof(struct staff));
        if (new_staff == NULL)
        {
            perror("Failed to allocate memory for new staff");
            fclose(file);
            return;
        }
        *new_staff = temp_staff;
        new_staff->next = NULL;
        if (!staff_head)
        {
            staff_head = new_staff;
            current_staff = staff_head;
        } else {
            current_staff->next = new_staff;
            current_staff = new_staff;
        }
        (*staff_count)++;
    }

    fclose(file);
}


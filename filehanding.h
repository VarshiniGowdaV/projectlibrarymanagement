#ifndef FILEHANDLING_H
#define FILEHANDLING_H

#include "sortbybookname.h"
#include "student.h"
#include "staff.h"

struct sortbybookname* load_books_from_file();
void save_books_to_file(struct sortbybookname* head);

struct student* load_students_from_file();
void save_students_to_file(struct student* head);

struct staff* load_staff_from_file();
void save_staff_to_file(struct staff* head);

#endif // FILEHANDLING_H

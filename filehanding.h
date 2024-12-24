#ifndef FILEHANDING_H
#define FILEHANDING_H

#include "sortbybookname.h"
#include "student.h"
#include "staff.h"

// Function to save all data to a file
void save_all_to_file(struct sortbybookname* book_head, struct student* student_head, struct staff* staff_head);

// Function to load all data from a file
void load_all_from_file(int* books_count, int* students_count, int* staff_count);

#endif // FILEHANDING_H

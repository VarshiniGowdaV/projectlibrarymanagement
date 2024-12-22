#include <stdio.h>
#include <string.h>
#include "admin.h"

int authenticate_admin()
{
    const char *correct_username = "admin";
    const char *correct_password = "password123";
    char entered_username[50];
    char entered_password[50];

    printf("Admin Login\n");
    printf("Enter username: ");
    scanf("%s", entered_username);
    printf("Enter password: ");
    scanf("%s", entered_password);

    if (strcmp(entered_username, correct_username) == 0 && strcmp(entered_password, correct_password) == 0) {
        printf("Login successful.\n");
        return 1;
    };
}

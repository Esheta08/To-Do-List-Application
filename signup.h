#ifndef SIGNUP_H
#define SIGNUP_H

#include <stdio.h>
#include <string.h>

int usernameExists(const char *username) {
    char u[20], p[20];
    FILE *f = fopen("users.txt", "r");
    if (!f) return 0;

    while (fscanf(f, "%s %s", u, p) != EOF) {
        if (strcmp(u, username) == 0) {
            fclose(f);
            return 1;
        }
    }
    fclose(f);
    return 0;
}

int signup(char username[20]) {
    char password[20], confirm[20];

    printf("\nSIGNUP:\n");
    printf("Enter username: ");
    scanf("%s", username);

    if (usernameExists(username)) {
        printf("Username already exists. Try a different one.\n");
        return 0;
    }

    printf("Enter password: ");
    scanf("%s", password);
    printf("Confirm password: ");
    scanf("%s", confirm);

    if (strcmp(password, confirm) != 0) {
        printf("Passwords do not match.\n");
        return 0;
    }

    FILE *f = fopen("users.txt", "a");
    if (!f) {
        printf("Could not open user file.\n");
        return 0;
    }

    fprintf(f, "%s %s\n", username, password);
    fclose(f);
    printf("Signup successful. You are now logged in as %s.\n", username);
    return 1;
}

#endif
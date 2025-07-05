#ifndef LOGIN_H
#define LOGIN_H

#include <stdio.h>
#include <string.h>

int login(char username[20]) {
    char password[20], u[20], p[20];
    FILE *f = fopen("users.txt", "r");

    if (!f) {
        printf("No user file found. Please signup first.\n");
        return 0;
    }

    printf("\nLOGIN:\n");
    printf("Enter username: ");
    scanf("%s", username);
    printf("Enter password: ");
    scanf("%s", password);

    while (fscanf(f, "%s %s", u, p) != EOF) {
        if (strcmp(u, username) == 0 && strcmp(p, password) == 0) {
            fclose(f);
            printf("Login successful.\n");
            return 1;
        }
    }

    fclose(f);
    printf("Invalid credentials.\n");
    return 0;
}

#endif

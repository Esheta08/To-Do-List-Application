#include <stdio.h>
#include "signup.h"
#include "login.h"
#include "tasks.h"
#include "fileops.h"

void taskMenu(const char *username) {
    loadTasksFromFile(username);
    int choice;

    while (1) {
        printf("\n--- Task Menu (%s) ---\n", username);
        printf("1. Add Task\n");
        printf("2. View Tasks\n");
        printf("3. Update Task\n");
        printf("4. Delete Task\n");
        printf("5. Save and Logout\n");
        printf("Choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addTask();
                break;
            case 2:
                viewTasks();
                break;
            case 3:
                updateTask();
                break;
            case 4:
                deleteTask();
                break;
            case 5:
                saveTasksToFile(username);
                printf("Logged out.\n");
                return;
            default:
                printf("Invalid option. Try again.\n");
        }
    }
}

int main() {
    int choice;
    char username[20];

    while (1) {
        printf("\n****************************\n");
        printf("       TO-DO LIST MENU      \n");
        printf("****************************\n");
        printf("1. Signup\n");
        printf("2. Login\n");
        printf("3. Exit\n");
        printf("Choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (signup(username)) {
                    taskMenu(username);
                }
                break;
            case 2:
                if (login(username)) {
                    taskMenu(username);
                }
                break;
            case 3:
                printf("Goodbye!\n");
                return 0;
            default:
                printf("Invalid choice. Try again.\n");
        }
    }
}
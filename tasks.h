#ifndef TASKS_H
#define TASKS_H

#include <stdio.h>
#include <string.h>

typedef struct {
    int id;
    char name[100];
    int priority;
    char status[20];
} Task;

#define MAX_TASKS 100

Task tasks[MAX_TASKS];
int taskCount = 0;

void addTask() {
    if (taskCount >= MAX_TASKS) {
        printf("Task list is full.\n");
        return;
    }

    Task t;
    t.id = (taskCount > 0) ? tasks[taskCount - 1].id + 1 : 1;

    printf("Enter task name: ");
    getchar();
    fgets(t.name, sizeof(t.name), stdin);
    t.name[strcspn(t.name, "\n")] = '\0';

    printf("Enter priority (1-5): ");
    scanf("%d", &t.priority);
    strcpy(t.status, "Pending");

    tasks[taskCount++] = t;
    printf("Task added successfully.\n");
}

void viewTasks() {
    if (taskCount == 0) {
        printf("No tasks to display.\n");
        return;
    }

    for (int i = 0; i < taskCount; i++) {
        printf("ID: %d | Name: %s | Priority: %d | Status: %s\n",
               tasks[i].id, tasks[i].name, tasks[i].priority, tasks[i].status);
    }
}

void updateTask() {
    int id;
    printf("Enter task ID to update: ");
    scanf("%d", &id);

    for (int i = 0; i < taskCount; i++) {
        if (tasks[i].id == id) {
            printf("Enter new name: ");
            getchar();
            fgets(tasks[i].name, sizeof(tasks[i].name), stdin);
            tasks[i].name[strcspn(tasks[i].name, "\n")] = '\0';

            printf("Enter new priority: ");
            scanf("%d", &tasks[i].priority);

            printf("Enter new status: ");
            getchar();
            fgets(tasks[i].status, sizeof(tasks[i].status), stdin);
            tasks[i].status[strcspn(tasks[i].status, "\n")] = '\0';

            printf("Task updated.\n");
            return;
        }
    }
    printf("Task not found.\n");
}

void deleteTask() {
    int id;
    printf("Enter task ID to delete: ");
    scanf("%d", &id);

    for (int i = 0; i < taskCount; i++) {
        if (tasks[i].id == id) {
            for (int j = i; j < taskCount - 1; j++) {
                tasks[j] = tasks[j + 1];
                tasks[j].id = j + 1;
            }
            taskCount--;
            printf("Task deleted.\n");
            return;
        }
    }
    printf("Task not found.\n");
}

#endif
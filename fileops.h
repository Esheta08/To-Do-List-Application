#ifndef FILEOPS_H
#define FILEOPS_H

#include <stdio.h>
#include "tasks.h"

void loadTasksFromFile(const char *username) {
    char filename[100];
    snprintf(filename, sizeof(filename), "%s_tasks.txt", username); 

    FILE *fp = fopen(filename, "r");
    if (!fp) return;

    taskCount = 0;
    while (fscanf(fp, "%d\n%[^\n]\n%d\n%[^\n]\n", 
                  &tasks[taskCount].id,
                  tasks[taskCount].name,
                  &tasks[taskCount].priority,
                  tasks[taskCount].status) == 4) {
        taskCount++;
    }
    fclose(fp);
}

void saveTasksToFile(const char *username) {
    char filename[100];
    snprintf(filename, sizeof(filename), "%s_tasks.txt", username);

    FILE *fp = fopen(filename, "w");
    if (!fp) {
        printf("Error saving tasks.\n");
        return;
    }

    for (int i = 0; i < taskCount; i++) {
        fprintf(fp, "%d\n%s\n%d\n%s\n",
                tasks[i].id, tasks[i].name,
                tasks[i].priority, tasks[i].status);
    }
    fclose(fp);
}

#endif
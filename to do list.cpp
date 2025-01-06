#include <stdio.h>
#include <string.h>
#define MAX_TASKS 100
#define MAX_LENGTH 100

// Structure to store tasks
typedef struct 
{
    int id;
    char description[MAX_LENGTH];
} 
Task;

Task tasks[MAX_TASKS];
int taskCount = 0;

// Function to add a task
void addTask() 
{
    if (taskCount >= MAX_TASKS) 
	{
        printf("\nTask list is full! Cannot add more tasks.\n");
        return;
    }

    printf("\nEnter the description of the task: ");
    getchar(); // To consume the newline character left in the input buffer
    fgets(tasks[taskCount].description, MAX_LENGTH, stdin);
    tasks[taskCount].description[strcspn(tasks[taskCount].description, "\n")] = '\0'; // Remove trailing newline

    tasks[taskCount].id = taskCount + 1; // Assign an ID to the task
    taskCount++;
    printf("Task added successfully!\n");
}

// Function to display tasks
void displayTasks() 
{
    if (taskCount == 0) 
	{
        printf("\nNo tasks to display.\n");
        return;
    }

    printf("\nYour To-Do List:\n");
    for (int i = 0; i < taskCount; i++) 
	{
        printf("%d. %s\n", tasks[i].id, tasks[i].description);
    }
}

// Function to delete a task
void deleteTask() 
{
    if (taskCount == 0) 
	{
        printf("\nNo tasks to delete.\n");
        return;
    }

    int id;
    printf("\nEnter the ID of the task to delete: ");
    scanf("%d", &id);

    int found = 0;
    for (int i = 0; i < taskCount; i++) 
	{
        if (tasks[i].id == id) 
		{
            found = 1;
            // Shift tasks
            for (int j = i; j < taskCount - 1; j++) 
			{
                tasks[j] = tasks[j + 1];
            }
            taskCount--;
            printf("Task deleted successfully!\n");
            break;
        }
    }

    if (!found) 
	{
        printf("Task with ID %d not found.\n", id);
    }
}

int main() 
{
    int choice;

    while (1) 
	{
        printf("\n--- To-Do List Menu ---\n");
        printf("1. Add Task\n");
        printf("2. Display Tasks\n");
        printf("3. Delete Task\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) 
		{
            case 1:
                addTask();
                break;
            case 2:
                displayTasks();
                break;
            case 3:
                deleteTask();
                break;
            case 4:
                printf("Exiting To-Do List... Goodbye!\n");
                return 0;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}


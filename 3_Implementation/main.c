#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include <ctype.h>
#include <stdlib.h>
#include <unistd.h>

#include "inc/main.h"

typedef enum options {
  NONE,
  ADD='A',
  MARK='M',
  DELETE='D',
  EXIT='Q'
} options_t;

int tLength = 0;

void saveToFile()
{
    fp = fopen("todos.bin", "w");
    if (!fp)
    {
        printf("Can't save your todo\n");
    }
    else
    {
        for (size_t i = 0; i < tLength; i++)
        {
            fwrite(&todos[i], sizeof(struct Todo), 1, fp);
        }
        fclose(fp);
    }
}

void getFileSize()
{
    fseek(fp, 0L, SEEK_END);
    unsigned int long size = ftell(fp);
    fseek(fp, 0L, SEEK_SET);
    tLength = size / sizeof(struct Todo);
}

void readFromFile()
{
    fp = fopen("todos.bin", "r");
    if (!fp)
    {
        printf("We are not able to find any todos file\n");
    }
    else
    {
        getFileSize();
        for (size_t i = 0; i < tLength; i++)
        {
            fread(&todos[i], sizeof(struct Todo), 1, fp);
        }
        fclose(fp);
    }
}

void ShowOptions()
{
    char userChoice;
    printf("Type 'A' to add, 'D' to delete & 'M' to mark complete or 'Q' to quit\n>>");
    userChoice = getchar();
    userChoice = toupper(userChoice);
    getchar();
    switch (userChoice)
    {
    case ADD:
        char userInput[50];
        printf("Type your todo \n>> ");
        scanf("%[^\n]s", userInput);
        addTodo(userInput);
        break;
    case DELETE:
        int todoId;
        printf("Enter the ID of todo \n>>");
        scanf("%d", &todoId);
        deleteTodo(todoId);
        break;
    case MARK:
        int todoId2;
        printf("Enter the ID of todo \n>>");
        scanf("%d", &todoId2);
        markAsComplete(todoId2);
        break;
    case EXIT:
        exit(0);
        break;
    default:
        printf("Command not found\n");
        ShowOptions();
        break;
    }
    saveToFile();
    printAllTodo();
    getchar();
    ShowOptions();
}

void isThisFirstTime()
{
    if (access("todos.bin", F_OK) != -1)
    {
        readFromFile();
        printAllTodo();
        ShowOptions();
    }
    else
    {
        printf("Welcome to the Todo App\n");
        addTodo("Default Todo");
        saveToFile();
        printAllTodo();
        ShowOptions();
    }
}

int main()
{
    system("clear||@cls");
    printf("\033[32;1m");
    isThisFirstTime();
}

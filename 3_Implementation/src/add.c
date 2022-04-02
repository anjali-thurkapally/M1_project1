#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include <add.h>

int addTodo(char userInput[])
{

    // for todo title
    // char userInput[50];
    // printf("Type your todo \n>> ");
    // scanf("%[^\n]s", userInput);
    strncpy(todos[tLength].title, userInput, 50);

    // add time
    char todoTime[50];
    struct tm cTime;
    time_t timeS = time(NULL);
    cTime = *localtime(&timeS);
    snprintf(todoTime, 50, "%i/%i %i:%i", cTime.tm_mday, cTime.tm_mon + 1, cTime.tm_hour, cTime.tm_min);
    strcpy(todos[tLength].createdAt, todoTime); 

    //set boolean to false
    todos[tLength].isCompleted = false;
    tLength++;

    return 0;
}
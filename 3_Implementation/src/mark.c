
#include <mark.h>
#include <stdbool.h>

int markAsComplete(int todoId)
{
    // int todoId;
    // printf("Enter the ID of todo \n>>");
    // scanf("%d", &todoId);
    todoId--;
    if (todoId < 0 || todoId > tLength)
    {
        printf("Invalid todo id \n");
    }
    else
    {
        todos[todoId].isCompleted = true;
        printf("Todo marked as completed \n");
    }

    return 0;
}